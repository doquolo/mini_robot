#include <Arduino.h>
#include <motors.h>
#include <controller.h>

void setup() {
  Serial.begin();
  initMotor();
  initGamepad();
}

void loop() {
  updateGamepad();
  if (isPressed(UP_BUTTON)) {
    Serial.println("F");
    run(FORWARD);
  }
  else if (isPressed(DOWN_BUTTON)) {
    Serial.println("B");
    run(BACKWARD);
  }
  else if (isPressed(LEFT_BUTTON)) {
    Serial.println("L");
    run(LEFT);
  }
  else if (isPressed(RIGHT_BUTTON)) {
    Serial.println("R");
    run(RIGHT);
  }
  else stop();
  delay(50);
}