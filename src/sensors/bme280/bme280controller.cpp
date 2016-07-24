#include "bme280controller.h"
#include <Arduino.h>
#include "Wire.h"
#include <BME280_MOD-1022.h>


Bme280controller::Bme280controller() {

}

bool Bme280controller::isAvailable(void) {

  sensorAvailable = BME280.readChipId() == BME280_CHIPID;
  return sensorAvailable;
}

void Bme280controller::begin(void) {

  if (!sensorAvailable) return;

  BME280.readCompensationParams();
  BME280.writeOversamplingPressure(os16x);  // 1x over sampling (ie, just one sample)
  BME280.writeOversamplingTemperature(os16x);
  BME280.writeOversamplingHumidity(os16x);
}

void Bme280controller::measure(void) {

  if (!sensorAvailable) return;

  BME280.writeMode(smForced);
  while (BME280.isMeasuring()) {
      delay(10);
  }

  BME280.readMeasurements();
}

double Bme280controller::getTemperature(void) {

  if (!sensorAvailable) return 0;
  return BME280.getTemperatureMostAccurate();
}

double Bme280controller::getPressure(void) {

  if (!sensorAvailable) return 0;
  return BME280.getPressureMostAccurate();
}

double Bme280controller::getHumidity(void) {

  if (!sensorAvailable) return 0;
  return BME280.getHumidityMostAccurate();
}
