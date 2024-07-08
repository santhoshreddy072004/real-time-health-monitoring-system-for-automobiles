#ifndef BMP180_SENSOR_H
#define BMP180_SENSOR_H

#include <Wire.h>
#include <SFE_BMP180.h>
#include "DTC_Codes.h"

// Create an SFE_BMP180 object
extern SFE_BMP180 pressure;

// Threshold values
const float NORMAL_PRESSURE_LOW = 28.0; // Low pressure threshold in psi
const float NORMAL_PRESSURE_HIGH = 35.0; // High pressure threshold in psi
const float NORMAL_TEMP_LOW = 0.0; // Low temperature threshold in degrees Celsius
const float NORMAL_TEMP_HIGH = 80.0; // High temperature threshold in degrees Celsius

void setupBMP180();
void checkBMP180();

#endif // BMP180_SENSOR_H

