#include <Arduino.h>
#include <motors.h>
#include <controller.h>
#include <distance.h>

void setup() {
  Serial.begin();
  initMotor();
  initGamepad();
  initDistance();
}

long long int prev_controller_update = 0;
const int controller_update_interval = 50;
long long int prev_sensor_update = 0;
const int sensor_update_interval = 500;

void loop() {
  updateGamepad();
  long long int temp = millis();
  if (temp - prev_controller_update >= controller_update_interval) {
    prev_controller_update = temp;
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
  } 
  if (temp - prev_sensor_update >= sensor_update_interval) {
    prev_sensor_update = temp;
    char text[100];
    sprintf(text, "Distance: %d", getDistance());
    sendText(text);
    Serial.println(text);
  }
  delay(50);
}