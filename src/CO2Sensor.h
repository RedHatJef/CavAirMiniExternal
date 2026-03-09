//
// Created by redha on 11/7/2022.
//

#ifndef CAVAIR_CO2SENSOR_H
#define CAVAIR_CO2SENSOR_H

//#define CO2_ENABLE_DEBUGGING

#include "MathHelpers.h"
#include "MeaurementUnits.h"

typedef struct SCD40Config {
    char serialNumber[16] = { '\0' };
    float tempOffsetC = 0;
    float tempOffsetF = 0;
    uint16_t altitudeM = 0;
    uint16_t altitudeF = 0;
    const uint16_t CO2_CALIBRATION_PPM_DEFAULT = 413;
    uint16_t co2CalibrationPPM;
} SCD40Config;

const unsigned int MAX_ALTITUDE_FEET = 30000;
const unsigned int MAX_ALTITUDE_METERS = convertFeetToMeters(MAX_ALTITUDE_FEET);

const float MAX_TEMP_OFFSET_F = 99.99;
const float MIN_TEMP_OFFSET_F = -99.99;
const float MAX_TEMP_OFFSET_C = MAX_TEMP_OFFSET_F * (float)5.0 / (float)9.0;
const float MIN_TEMP_OFFSET_C = MIN_TEMP_OFFSET_F * (float)5.0 / (float)9.0;

#define MAX_TEMP_OFFSET (cavAirSettings.measurementUnits == MU_ENGLISH ? MAX_TEMP_OFFSET_F : MAX_TEMP_OFFSET_C)
#define MIN_TEMP_OFFSET (cavAirSettings.measurementUnits == MU_ENGLISH ? MIN_TEMP_OFFSET_F : MIN_TEMP_OFFSET_C)

class CO2Sensor {
public:
    CO2Sensor() = default;
    void init();
    void loop();
    bool selfTest();
    bool forceRecalibration(uint16_t concentration);
    [[nodiscard]] bool isReady() const;
    void resetMinMax();
    bool setAltitudeMeters(unsigned int newAltitude);
    bool setAltitudeFeet(unsigned int newAltitude);
    bool setTempOffsetF(float tempF);
    bool setTempOffsetC(float tempC);

    unsigned int co2ppm_current = 0;
    unsigned int co2ppm_last = 0;
    int co2ppm_min = -1;
    int co2ppm_max = -1;

    float temperatureC = -1;
    float temperatureF = -1;
    int8_t humidity = -1;

    unsigned char numCO2Samples = 0;

    SCD40Config config;

private:
    bool refreshConfig();
    void clearConfig();
    unsigned char cycleNum = 0;
    bool isSensorReady = false;
    bool initPassed = false;
};

extern CO2Sensor co2Sensor;

#endif //CAVAIR_CO2SENSOR_H
