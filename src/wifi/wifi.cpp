#include "wifi.h"
#include <Arduino.h>

Wifi::Wifi() {

}

void Wifi::connect() {

  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(_ssid, _pass);
    //WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);

    #ifdef DEBUG
    Serial.println();
    Serial.print("Wait for WiFi... ");
    #endif

    while (getStatus() != Status::WL_CONNECTED) {
        #ifdef DEBUG
        Serial.print(".");
        #endif

        delay(50);
    }

    #ifdef DEBUG
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(getLocalIP());
    Serial.println("");
    #endif
  }
}

Wifi::Status Wifi::getStatus() {

  return WiFi.status();
}

IPAddress Wifi::getLocalIP() {

  return WiFi.localIP();
}

bool Wifi::isConnected() {

  return getStatus() == Status::WL_CONNECTED;
}

WiFiClientSecure Wifi::getWifiClient() {

  return _wifiClient;
}

void Wifi::loop() {

  if (!isConnected()) {

    connect();
  }
}
