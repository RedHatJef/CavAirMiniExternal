//
// Created by redha on 11/7/2022.
//

#ifndef CAVAIR_BUZZER_H
#define CAVAIR_BUZZER_H

#include "DangerLevel.h"

class Buzzer {
public:
    Buzzer() = default;
    void init();

    volatile bool enabled = false;

    void on();
    void off();

    volatile void handlePeriodicTimer();

private:
    volatile DangerLevel myDangerLevel;
    unsigned long numLoops = 0;
};

extern Buzzer buzzer;

#endif //CAVAIR_BUZZER_H
