//
// Created by redha on 11/7/2022.
//

#ifndef CAVAIR_PERIODICTIMER_H
#define CAVAIR_PERIODICTIMER_H


class PeriodicTimer {
public:
    PeriodicTimer() = default;
    void init();

    unsigned long milliseconds;
};

extern PeriodicTimer periodicTimer;

#endif //CAVAIR_PERIODICTIMER_H
