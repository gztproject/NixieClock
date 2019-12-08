#include <Arduino.h>
#include <config.h>
#include <OTA.h>
#include <myWiFi.h>
#include <NTP.h>
#include <NixieClock.h>
 
NTP ntp;
NixieClock nixie(NUM_CHIPS, DATA_PIN, CLOCK_PIN, LATCH_PIN);

void setup() { 
    Serial.println("****************** Entered setup: ***********************");
    Serial.println();
    Serial.begin(115200);
    OTA(HOST_NAME, OTA_KEY);
    myWiFi(WIFI_SSID, WIFI_PASSWORD);    
    ntp.init(TIME_HOST, INTERVAL_NTP, TIMEZONE);
    Serial.println("****************** Ended setup: ***********************");
    Serial.println();
}

void loop() {
    Serial.println("****************** Entered main loop: ***********************");
    Serial.println();
    
    ntp.CheckTime();
}