#include <motors.h>

int speed = 128; // change speed here!


void stop() {
    // turn all output to off
    digitalWrite(M1_CW, LOW);
    digitalWrite(M1_CCW, LOW);
    digitalWrite(M2_CW, LOW);
    digitalWrite(M2_CCW, LOW);
}

void initMotor() {
    // motor 1
    pinMode(M1_CW, OUTPUT);
    pinMode(M1_CCW, OUTPUT);
    // motor 2
    pinMode(M2_CW, OUTPUT);
    pinMode(M2_CCW, OUTPUT);
}

void run(int direction) {
    switch (direction)
    {
    case FORWARD: // foward
        // cw all motors
        analogWrite(M1_CW, speed);
        digitalWrite(M1_CCW, LOW);
        analogWrite(M2_CW, speed);
        digitalWrite(M2_CCW, LOW);
        // set to speed
        break;
    case BACKWARD: // backward
        // cw all motors
        digitalWrite(M1_CW, LOW);
        analogWrite(M1_CCW, speed);
        digitalWrite(M2_CW, LOW);
        analogWrite(M2_CCW, speed);
        // set to speed
        break;
    case RIGHT: // turn right
        // cw m1, ccw m2
        analogWrite(M1_CW, speed);
        digitalWrite(M1_CCW, LOW);
        digitalWrite(M2_CW, LOW);
        analogWrite(M2_CCW, speed);
        // set to speed
        break;
    case LEFT: // turn left
        // ccw m1, cw m2
        digitalWrite(M1_CW, LOW);
        analogWrite(M1_CCW, speed);
        analogWrite(M2_CW, speed);
        digitalWrite(M2_CCW, LOW);
        // set to speed
        break;
    default:
        // set all motor to off
        stop();    
        break;  
    }
}