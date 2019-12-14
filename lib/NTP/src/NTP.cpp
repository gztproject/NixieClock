//NTP.cpp
#include <NTP.h>
#include <ESP8266WiFi.h>

NTP::NTP()
{}

NTP::NTP(const char *host, const int checkInterval, const int tzone, 
                const int stdHemisphere, const int stdWeek, const int stdDay, const int stdMonth, const int stdHour, int16_t stdOffset,
                const int dstHemisphere, const int dstWeek, const int dstDay, const int dstMonth, const int dstHour, int16_t dstOffset)
{
   init(host, checkInterval, tzone, 
                stdHemisphere, stdWeek, stdDay, stdMonth, stdHour, stdOffset,
                dstHemisphere, dstWeek, dstDay, dstMonth, dstHour, dstOffset);
}

void NTP::init(const char *host, const int checkInterval, const int tzone, 
                const int stdHemisphere, const int stdWeek, const int stdDay, const int stdMonth, const int stdHour, int16_t stdOffset,
                const int dstHemisphere, const int dstWeek, const int dstDay, const int dstMonth, const int dstHour, int16_t dstOffsetArg)
{
    timezone = tzone;
    dstInfo[0].hemis = stdHemisphere;
    dstInfo[0].week = stdWeek;
    dstInfo[0].dow = stdDay;
    dstInfo[0].month = stdMonth;
    dstInfo[0].hour = stdHour;
    dstOffset[0] = stdOffset;

    dstInfo[1].hemis = dstHemisphere;
    dstInfo[1].week = dstWeek;
    dstInfo[1].dow = dstDay;
    dstInfo[1].month = dstMonth;
    dstInfo[1].hour = dstHour;
    dstOffset[1] = dstOffsetArg;
    
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
    else if ((currentMillis - lastNTPResponse) > 3600000) {
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
    timeinfo = localtime (&UTCtime + (timezone + getDST()) * 60);
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
    // Unix time starts on Jan 1 1970. That's 2208988800 seconds in NTP time:
    const uint32_t seventyYears = 2208988800UL;
    // subtract seventy years:
    uint32_t UNIXTime = NTPTime - seventyYears;
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
    return timeinfo->tm_year + 1900;
}

int NTP::getWeek(){
    return floor(timeinfo->tm_yday / 7);
}

//Returns timezone difference to UTC in minutes
int NTP::getTimeZone(){
    return timezone;
}

//Returns DST offset in minutes
int NTP::getDST(){
    //Checking the month
    if(getMonth() >= dstInfo[1].month && getMonth() <= dstInfo[0].month)
        //Checking week
        if(true)
            //Checking DOW
            if(getDow() >= dstInfo[1].dow && getDow() <= dstInfo[0].dow)
                //checking hour
                if(((UTCtime + (timezone + dstOffset[0]) * 60) / 3600 % 24) >= dstInfo[1].hour && ((UTCtime + (timezone + dstOffset[1]) * 60) / 3600 % 24) <= dstInfo[0].hour)
                    return dstOffset[1];
    else
        return dstOffset[0];    
    
    return 0;
}
