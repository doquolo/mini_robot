// Thư viện
#include <Arduino.h>
#include <motors.h>
#include <controller.h>
#include <ESP32Servo.h>

// Servo myservo; // create servo object to control a servo
//                // 16 servo objects can be created on the ESP32

// int pos = 0; // variable to store the servo position
// // Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
// int servoPin = 26;

// Hàm thiết lập
void setup()
{
  // Mở serial kết nối với máy tính (gỡ lỗi)
  Serial.begin(115200);
  // nghe servo
  // Allow allocation of all timers
	// ESP32PWM::allocateTimer(0);
	// ESP32PWM::allocateTimer(1);
	// ESP32PWM::allocateTimer(2);
	// ESP32PWM::allocateTimer(3);

  // myservo.setPeriodHertz(50); // standard 50 hz servo
  // myservo.attach(26, 500, 2400);

  // myservo.write(0);
  // delay(1000);
  // myservo.write(40);
  // Thiết lập cầu H
  initMotor();
  // Thiết lập gamepad
  initGamepad();
}

void loop()
{
  // cập nhật gói tin mới từ app
  updateGamepad();

  if (isPressed(UP_BUTTON))
  {
    run(FORWARD);
  }
  else if (isPressed(DOWN_BUTTON))
  {
    run(BACKWARD);
  }
  else if (isPressed(LEFT_BUTTON))
  {
    run(RIGHT);
  }
  else if (isPressed(RIGHT_BUTTON))
  {
    run(LEFT);
  }
  // else if (isPressed(BUTTON1))
  //   myservo.write(0);
  // else if (isPressed(BUTTON2))
  //   myservo.write(40);
  else
    stop();

  delay(50);
}