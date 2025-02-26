#ifndef distance_h
#define distance_h

#include <Arduino.h>

#define TRIG 2
#define ECHO 3

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

// using to init supersonic sensor
void initDistance();

// using to get distance in cm
int getDistance();

#endif