#include <Arduino.h>
#include <config.h>
#include <OTA.h>
#include <myWiFi.h>
#include <NTP.h>
#include <NixieClock.h>

NTP ntp;
NixieClock nixie(DATA_PIN, CLOCK_PIN, LATCH_PIN);
uint8_t ip[4];

void setup()
{
    Serial.println("****************** Entered setup: ***********************");
    Serial.println();
    Serial.begin(115200);
    OTA(HOST_NAME, OTA_KEY);
    myWiFi wifi(WIFI_SSID, WIFI_PASSWORD);
    wifi.getIp(ip);
    ntp.init(TIME_HOST, INTERVAL_NTP, TIMEZONE,
             TIME_STD_WEEK, TIME_STD_DAY, TIME_STD_MONTH, TIME_STD_HOUR, TIME_STD_OFFSET,
             TIME_DST_WEEK, TIME_DST_DAY, TIME_DST_MONTH, TIME_DST_HOUR, TIME_DST_OFFSET);
    Serial.println("****************** Ended setup: ***********************");
#if SHOW_IP_ON_STARTUP
    nixie.showIpFlashy(ip, 4, STRAT_IP_DISPLAY_TIME*250);       
#endif
    Serial.println();
}

void loop()
{
    //Serial.println("****************** Entered main loop: ***********************");
    //Serial.println();

    ntp.CheckTime();

#if CYCLE_LAMPS
    if ((ntp.getSeconds() >= CYCLE_START_SECOND) && (ntp.getSeconds() < CYCLE_START_SECOND + CYCLE_TIME))
        nixie.cycleTubes();
#endif

#if SHOW_IP
#if ONLY_SHOW_LAST_TWO_OCTETS
    if ((ntp.getSeconds() >= IP_START_SECOND) && (ntp.getSeconds() < IP_START_SECOND + IP_DISPLAY_TIME))
    {
        nixie.showIpFlashy(ip, 2, IP_DISPLAY_TIME*500); 
    }    
#else
    if ((ntp.getSeconds() >= IP_START_SECOND) && (ntp.getSeconds() < IP_START_SECOND + IP_DISPLAY_TIME))
    {
        nixie.showIpFlashy(ip, 4, IP_DISPLAY_TIME*250); 
    }
#endif
#endif

#if SHOW_DATE
#if CYCLE_LAMPS || SHOW_IP
    else
#endif
        if ((ntp.getSeconds() >= DATE_START_SECOND) && (ntp.getSeconds() < DATE_START_SECOND + DATE_DISPLAY_TIME))
        nixie.showDate(ntp.getDay(), ntp.getMonth(), ntp.getYear());
#endif
#if SHOW_TEMP
#if CYCLE_LAMPS || SHOW_IP || SHOW_DATE
    else
#endif
        if ((ntp.getSeconds() >= TEMP_START_SECOND) && (ntp.getSeconds() < TEMP_START_SECOND + TEMP_DISPLAY_TIME))
        nixie.showTempHum(20, 100);
#endif
#if SHOW_TEMP || SHOW_DATE || SHOW_IP || CYCLE_LAMPS
    else
#endif
        nixie.showTime(ntp.getHours(), ntp.getMinutes(), ntp.getSeconds());
}