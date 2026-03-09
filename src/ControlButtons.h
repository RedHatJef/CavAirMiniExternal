//
// Created by redha on 11/2/2022.
//

#ifndef CAVAIR_CONTROL_BUTTONS_H
#define CAVAIR_CONTROL_BUTTONS_H

class ControlButtons {
public:
    ControlButtons() = default;

    void init();

    bool isButton0Pressed();
    bool isButton1Pressed();
    bool isAnyButtonPressed();

    void clearButtonState();
};

extern ControlButtons controlButtons;

#define b0pressed controlButtons.isButton0Pressed()
#define b1pressed controlButtons.isButton1Pressed()
#define anyPressed (b0pressed || b1pressed)

#endif //CAVAIR_CONTROL_BUTTONS_H
