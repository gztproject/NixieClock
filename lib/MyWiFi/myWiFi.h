//myWiFi.h
#include <Arduino.h>
#ifndef myWiFi_H
    #define myWiFi_H    

    class myWiFi
    {
        public:
            myWiFi(const char *ssid, const char *password);
            void getIp(uint8_t *res);
    };

#endif

