#include "DTC_Codes.h"
#include "FuelLevelSensor.h"
#include "BMP180Sensor.h"

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Initialize sensors
    setupFuelLevelSensor();
    setupBMP180();
}

void loop() {
    // Check water level sensor
    checkFuelLevel();

    // Check BMP180 sensor
    checkBMP180();

    // Add a delay between checks
    delay(1000);
}

