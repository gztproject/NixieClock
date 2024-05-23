//myWiFi.cpp
#include <myWiFi.h>


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
    #ifdef WIFI_DEBUG
    WiFi.printDiag(Serial);
    #endif

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();

}

void myWiFi::getIp(uint8_t *res)
{
    IPAddress ip = WiFi.localIP();
    res[0] = ip.operator[](0);
    res[1] = ip.operator[](1);
    res[2] = ip.operator[](2);
    res[3] = ip.operator[](3);
}