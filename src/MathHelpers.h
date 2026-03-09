//
// Created by redha on 11/24/2022.
//

#ifndef CAVAIR_MATHHELPERS_H
#define CAVAIR_MATHHELPERS_H

#define convertFeetToMeters(feet) ((unsigned int)(((float) feet / (float) 3.281f) + (float)0.5))
#define cf_round(value) ((char)(value + (float)0.5))
#define ucf_round(value) ((unsigned char)(value + (float)0.5))
#define uif_round(value) ((unsigned int)(value + (float)0.5))
#define clampValue(value, min, max) (value > max ? max : (value < min ? min : value))

#endif //CAVAIR_MATHHELPERS_H
