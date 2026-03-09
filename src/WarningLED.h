//
// Created by redha on 11/2/2022.
//

#ifndef CAVAIR_WARNING_LED_H
#define CAVAIR_WARNING_LED_H

#include <Arduino.h>
#include "DangerLevel.h"

class WarningLED {
public:
    WarningLED() = default;
    void init();

    volatile bool enabled = false;
    void setRGB(unsigned char redValue, unsigned char greenValue, unsigned char blueValue);
    volatile void handlePeriodicTimer();

    volatile bool isInFlashlightMode;

private:
    volatile DangerLevel myDangerLevel;
    volatile unsigned int numLoops = 0;
};

extern WarningLED warningLED;

#endif //CAVAIR_WARNING_LED_H
