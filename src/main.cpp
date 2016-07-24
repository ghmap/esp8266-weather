#include <Arduino.h>
#include <Wire.h>
#include "config/config.h"
#include "sensors/bme280/bme280controller.h"
#include "wifi/wifi.h"
#include "mqtt/mqtt.h"

#define DEBUG
#define SERIAL_BAUDRATE 115200

// Sensor controllers
Bme280controller bme280;

// Other controllers
Wifi wifi;
Mqtt mqtt;

void initSerial() {
  Serial.begin(SERIAL_BAUDRATE);
}

void initI2C() {
  Wire.begin();
}

void initSensors() {
  if (bme280.isAvailable()) {
    bme280.begin();
    Serial.println(F("BME280 is ready!"));
  } else {
    Serial.println(F("BME280 communication error"));
  }
}

void setup() {

  Serial.println(F("BME280 wifi project"));

  initI2C();
  initSensors();
}

void loop() {

  wifi.loop();
  mqtt.loop(wifi);

  bme280.measure();
  Serial.print("Temperature = ");
  Serial.println(bme280.getTemperature());  // use double calculations
  Serial.print("Humidity = ");
  Serial.println(bme280.getHumidity()); // use double calculations
  Serial.print("Pressure = ");
  Serial.println(bme280.getPressure()); // use double calculations

  delay(2000);
}
