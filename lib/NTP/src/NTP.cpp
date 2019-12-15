//NTP.cpp
#include <NTP.h>
#include <ESP8266WiFi.h>

NTP::NTP()
{}

NTP::NTP(const char *host, const int checkInterval, const int tzone, 
                uint8_t stdWeek, uint8_t stdDay, uint8_t stdMonth, uint8_t stdHour, int16_t stdOffset,
                uint8_t dstWeek, uint8_t dstDay, uint8_t dstMonth, uint8_t dstHour, int16_t dstOffset)
{
   init(host, checkInterval, tzone, 
                stdWeek, stdDay, stdMonth, stdHour, stdOffset,
                dstWeek, dstDay, dstMonth, dstHour, dstOffset);
}

void NTP::init(const char *host, const int checkInterval, const int tzone, 
                uint8_t stdWeek, uint8_t stdDay, uint8_t stdMonth, uint8_t stdHour, int16_t stdOffset,
                uint8_t dstWeek, uint8_t dstDay, uint8_t dstMonth, uint8_t dstHour, int16_t dstOffset)
{
    timezone = tzone;

    dstStartRule.week = dstWeek;
    dstStartRule.dow = dstDay;
    dstStartRule.month = dstMonth;
    dstStartRule.hour = dstHour;
    dstStartRule.offset = dstOffset;
    
    dstEndRule.week = stdWeek;
    dstEndRule.dow = stdDay;
    dstEndRule.month = stdMonth;
    dstEndRule.hour = stdHour;
    dstEndRule.offset = stdOffset;
    
    interval = checkInterval;
    startUDP();

    if(!WiFi.hostByName(host, timeServerIP)) { // Get the IP address of the NTP server
        #if SERIAL_DEBUG
            Serial.println("DNS lookup failed. Rebooting.");
            Serial.flush();
        #endif
        ESP.reset();
    }
    #if SERIAL_DEBUG
        Serial.print("Time server IP:\t");
        Serial.println(timeServerIP);
        Serial.println("\r\nSending NTP request ...");
    #endif
    sendNTPpacket(timeServerIP);  
}

void NTP::CheckTime()
{
    unsigned long currentMillis = millis();

    if (currentMillis - prevNTP > interval) { // If check time interval has passed since last NTP request
        prevNTP = currentMillis;
        #if SERIAL_DEBUG
            Serial.println("\r\nSending NTP request ...");
        #endif
        sendNTPpacket(timeServerIP);               // Send an NTP request
    }

    uint32_t time = getTime();                   // Check if an NTP response has arrived and get the (UNIX) time
    if (time) {                                  // If a new timestamp has been received
        timeUNIX = time;
        #if SERIAL_DEBUG
          Serial.print("NTP response:\t");
            Serial.println(timeUNIX);
        #endif
        lastNTPResponse = currentMillis;
    } 
    else if ((currentMillis - lastNTPResponse) > SECS_PER_HOUR * 1000) {
        #if SERIAL_DEBUG
            Serial.println("More than 1 hour since last NTP response. Rebooting.");
            Serial.flush();
        #endif
        ESP.reset();
    }

    UTCtime = timeUNIX + (currentMillis - lastNTPResponse)/1000;
    if (UTCtime != prevUTCtime && timeUNIX != 0) { // If a second has passed since last print
        prevUTCtime = UTCtime;  
    }
    localTime = UTCtime + timezone*60 + getDST()*60;
    //Serial.println(ctime(&localTime));
    timeinfo = localtime (&localTime);    
}

void NTP::startUDP() 
{
    #if SERIAL_DEBUG
        Serial.println("Starting UDP");
    #endif
    UDP.begin(123);                          // Start listening for UDP messages on port 123
    #if SERIAL_DEBUG
        Serial.print("Local port:\t");
        Serial.println(UDP.localPort());
        Serial.println();
    #endif
}

void NTP::sendNTPpacket(IPAddress& address) {
    memset(NTPBuffer, 0, packetSize);  // set all bytes in the buffer to 0
    // Initialize values needed to form NTP request
    NTPBuffer[0] = 0b11100011;   // LI, Version, Mode
    // send a packet requesting a timestamp:
    if(UDP.beginPacket(address, 123)==1) // NTP requests are to port 123
    {
        #if SERIAL_DEBUG
            Serial.println("Starting assembly of NTP packet.");
        #endif
    }
    else
    {
         #if SERIAL_DEBUG
            Serial.println("There was a problem with the NTP IP address or port.");
        #endif
    }
    UDP.write(NTPBuffer, packetSize);
    if(UDP.endPacket() == 1)
    {
        #if SERIAL_DEBUG
            Serial.println("NTP packent sent.");
        #endif
    }
    else
    {
         #if SERIAL_DEBUG
            Serial.println("There was an error sending the NTP packet.");
        #endif
    }

}

time_t NTP::getTime() {
    if (UDP.parsePacket() == 0) { // If there's no response (yet)
        return 0;
    }
    UDP.read(NTPBuffer, packetSize); // read the packet into the buffer
    // Combine the 4 timestamp bytes into one 32-bit number
    uint32_t NTPTime = (NTPBuffer[40] << 24) | (NTPBuffer[41] << 16) | (NTPBuffer[42] << 8) | NTPBuffer[43];
    // Convert NTP time to a UNIX timestamp:    
    // subtract seventy years:
    uint32_t UNIXTime = NTPTime - SEVENTY_YEARS;
    return UNIXTime;
}

int NTP::getSeconds() {
    return timeinfo->tm_sec;
}

int NTP::getMinutes() {
    return timeinfo->tm_min;
}

int NTP::getHours() {
    return timeinfo->tm_hour;    
}

int NTP::getDay() {
    return timeinfo->tm_mday;
}

int NTP::getDow(){
    return timeinfo->tm_wday + 1;
}

int NTP::getMonth() {
    return timeinfo->tm_mon + 1;
}

int NTP::getYear() {
    return timeinfo->tm_year + NTP_START_YEAR;
}

//Returns timezone difference to UTC in minutes
int NTP::getTimeZone(){
    return timezone;
}

//Returns DST offset in minutes
int NTP::getDST(){
    time_t now = UTCtime;
    uint8_t year = calcYear(now);
    static time_t dstStart;  // Start of DST in specific Year (seconds since 1970)
    static time_t dstEnd;    // End of DST in listed Year (seconds since 1970)
 
    // Init DST variables if necessary
    if(dstYear!=year)
    {
        dstYear=year;
        dstStart = calcTime(&dstStartRule);
        dstEnd = calcTime(&dstEndRule);
    
        Serial.println("\nDST Rules Updated:");
        Serial.print("DST Start: ");
        Serial.print(ctime(&dstStart));
        Serial.print("DST End:   ");
        Serial.println(ctime(&dstEnd));
    }

    bool northTZ = (dstEnd>dstStart)?1:0; // Northern or Southern hemisphere TZ?
    
    if((northTZ && (now >= dstStart && now < dstEnd)) || (!northTZ && (now < dstEnd || now >= dstStart)))
    {
        return dstStartRule.offset;            	
    }
    else
    {
        return dstEndRule.offset;
    }
    
    return(0);
}

uint8_t NTP::calcYear(time_t time)
{
    uint8_t year=0;
    long days=0;
    
    time /= SECS_PER_DAY; // now it is days

    while((days += (LEAP_YEAR(year) ? 366 : 365)) <= time) {
        //Serial.printf("%s %i, days %i\n\r", LEAP_YEAR(year)?"Leap year":"Year", year+UNIX_START_YEAR, days);
        year++;
    }
    
    return(year);
}

/*----------------------------------------------------------------------*
 * Convert the given DST change rule to a time_t value                  *
 * for the given year.                                                  *
 * Based on code from Arduino Timezone Library by Jack Christensen      *
 *----------------------------------------------------------------------*/
time_t NTP::calcTime(struct dstRule * tr)
{
    struct tm tm2;
    time_t t;
    uint8_t m, w;            //temp copies
 
    m = tr->month;
    w = tr->week;
    if (w == 0) {            //Last week = 0
        if (++m > 11) {      //for "Last", go to the next month
            m = 0;
            // yr++;
        }
        w = 1;               //and treat as first week of next month, subtract 7 days later
    }

    tm2.tm_hour = tr->hour;
    tm2.tm_min = 0;
    tm2.tm_sec = 0;
    tm2.tm_mday = 1;
    tm2.tm_mon = m;
    tm2.tm_year = dstYear;
  
    t = mktime(&tm2);        
    //mktime works with NTP timestamps rather than UNIX one, so we have to add 70 years:    
    t += SEVENTY_YEARS;
    
    //first day of the month, or first day of next month for "Last" rules
    t += (7 * (w - 1) + (tr->dow - weekday(t) + 7) % 7) * SECS_PER_DAY;
    if (tr->week == 0) t -= 7 * SECS_PER_DAY;    //back up a week if this is a "Last" rule
    
    return t;
}