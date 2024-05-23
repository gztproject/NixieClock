#ifndef CONFIG_OVERRIDE_H
#define CONFIG_OVERRIDE_H

#define SERIAL_DEBUG false
#define OTA_KEY "21232f297a57a5a743894a0e4a801fc3" // ->'admin'


/************************************************************/
/*****                     WiFi                        ******/
/************************************************************/

#define WIFI_SSID       "SSID"
#define WIFI_PASSWORD   "PASSWD"
#define HOST_NAME       "NixieClock"


/************************************************************/
/*****                 Clock options                   ******/
/************************************************************/

#define TIMEZONE 1*60
#define TIME_HOST "pool.ntp.org"
#define INTERVAL_NTP 20*60*1000
#define USE_DST true

#define SHOW_DATE true 
#if SHOW_DATE
  #define DATE_START_SECOND 40
  #define DATE_DISPLAY_TIME 10
#endif

#define SHOW_TEMP false //Not yet implemented really...
#if SHOW_TEMP
  #define TEMP_START_SECOND 50
  #define TEMP_DISPLAY_TIME 10
#endif

#define CYCLE_LAMPS true
#if CYCLE_LAMPS
  #define CYCLE_START_SECOND 0
  #define CYCLE_TIME 1
#endif

#define SHOW_IP_ON_STARTUP true

#define SHOW_IP false
#if SHOW_IP
  #define ONLY_SHOW_LAST_TWO_OCTETS true
  #define IP_START_SECOND 1
  #define IP_DISPLAY_TIME 2
#endif
#endif
