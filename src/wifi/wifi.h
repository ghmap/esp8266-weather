#ifndef __WIFI_H__
#define __WIFI_H__

#include "config/config.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

class Wifi
{
private:
  const char* _ssid = WIFI_SSID;
  const char* _pass = WIFI_PASS;


public:
  WiFiClientSecure _wifiClient;
  typedef wl_status_t Status;

  Wifi();
  Status getStatus();
  bool isConnected();
  void connect();
  IPAddress getLocalIP();
  WiFiClientSecure getWifiClient();
  void loop();
};

#endif
