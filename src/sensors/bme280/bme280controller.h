#ifndef __BME280CONTROLLER_H__
#define __BME280CONTROLLER_H__

#define BME280_CHIPID 0x60

class Bme280controller
{
private:
  bool sensorAvailable;

public:
  Bme280controller();

  // Returns true if bme280 is available to be used
  bool isAvailable(void);

  // Initialize the sensor
  void begin(void);

  // Tell to the sensor to start measuring and wait until is done. The sensor will going to sleep mode just before returning of this method.
  void measure(void);

  double getTemperature(void);
  double getPressure(void);
  double getHumidity(void);
};

#endif
