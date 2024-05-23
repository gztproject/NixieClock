#ifndef myWiFi_H
#define myWiFi_H    

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "config.h"

    class myWiFi
    {
        public:
            myWiFi(const char *ssid, const char *password);
            void getIp(uint8_t *res);
    };

#endif

