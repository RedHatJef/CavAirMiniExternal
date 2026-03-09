//
// Created by redha on 12/2/2022.
//

#include <Arduino.h>

#ifndef CAVAIR_SHAREDSTRINGS_H
#define CAVAIR_SHAREDSTRINGS_H

#define SSF(pstr_pointer) ((const __FlashStringHelper *)pstr_pointer)

//#ifndef FPSTR
//#define FPSTR(pstr_pointer) (reinterpret_cast<const __FlashStringHelper *>(pstr_pointer))
//#endif

//#define CF(s) FPSTR(s)

const char SS_RUNNING[] PROGMEM                     = "Running...";
const char SS_SETTING[] PROGMEM                     = "Setting...";
const char SS_RESETTING[] PROGMEM                   = "Resetting...";
const char SS_PASSED[] PROGMEM                      = "*** PASSED ***";
const char SS_FAILED[] PROGMEM                      = "--- FAILED ---";
const char SS_NO_ALERTS[] PROGMEM                   = "-- NO ALERTS --";
const char SS_SPLASH[] PROGMEM                      = "SPLASH!";
const char SS_COMPLETE[] PROGMEM                    = "COMPLETE!";
const char SS_CANCELLED[] PROGMEM                   = "CANCELLED!";
const char SS_UNITS[] PROGMEM                       = "Units:";
const char SS_METRIC[] PROGMEM                      = "METRIC";
const char SS_ENGLISH[] PROGMEM                     = "ENGLISH";
const char SS_PERCENT[] PROGMEM                     = "PERCENT";
const char SS_SET[] PROGMEM                         = "SET";

const char SS_TITLE_CO2_SELF_TEST[] PROGMEM         = "CO2 Self-Test";
const char SS_TITLE_STARTING_UP[] PROGMEM           = "Starting up...";
const char SS_TITLE_TEST_ALERTS[] PROGMEM           = "Test Alerts";
const char SS_TITLE_BATTERY_INFO[] PROGMEM          = "Battery Info";
const char SS_TITLE_FLASHLIGHT_MODE[] PROGMEM       = "Flashlight Mode";
const char SS_TITLE_CO2_TEMP_OFFSET[] PROGMEM       = "CO2 Temp Offset";
const char SS_TITLE_CO2_SENSOR_ALTITUDE[] PROGMEM   = "CO2 Sensor Altitude";
const char SS_TITLE_SET_UNITS[] PROGMEM             = "Set Units";
const char SS_TITLE_SET_CO2_UNITS[] PROGMEM         = "Set CO2 Units";
const char SS_TITLE_SYSTEM_INFO[] PROGMEM           = "System Info";
const char SS_TITLE_CALIBRATE_CO2[] PROGMEM         = "CO2 Calibration";

const char SS_DANGER_NONE[] PROGMEM                 = "NONE";
const char SS_DANGER_LOW[] PROGMEM                  = "LOW";
const char SS_DANGER_MODERATE[] PROGMEM             = "MODERATE";
const char SS_DANGER_HIGH[] PROGMEM                 = "HIGH";
const char SS_DANGER_CRITICAL[] PROGMEM             = "CRITICAL";
const char SS_DANGER_SYSTEM_FAILURE[] PROGMEM       = "SYS FAIL";

const char SS_FIELD_VOLTAGE[] PROGMEM               = "Voltage: ";
const char SS_FIELD_RAW_VALUE[] PROGMEM             = "Raw Value: ";
const char SS_FIELD_SERIAL_NUMBER[] PROGMEM         = "SN: ";
const char SS_FIELD_TEMP_OFFSET[] PROGMEM           = "Temp Offset: ";
const char SS_FIELD_CO2_CALIBRATION[] PROGMEM       = "Atmos. CO2: ";

const char SS_PPM[] PROGMEM                         = " ppm";
const char SS_UNKNOWN[] PROGMEM                     = "???";

const char SS_ALERTS_LEVEL[] PROGMEM                = "LVL = ";
const char SS_ALERTS_LED[] PROGMEM                  = "LED = ";
const char SS_ALERTS_BUZZER[] PROGMEM               = "BUZZER = ";
const char SS_BATTERY_EMPTY[] PROGMEM               = " --%";
const char SS_TITLE_RESET_MINMAX_CO2[] PROGMEM      = "Reset Min/Max CO2";
const char SS_TITLE_CO2_SENSOR_CONFIG[] PROGMEM     = "CO2 Sensor Config";

#endif //CAVAIR_SHAREDSTRINGS_H
