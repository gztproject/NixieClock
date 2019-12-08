//NTP.cpp
#include <NTP.h>
#include <ESP8266WiFi.h>

NTP::NTP()
{}

NTP::NTP(const char *host, const int checkInterval, const int tzone)
{
   init(host, checkInterval, tzone);
}

void NTP::init(const char *host, const int checkInterval, const int tzone)
{
    timezone = tzone;
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

    actualTime = timeUNIX + (currentMillis - lastNTPResponse)/1000;
    if (actualTime != prevActualTime && timeUNIX != 0) { // If a second has passed since last print
        prevActualTime = actualTime;  
    } 
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

uint32_t NTP::getTime() {
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
    return actualTime % 60;
}

int NTP::getMinutes() {
    return actualTime / 60 % 60;
}

int NTP::getHours() {
    int h = (actualTime / 3600 % 24)+timezone;
    if(h==24) h = 0;
    return h;
}
