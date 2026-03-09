//
// Created by redha on 11/25/2022.
//

#ifndef CAVAIR_MENUACTION_H
#define CAVAIR_MENUACTION_H

#include "DisplayMode.h"

typedef struct MenuAction {
    DisplayMode displayMode;
    int screenHoldDelayMillis;      // for static screens, hold the screen for this long
    DisplayMode nextDisplayMode;
} MenuAction;

#endif //CAVAIR_MENUACTION_H
