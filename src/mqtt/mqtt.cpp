#include "mqtt/mqtt.h"

Mqtt::Mqtt() {

  _device = new LosantDevice(LOSANT_DEVICE_ID);
}

bool Mqtt::isConnected() {

  return _device->connected();
}

void Mqtt::loop(Wifi wifi) {

  if (!isConnected()) {

    connect(wifi);
  }
  _device->loop();
}


void Mqtt::connect(Wifi wifi) {

  #ifdef DEBUG
  Serial.println("Connecting to Losant");
  #endif

  _device->connectSecure(wifi._wifiClient, LOSANT_ACCESS_KEY, LOSANT_ACCESS_SECRET);

  while(!isConnected()) {

    delay(50);

    #ifdef DEBUG
    Serial.print(".");
    #endif
  }

  #ifdef DEBUG
  Serial.println("Connected :)");
  #endif
}

void Mqtt::send(JsonObject& json) {

  _device->sendState(json);
}
