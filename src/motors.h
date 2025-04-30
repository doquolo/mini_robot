#ifndef motor_h
#define motor_h

#include <Arduino.h>

// define H-bridge module
#define M1_PWM 27
#define M1_CW 19
#define M1_CCW 18

#define M2_PWM 26
#define M2_CW 17
#define M2_CCW 16

// define direction alias
#define FORWARD 0
#define BACKWARD 1
#define RIGHT 2
#define LEFT 3
#define STOP 4

// using to init H-bridge moule
// expect no input
// expect no return value
void initMotor();

// using to stop all motor
// expect no input
// expect no return value
void stop();


// using to run to direction
// expect one input (direction)
// expect no return value
void run(int direction);

#endif