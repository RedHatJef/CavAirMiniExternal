#include <Arduino.h>
#include <Wire.h>

#include "WarningLED.h"
#include "ControlButtons.h"
#include "CO2Sensor.h"
#include "Buzzer.h"
#include "PeriodicTimer.h"
#include "DisplayMode.h"
#include "Battery.h"

#include "Version.h"
#include "CavAirMiniDisplay.h"
#include "CavSerial.h"
#include "Settings.h"

volatile DangerLevel currentDangerLevel = DANGER_NONE;

Settings cavAirSettings;

void setup()
{
    CavSerial.begin(115200);
    while(!Serial);
    CavSerial.print(SSF(CAVAIR_VERSION));
    CavSerial.print(F(" :: "));
    CavSerial.println(SSF(CAVAIR_SUBVERSION));

    loadSettings();
    saveSettings();

    Wire.begin();
    delay(100);

    warningLED.init();
    buzzer.init();
    controlButtons.init();
    battery.init();

    mainDisplay.init();
    co2Sensor.init();
    periodicTimer.init();

    //CavSerial.println(F("System Started."));
    cavAirSettings.numBoots++;
    saveSettings();
}

void loop()
{
    const DisplayMode currentDisplayMode = mainDisplay.getDisplayMode();

    if(currentDisplayMode == DM_MAIN || currentDisplayMode == DM_SYSTEM_INFO) {
        co2Sensor.loop();
    }

    if(currentDisplayMode == DM_MAIN || currentDisplayMode == DM_BATTERY_INFO) {
        battery.loop();
    }

    if(mainDisplay.isSystemReady()) {
        if(currentDisplayMode == DM_TEST_ALERTS || currentDisplayMode == DM_FLASHLIGHT) {
            // skip
        }
        else {
            warningLED.enabled = true;
            buzzer.enabled = true;
            currentDangerLevel = getDangerLevelFromCO2PPM(co2Sensor.co2ppm_current);
        }
    }

    mainDisplay.updateDisplay();
}
