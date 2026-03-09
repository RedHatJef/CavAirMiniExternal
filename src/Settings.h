//
// Created by redha on 3/27/2024.
//

#ifndef CAVAIRMINI_SETTINGS_H
#define CAVAIRMINI_SETTINGS_H

#include "MeaurementUnits.h"
#define DEFAULT_VERSION_CODE 0xDEADBEEF

typedef enum MeasurementUnits: unsigned char {
    MU_ENGLISH,
    MU_METRIC,
    MU_PPM,
    MU_PERCENT
} MeasurementUnits;

struct Settings {
    uint32_t versionCode = DEFAULT_VERSION_CODE;
    MeasurementUnits measurementUnits = MU_ENGLISH;
    MeasurementUnits co2MeasurementUnits = MU_PPM;
    uint32_t numBoots = 0;
};

extern Settings cavAirSettings;

void loadSettings();
void saveSettings();

#define DISTANCE_UNIT_MARKER (cavAirSettings.measurementUnits == MU_ENGLISH ? '\'' : 'm')
#define TEMP_UNIT_MARKER (cavAirSettings.measurementUnits == MU_ENGLISH ? 'F' : 'C')
#define MAX_ALTITUDE_VALUE (cavAirSettings.measurementUnits == MU_ENGLISH ? MAX_ALTITUDE_FEET : MAX_ALTITUDE_METERS)
#define MEASUREMENT_UNITS_TITLE (cavAirSettings.measurementUnits == MU_ENGLISH ? SS_ENGLISH : SS_METRIC)
#define CO2_MEASUREMENT_UNITS_TITLE (cavAirSettings.co2MeasurementUnits == MU_PPM ? SS_PPM : SS_PERCENT)
#define MAX_CO2_CALIBRATION_PPM 2000

#endif //CAVAIRMINI_SETTINGS_H
