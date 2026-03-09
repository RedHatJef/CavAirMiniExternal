//
// Created by redha on 11/7/2022.
//

#ifndef CAVAIR_DANGER_LEVEL_H
#define CAVAIR_DANGER_LEVEL_H

// https://www.fsis.usda.gov/sites/default/files/media_file/2020-08/Carbon-Dioxide.pdf
// these numbers below are based loosely on the guidelines from the PDF above
// but made more conservative based on this device being used during activity

const unsigned int CO2LEVEL_THRESHOLD_LOW = 10000;
const unsigned int CO2LEVEL_THRESHOLD_MEDIUM = 20000;
const unsigned int CO2LEVEL_THRESHOLD_HIGH = 30000;
const unsigned int CO2LEVEL_THRESHOLD_CRITICAL = 40000;

typedef enum DangerLevel: unsigned char {
    DANGER_NONE = 0,
    DANGER_LOW = 1,
    DANGER_MODERATE = 2,
    DANGER_HIGH = 3,
    DANGER_CRITICAL = 4,
    DANGER_SYSTEM_FAILURE = 99,
    DANGER_CONSTANT = 100,          // <--- do not use, buzzer only
} DangerLevel;

const __FlashStringHelper *getDangerLevelString(DangerLevel dangerLevel);

DangerLevel getDangerLevelFromCO2PPM(unsigned int ppm);
unsigned int getPPMLevelForDangerLevel(DangerLevel dangerLevel);

//bool isDangerLevelHigher(DangerLevel oldLevel, DangerLevel newLevel);
//bool isDangerLevelLower(DangerLevel oldLevel, DangerLevel newLevel);

#endif //CAVAIR_DANGER_LEVEL_H
