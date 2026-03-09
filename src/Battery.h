//
// Created by redha on 11/27/2022.
//

#ifndef CAVAIR_BATTERY_H
#define CAVAIR_BATTERY_H

class Battery {
public:
    Battery() = default;
    void init();
    void loop();

    float voltage = 0;
    int8_t percent = -1;
    unsigned int rawValue = 0;
    bool useFastSampleRate = false;

private:
    uint8_t numCycles = 0;
    bool isReady = false;
};

extern Battery battery;


#endif //CAVAIR_BATTERY_H
