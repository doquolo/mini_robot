#include <motors.h>

int speed = 255; // change speed here!


void stop() {
    // turn all output to off
    digitalWrite(M1_CW, LOW);
    digitalWrite(M1_CCW, LOW);
    digitalWrite(M2_CW, LOW);
    digitalWrite(M2_CCW, LOW);
    // turn pwm output to 0 (off)
    analogWrite(M1_PWM, speed);
    analogWrite(M2_PWM, speed);
}

void initMotor() {
    // motor 1
    pinMode(M1_PWM, OUTPUT);
    pinMode(M1_CW, OUTPUT);
    pinMode(M1_CCW, OUTPUT);
    // motor 2
    pinMode(M2_PWM, OUTPUT);
    pinMode(M2_CW, OUTPUT);
    pinMode(M2_CCW, OUTPUT);

    pinMode(25, HIGH);
}

void run(int direction) {
    switch (direction)
    {
    case FORWARD: // foward
        // cw all motors
        digitalWrite(M1_CW, HIGH);
        digitalWrite(M1_CCW, LOW);
        digitalWrite(M2_CW, HIGH);
        digitalWrite(M2_CCW, LOW);
        // set to speed
        analogWrite(M1_PWM, speed);
        analogWrite(M2_PWM, speed);
        break;
    case BACKWARD: // backward
        // cw all motors
        digitalWrite(M1_CW, LOW);
        digitalWrite(M1_CCW, HIGH);
        digitalWrite(M2_CW, LOW);
        digitalWrite(M2_CCW, HIGH);
        // set to speed
        analogWrite(M1_PWM, speed);
        analogWrite(M2_PWM, speed);
        break;
    case RIGHT: // turn right
        // cw m1, ccw m2
        digitalWrite(M1_CW, HIGH);
        digitalWrite(M1_CCW, LOW);
        digitalWrite(M2_CW, LOW);
        digitalWrite(M2_CCW, HIGH);
        // set to speed
        analogWrite(M1_PWM, speed);
        analogWrite(M2_PWM, speed);
        break;
    case LEFT: // turn left
        // ccw m1, cw m2
        digitalWrite(M1_CW, LOW);
        digitalWrite(M1_CCW, HIGH);
        digitalWrite(M2_CW, HIGH);
        digitalWrite(M2_CCW, LOW);
        // set to speed
        analogWrite(M1_PWM, speed);
        analogWrite(M2_PWM, speed);
        break;
    default:
        // set all motor to off
        stop();    
        break;  
    }
}