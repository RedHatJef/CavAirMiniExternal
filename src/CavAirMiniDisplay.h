//
// Created by redha on 12/1/2022.
// https://github.com/greiman/SSD1306Ascii
//

#ifndef CAVAIR_CAVAIRMINIDISPLAY_H
#define CAVAIR_CAVAIRMINIDISPLAY_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "DisplayMode.h"
#include "MenuAction.h"
#include "SplashGraphic.h"

#define UP_ARROW (char)0x18
#define RIGHT_ARROW (char)0x1A
#define NUM_CO2PPM_DIGITS 5
#define NUM_ALTITUDE_DIGITS 5
#define NUM_TEMP_OFFSET_DIGITS 6


#if DUMP_DISPLAY
#define DumpDisplay(x) CavAirMiniDisplay::dumpDisplayDataToSerial(x)
#else
#define DumpDisplay(x)
#endif

class CavAirMiniDisplay {
public:
    CavAirMiniDisplay() = default;

    void init();
    void updateDisplay();
    void displayNone();

    [[nodiscard]] DisplayMode getDisplayMode() const;
    [[nodiscard]] bool isSystemReady() const;

    void displaySplashScreen();
    void displayTitleScreen();
    void displayCO2SelfTest();
    void displayCO2SelfTestSuccess();
    void displayCO2SelfTestFailure();
    void displayMain();
    void displaySystemInfo();
    void displayBatteryInfo();
    void displayCO2Config();
    void displayCO2Calibration();
    void displayCO2CalibrationStart();
    void displayCO2CalibrationComplete();
    void displayCO2CalibrationCancelled();
    void displayCO2CalibrationFailed();
    void displaySetAltitude();
    void displaySetTemperatureOffset();
    void displayResetMinMax();
    void displaySetUnits();
    void displaySetCO2Units();
    void displayTestAlerts();
    void displayFlashlight();
    void displaySettingAltitudeStart();
    void displaySettingAltitudeComplete();
    void displaySettingTempOffsetStart();
    void displaySettingTempOffsetComplete();
    void displayResetMinMaxStart();
    void displayResetMinMaxComplete();
    void displayCO2Value(unsigned int ppm, bool rightJustify);
    void displayDebug(const char* debugString, int debugValue);

#if DUMP_DISPLAY
    static void dumpDisplayDataToSerial(const char* title);
#endif

private:
    void displayTitleString(const char *stringToDisplay);
    void displayTitleStringF(const __FlashStringHelper *progmemStringToDisplay);

    void initDevice();
    void clearDevice();
    void updateDevice();

    void displayCO2SelfTestBase();
    void displayCO2CalibrationBase();
    void displaySettingAltitudeBase();
    void displaySetTemperatureOffsetBase();
    void displayResetMinMaxBase();

    static void convertValueToString(unsigned int value, char* buf, bool showLeadingZeros, bool rightJustify);
    float getFloatFromDigits();
    unsigned int getUIntFromDigits();
    void refreshTempOffsetDigits();
    void refreshAltitudeDigits(bool showLeadingZeros);
    void refreshCO2PPMDigits(bool showLeadingZeros);

    bool systemReady = false;
    DisplayMode displayMode = DM_NONE;

    unsigned long nextDisplayUpdate = 1; // must be 1 to kick things off
    unsigned char optionNum = 0;

    char digitBuffer[16]{};

    [[nodiscard]] const MenuAction* getCurrentMenuAction() const;
    [[nodiscard]] const MenuAction* getMenuAction(DisplayMode d) const;
    DisplayMode gotoNextMenuAction();
    void runMenuAction(DisplayMode d);

    static Adafruit_SSD1306 ssd1306;

    // use -1 for "I will handle advancing in my display function"
    // use  0 for "advance manually or by menu button"
    // use  1 for "advance next frame"
    // use >1 to advance on a delay in milliseconds
    const MenuAction menuActions[32] = {
            // STARTUP
            {DM_NONE,                   1,    DM_SPLASH },
            {DM_SPLASH,                 3000, DM_TITLE },
            {DM_TITLE,                  1500, DM_CO2_SELF_TEST },
            {DM_CO2_SELF_TEST,          -1,   DM_NONE },
            {DM_CO2_SELF_TEST_SUCCESS,  -1,   DM_MAIN },
            {DM_CO2_SELF_TEST_FAILURE,  -1,   DM_NONE },

            // MAIN MENUS
            {DM_MAIN,                    0,   DM_SYSTEM_INFO },
            {DM_SYSTEM_INFO,             0,   DM_BATTERY_INFO },
            {DM_BATTERY_INFO,           -1,   DM_CO2_CONFIG },
            {DM_CO2_CONFIG,               0,  DM_SET_ALTITUDE },
            {DM_SET_ALTITUDE,           -1,  DM_SET_TEMP_OFFSET },
            {DM_SET_TEMP_OFFSET,        -1,  DM_CO2_CALIBRATION },
            {DM_CO2_CALIBRATION,        -1,  DM_RESET_MINMAX },
            {DM_RESET_MINMAX,           -1,  DM_SET_UNITS },
            {DM_SET_UNITS,               0,  DM_SET_CO2_UNITS },
            {DM_SET_CO2_UNITS,           0,  DM_TEST_ALERTS },
            {DM_TEST_ALERTS,            -1,  DM_FLASHLIGHT },
            {DM_FLASHLIGHT,             -1,  DM_MAIN },

            // PROCESSES
            {DM_SETTING_ALTITUDE_START, 2000, DM_SETTING_ALTITUDE_COMPLETE },
            {DM_SETTING_ALTITUDE_COMPLETE,      2000,   DM_MAIN },
            {DM_SETTING_TEMP_OFFSET_START,      2000,   DM_SETTING_TEMP_OFFSET_COMPLETE },
            {DM_SETTING_TEMP_OFFSET_COMPLETE,   2000,   DM_MAIN },
            {DM_RESET_MINMAX_START,              500,   DM_RESET_MINMAX_COMPLETE },
            {DM_RESET_MINMAX_COMPLETE,           500,   DM_MAIN },
            {DM_CO2_CALIBRATION_START, -1, DM_CO2_CALIBRATION_COMPLETE },
            {DM_CO2_CALIBRATION_COMPLETE, 3000, DM_MAIN },
            {DM_CO2_CALIBRATION_CANCELLED, 3000, DM_MAIN },
            {DM_CO2_CALIBRATION_FAILED, 3000, DM_MAIN },
    };
};

extern CavAirMiniDisplay mainDisplay;

#endif //CAVAIR_CAVAIRMINIDISPLAY_H
