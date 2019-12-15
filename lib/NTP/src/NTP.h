//NTP.h
#ifndef NTP_H
    #define NTP_H
    #define SERIAL_DEBUG true

    #include <Arduino.h>
    #include <WiFiUdp.h>
    
    #define UNIX_START_YEAR 1970
    #define NTP_START_YEAR 1900
    #define SEVENTY_YEARS 2208988800UL
    #define LEAP_YEAR(Y) (  ((UNIX_START_YEAR+Y)>0) && !((UNIX_START_YEAR+Y)%4) && ( ((UNIX_START_YEAR+Y)%100) || !((UNIX_START_YEAR+Y)%400) ) )
    #define SECS_PER_MIN  (60)
    #define SECS_PER_HOUR (3600)
    #define SECS_PER_DAY  (SECS_PER_HOUR * 24)
    #define weekday(t) (((t / SECS_PER_DAY) + 4) % 7)
    

    //convenient constants for dstRules
    enum hemisphere_t {North=0, South};
    enum week_t {Last=0, First, Second, Third, Fourth}; 
    enum dow_t {Sun=0, Mon, Tue, Wed, Thu, Fri, Sat};
    enum month_t {Jan=0, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

    //structure to describe rules for when daylight/summer time begins, or when standard time begins.
    struct dstRule
    {
        uint8_t hemisphere;//0=North, 1 = South
        uint8_t week;      //First, Second, Third, Fourth, or Last week of the month
        uint8_t dow;       //day of week, 0=Sun, 1=Mon, ... 6=Sat
        uint8_t month;     //0=Jan, 1=Feb, ... 11=Dec
        uint8_t hour;      //0-23
        int offset;        //offset from Standard Time in minutes
    };   

    class NTP
    {
        private:
            uint8_t calcYear(time_t time);
	        time_t calcTime(struct dstRule * tr);
        	time_t my_mktime(struct tm *tmptr);
            uint8_t dstYear;  // Years since 1970
            struct dstRule dstStartRule;
            struct dstRule dstEndRule;
            WiFiUDP UDP;
            IPAddress timeServerIP;
            unsigned int interval = 0;
            int timezone = 0; //Timezone in minutes
            const int packetSize = 48;
            uint8_t NTPBuffer[48]; // buffer to hold incoming and outgoing packets

            unsigned long prevNTP = 0;
            unsigned long lastNTPResponse = millis();
            time_t timeUNIX = 0;
            time_t UTCtime = 0;
            time_t localTime = 0;
            struct tm * timeinfo;

            time_t prevUTCtime = 0;

            void startUDP();
            void sendNTPpacket(IPAddress& address);
            time_t getTime();

        public:
            NTP();
            NTP(const char *host, const int checkInterval, const int tzone, 
                uint8_t stdWeek, uint8_t stdDay, uint8_t stdMonth, uint8_t stdHour, int16_t stdOffset,
                uint8_t dstWeek, uint8_t dstDay, uint8_t dstMonth, uint8_t dstHour, int16_t dstOffset);
            void init(const char *host, const int checkInterval, const int tzone, 
                uint8_t stdWeek, uint8_t stdDay, uint8_t stdMonth, uint8_t stdHour, int16_t stdOffset,
                uint8_t dstWeek, uint8_t dstDay, uint8_t dstMonth, uint8_t dstHour, int16_t dstOffset);
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

