#ifndef __MQTT_H__
#define __MQTT_H__

#include <Losant.h>
#include "wifi/wifi.h"

class Mqtt {
private:
  // Losant credentials.
  const char* LOSANT_DEVICE_ID = "578fd505fc8a5001007a9950";
  const char* LOSANT_ACCESS_KEY = "5705c3f5-385e-4a68-81ad-37bdfa283241";
  const char* LOSANT_ACCESS_SECRET = "7ecbe4ec0cb812faa60f892aae58b0241a58410c5450ab00a65ce0136b924a79";

  LosantDevice* _device;

public:
  Mqtt();
  bool isConnected();
  void loop(Wifi);
  void connect(Wifi);
  void send(JsonObject&);
};

#endif
