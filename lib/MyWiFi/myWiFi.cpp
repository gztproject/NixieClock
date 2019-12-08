//myWiFi.cpp
#include <myWiFi.h>
#include <ESP8266WiFi.h>

myWiFi::myWiFi(const char *ssid, const char *password)
{
    Serial.println(); Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    delay(2000);

    Serial.println("");

    /* Wait for WiFi connection */
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    /* Show some important information on Serial Monitor */
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}