#include "FuelLevelSensor.h"
#include "DTC_Codes.h"
#include <Arduino.h> // Include Arduino framework

// Define the fuel level sensor pin
const int FUEL_LEVEL_SENSOR_PIN = A0;

// Initialize the fuel level variable
int fuelLevel = 0;

// Initialize the fuel level sensor
void setupFuelLevelSensor() {
    // Setup code for fuel level sensor, if any
}

// Forward declaration
void checkFuelLevelRange(int fuelLevel);

// Check fuel level sensor readings
void checkFuelLevel() {
    fuelLevel = analogRead(FUEL_LEVEL_SENSOR_PIN);
    Serial.print("Fuel Level: ");
    Serial.println(fuelLevel);

    checkFuelLevelRange(fuelLevel);
}

// Check if the fuel level is within the normal range
void checkFuelLevelRange(int fuelLevel) {
    if (fuelLevel < FUEL_LEVEL_LOW_THRESHOLD) {
        Serial.println("DTC Code: P3103"); // DTC_FLS_CIRCUIT_VOLTAGE_LOW
    } else if (fuelLevel > FUEL_LEVEL_HIGH_THRESHOLD) {
        Serial.println("DTC Code: P3104"); // DTC_FLS_CIRCUIT_VOLTAGE_HIGH
    }
    if (fuelLevel >= 1024 || fuelLevel < 0) {
    Serial.println("DTC Code: P3100"); // DTC_FLS_GENERIC_FAULT
    }

    // Additional checks for fuel level sensor
    if (fuelLevel == -1) {
        Serial.println("DTC Code: P3102"); // DTC_FLS_NOT_RESPONDING
    }
    if (fuelLevel < 0 || fuelLevel > 1023) {
        Serial.println("DTC Code: P3401"); // DTC_FLS_PLAUSIBILITY_FAILURE
    }
    if (fuelLevel > 1100) {
        Serial.println("DTC Code: P3406"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel < 0) {
        Serial.println("DTC Code: P3402"); // DTC_FLS_PLAUSIBILITY_FAILURE
    }
    if (fuelLevel > 1200) {
        Serial.println("DTC Code: P3411"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel < 100) {
        Serial.println("DTC Code: P3412"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel == 0) {
        Serial.println("DTC Code: P3413"); // DTC_FLS_NOT_RESPONDING
    }
    if (fuelLevel > 1300) {
        Serial.println("DTC Code: P3408"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel == 1000) {
        Serial.println("DTC Code: P3409"); // DTC_FLS_PLAUSIBILITY_FAILURE
    }
    if (fuelLevel > 1400) {
        Serial.println("DTC Code: P3410"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel < 50 || fuelLevel > 1500) {
        Serial.println("DTC Code: P3407"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel == 9999) {
        Serial.println("DTC Code: P3414"); // DTC_FLS_PLAUSIBILITY_FAILURE
    }
    if (fuelLevel == -9999) {
        Serial.println("DTC Code: P3415"); // DTC_FLS_PLAUSIBILITY_FAILURE
    }
    if (fuelLevel > 1600) {
        Serial.println("DTC Code: P3416"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel < 40) {
        Serial.println("DTC Code: P3417"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel > 1700) {
        Serial.println("DTC Code: P3418"); // DTC_FLS_LEVEL_OUT_OF_RANGE
    }
    if (fuelLevel == 12345) {
        Serial.println("DTC Code: P3419"); // DTC_FLS_PLAUSIBILITY_FAILURE
    }
}
