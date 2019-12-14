//NTP.h
#ifndef NTP_H
    #define NTP_H
    #define SERIAL_DEBUG true

    #include <Arduino.h>
    #include <WiFiUdp.h>

    typedef union {
        uint16_t data;
        struct {
            uint16_t hemis : 1;                    // bit 0        = 0=Northern, 1=Southern Hemisphere (=Opposite DST/STD)
            uint16_t week : 3;                     // bits 1 - 3   = 0=Last week of the month, 1=First, 2=Second, 3=Third, 4=Fourth
            uint16_t month : 4;                    // bits 4 - 7   = 1=Jan, 2=Feb, ... 12=Dec
            uint16_t dow : 3;                      // bits 8 - 10  = day of week, 1=Sun, 2=Mon, ... 7=Sat
            uint16_t hour : 5;                     // bits 11 - 15 = 0-23             
        };
    } TimeRule;

    class NTP
    {
        WiFiUDP UDP;
        IPAddress timeServerIP;
        unsigned int interval = 0;
        int timezone = 0;
        const int packetSize = 48;
        uint8_t NTPBuffer[48]; // buffer to hold incoming and outgoing packets

        unsigned long prevNTP = 0;
        unsigned long lastNTPResponse = millis();
        time_t timeUNIX = 0;
        time_t UTCtime = 0;
        struct tm * timeinfo;

        time_t prevUTCtime = 0;
        
        void startUDP();
        void sendNTPpacket(IPAddress& address);
        time_t getTime();

        TimeRule dstInfo[2];
        int16_t dstOffset[2];

        public:
            NTP();
            NTP(const char *host, const int checkInterval, const int tzone, 
                const int stdHemisphere, const int stdWeek, const int stdDay, const int stdMonth, const int stdHour, int16_t stdOffset,
                const int dstHemisphere, const int dstWeek, const int dstDay, const int dstMonth, const int dstHour, int16_t dstOffset);
            void init(const char *host, const int checkInterval, const int tzone, 
                const int stdHemisphere, const int stdWeek, const int stdDay, const int stdMonth, const int stdHour, int16_t stdOffset,
                const int dstHemisphere, const int dstWeek, const int dstDay, const int dstMonth, const int dstHour, int16_t dstOffset);
            void CheckTime();
            int getSeconds();
            int getMinutes();
            int getHours();
            int getDay();
            int getDow();
            int getMonth();
            int getYear();
            int getWeek();
            int getTimeZone();
            int getDST();
    };   

#endif

