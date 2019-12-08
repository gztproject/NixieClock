#define SERIAL_DEBUG true
#define OTA_KEY "21232f297a57a5a743894a0e4a801fc3" // ->'admin'


/************************************************************/
/*****                     WiFi                        ******/
/************************************************************/
//#define IP            {10,10,2,1}
//#define GATEWAY       {10,10,0,1}
//#define NETWORK_MASK  {255,255,0,0}

#define WIFI_SSID       "SSID"
#define WIFI_PASSWORD   "PASSWD"
#define HOST_NAME       "NixieClock"

/************************************************************/
/*****                     PINS                        ******/
/************************************************************/
#define NUM_CHIPS 4

#define LATCH_PIN D2
#define CLOCK_PIN D1
#define DATA_PIN D0

#define BME_CS D8
#define BME_MOSI D7
#define BME_MISO D6
#define BME_SCK D5

/************************************************************/
/*****                 Clock options                   ******/
/************************************************************/

#define TIMEZONE 1
#define TIME_HOST "pool.ntp.org"
#define INTERVAL_NTP 20*60*1000
#define USE_DST true
#define SHOW_DATE true 
#define DATE_START_SECOND 40
#define DATE_DISPLAY_TIME 10
#define SHOW_TEMP false 
#define TEMP_START_SECOND DATE_START_SECOND + DATE_DISPLAY_TIME
#define TEMP_DISPLAY_TIME 10
