//OTA.cpp
#include <ArduinoOTA.h>
#include <OTA.h>

OTA::OTA(const char *host, const char *otaPassHash)
{
    ArduinoOTA.setHostname(host);
    ArduinoOTA.setPasswordHash(otaPassHash);
  
    ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
        else // U_SPIFFS
        type = "filesystem";

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    });
    ArduinoOTA.onEnd([]() {
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    });
    ArduinoOTA.onError([](ota_error_t error) {    
        ESP.restart();
    });
    ArduinoOTA.begin();
}