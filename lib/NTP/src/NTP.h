//NTP.h
#ifndef NTP_H
    #define NTP_H
    #define SERIAL_DEBUG true

    #include <Arduino.h>
    #include <WiFiUdp.h>

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
        time_t actualTime = 0;
        struct tm * timeinfo;

        unsigned long prevActualTime = 0;
        
        void startUDP();
        void sendNTPpacket(IPAddress& address);
        time_t getTime();
        
        
        public:
            NTP();
            NTP(const char *host, const int checkInterval, const int tzone);
            void init(const char *host, const int checkInterval, const int tzone);
            void CheckTime();
            int getSeconds();
            int getMinutes();
            int getHours();
            int getDay();
            int getMonth();
            int getYear();
    };

#endif

