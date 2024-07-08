#ifndef FUEL_LEVEL_SENSOR_H
#define FUEL_LEVEL_SENSOR_H

extern const int FUEL_LEVEL_SENSOR_PIN; // Declare external variable for the fuel level sensor pin
extern int fuelLevel; // Variable to store the fuel level sensor value

// Threshold values
const int FUEL_LEVEL_LOW_THRESHOLD = 200; // Low fuel level threshold (analog value)
const int FUEL_LEVEL_HIGH_THRESHOLD = 800; // High fuel level threshold (analog value)

void setupFuelLevelSensor();
void checkFuelLevel();

#endif // FUEL_LEVEL_SENSOR_H

