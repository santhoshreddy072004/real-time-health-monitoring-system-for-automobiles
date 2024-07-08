#include "BMP180Sensor.h"
#include "DTC_Codes.h"

// Create an SFE_BMP180 object
SFE_BMP180 pressure;

// Initialize the BMP180 sensor
void setupBMP180() {
    if (pressure.begin()) {
        Serial.println("BMP180 init success");
    } else {
        Serial.println("DTC Code: P3000"); // DTC_TPS_GENERAL_FAULT
        Serial.println("DTC Code: P3200"); // DTC_ETS_GENERAL_FAULT
        while (true); // Pause forever if initialization fails
    }
}
void checkPressure(float pressureValue);
void checkTemperature(float temperature);
// Check BMP180 sensor readings
void checkBMP180() {
    char status;
    double temperature, pressureValue;

    status = pressure.startTemperature();
    if (status != 0) {
        delay(status); // Wait for the measurement to complete

        status = pressure.getTemperature(temperature);
        if (status != 0) {
            status = pressure.startPressure(3);
            if (status != 0) {
                delay(status); // Wait for the measurement to complete

                status = pressure.getPressure(pressureValue, temperature);
                if (status != 0) {
                    // Convert pressure from Pa to psi
                    double pressurePsi = pressureValue * 0.000145038;

                    Serial.print("Engine Temperature: ");
                    Serial.print(temperature, 2);
                    Serial.print(" deg C\nTire Pressure: ");
                    Serial.print(pressureValue,2);
                    Serial.print(" hPa, ");
                    Serial.print(pressurePsi, 2);
                    Serial.println(" PSI");

                    // Check pressure and temperature readings
                    checkPressure(pressurePsi);
                    checkTemperature(temperature);

                } else {
                    Serial.println("DTC Code: P3001"); // DTC_TPS_COMM_FAILURE
                }
            } else {
                Serial.println("DTC Code: P3003"); // DTC_TPS_NOT_RESPONDING
            }
        } else {
            Serial.println("DTC Code: P3201"); // DTC_ETS_COMM_FAILURE
        }
    } else {
        Serial.println("DTC Code: P3203"); // DTC_ETS_CIRCUIT_VOLTAGE_LOW
    }
}

// Check pressure values
void checkPressure(float pressureValue) {
    if (pressureValue < NORMAL_PRESSURE_LOW) {
        Serial.println("DTC Code: P3007"); // DTC_TPS_PRESSURE_OUT_OF_RANGE
    } else if (pressureValue > NORMAL_PRESSURE_HIGH) {
        Serial.println("DTC Code: P3007"); // DTC_TPS_PRESSURE_OUT_OF_RANGE
    }

    // Additional checks for pressure sensor
    if (pressureValue == -1) {
        Serial.println("DTC Code: P3002"); // DTC_TPS_NOT_RESPONDING
    }
    if (pressureValue < 0 || pressureValue > 1500) {
        Serial.println("DTC Code: P3301"); // DTC_TPS_PLAUSIBILITY_FAILURE
    }
    if (pressureValue > 2000) {
        Serial.println("DTC Code: P3307"); // DTC_TPS_PRESSURE_OUT_OF_RANGE
    }
    if (pressureValue < 0) {
        Serial.println("DTC Code: P3302"); // DTC_TPS_PLAUSIBILITY_FAILURE
    }
    if (pressureValue > 2200) {
        Serial.println("DTC Code: P3311"); // DTC_TPS_CIRCUIT_VOLTAGE_HIGH
    }
    if (pressureValue < 60) {
        Serial.println("DTC Code: P3312"); // DTC_TPS_CIRCUIT_VOLTAGE_LOW
    }
    if (pressureValue == 0) {
        Serial.println("DTC Code: P3313"); // DTC_TPS_CIRCUIT_SHORT_TO_GROUND
    }
    if (pressureValue > 2300) {
        Serial.println("DTC Code: P3308"); // DTC_TPS_ACCURACY_FAILURE
    }
    if (pressureValue == 1000) {
        Serial.println("DTC Code: P3309"); // DTC_TPS_SELF_TEST_FAILED
    }
    if (pressureValue > 2400) {
        Serial.println("DTC Code: P3310"); // DTC_TPS_RANGE_CHECK_FAILED
    }
    if (pressureValue < 50 || pressureValue > 2500) {
        Serial.println("DTC Code: P3307"); // DTC_TPS_PRESSURE_OUT_OF_RANGE
    }
    if (pressureValue == 9999) {
        Serial.println("DTC Code: P3314"); // DTC_TPS_PLAUSIBILITY_FAILURE
    }
    if (pressureValue == -9999) {
        Serial.println("DTC Code: P3315"); // DTC_TPS_PLAUSIBILITY_FAILURE
    }
    if (pressureValue > 2600) {
        Serial.println("DTC Code: P3316"); // DTC_TPS_CIRCUIT_VOLTAGE_HIGH
    }
    if (pressureValue < 40) {
        Serial.println("DTC Code: P3317"); // DTC_TPS_CIRCUIT_VOLTAGE_LOW
    }
    if (pressureValue > 2700) {
        Serial.println("DTC Code: P3318"); // DTC_TPS_PRESSURE_OUT_OF_RANGE
    }
    if (pressureValue == 12345) {
        Serial.println("DTC Code: P3319"); // DTC_TPS_PLAUSIBILITY_FAILURE
    }
}

// Check temperature values
void checkTemperature(float temperature) {
    if (temperature < NORMAL_TEMP_LOW) {
        Serial.println("DTC Code: P3006"); // DTC_ETS_TEMP_OUT_OF_RANGE
    } else if (temperature > NORMAL_TEMP_HIGH) {
        Serial.println("DTC Code: P3006"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }

    // Additional checks for temperature sensor
    if (temperature == -1) {
        Serial.println("DTC Code: P3202"); // DTC_ETS_NOT_RESPONDING
    }
    if (temperature < 0 || temperature > 150) {
        Serial.println("DTC Code: P3501"); // DTC_ETS_PLAUSIBILITY_FAILURE
    }
    if (temperature > 200) {
        Serial.println("DTC Code: P3506"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature < 0) {
        Serial.println("DTC Code: P3502"); // DTC_ETS_PLAUSIBILITY_FAILURE
    }
    if (temperature > 220) {
        Serial.println("DTC Code: P3511"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature < 60) {
        Serial.println("DTC Code: P3512"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature == 0) {
        Serial.println("DTC Code: P3513"); // DTC_ETS_NOT_RESPONDING
    }
    if (temperature > 230) {
        Serial.println("DTC Code: P3508"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature == 1000) {
        Serial.println("DTC Code: P3509"); // DTC_ETS_PLAUSIBILITY_FAILURE
    }
    if (temperature > 240) {
        Serial.println("DTC Code: P3510"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature < 50 || temperature > 250) {
        Serial.println("DTC Code: P3507"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature == 9999) {
        Serial.println("DTC Code: P3514"); // DTC_ETS_PLAUSIBILITY_FAILURE
    }
    if (temperature == -9999) {
        Serial.println("DTC Code: P3515"); // DTC_ETS_PLAUSIBILITY_FAILURE
    }
    if (temperature > 260) {
        Serial.println("DTC Code: P3516"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature < 40) {
        Serial.println("DTC Code: P3517"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature > 270) {
        Serial.println("DTC Code: P3518"); // DTC_ETS_TEMP_OUT_OF_RANGE
    }
    if (temperature == 12345) {
        Serial.println("DTC Code: P3519"); // DTC_ETS_PLAUSIBILITY_FAILURE
    }
}
