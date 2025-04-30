// Thư viện
#include <Arduino.h>
#include <motors.h>
#include <controller.h>
#include <distance.h>

// Hàm thiết lập
void setup()
{
  // Mở serial kết nối với máy tính (gỡ lỗi)
  Serial.begin(115200);
  // Thiết lập cầu H
  initMotor();
  // Thiết lập gamepad
  initGamepad();
  // Thiết lập cảm biến khoảng cách
  initDistance();

  // Bật còi
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
}

// biến lưu trữ chế độ robot
// 0: chế độ di chuyển bình thường
// 1: gặp vật cản đứng lại hú còi
// 2: gặp vật cản đứng lại hú còi xong rẽ hướng đi tiếp
// 3: đi theo vật thể
int prev_mode = 0;
int mode = 0;

void loop()
{
  // cập nhật gói tin mới từ app
  updateGamepad();

  // chuyển mode (nếu có)
  if (isPressed(BUTTON1))
    mode = 0;
  else if (isPressed(BUTTON2))
    mode = 1;
  else if (isPressed(BUTTON3))
    mode = 2;
  else if (isPressed(BUTTON4))
    mode = 3;

  if (prev_mode != mode)
  {
    // thông báo chuyển mode về điện thoại
    sendText(String("Da chuyen che do " + String(mode)));
    prev_mode = mode;
    // reset robot
    stop();
    digitalWrite(4, LOW);
  }

  // thực thi công việc dựa trên mode
  switch (mode)
  {
  case 0:
  { // di chuyển bình thường
    if (isPressed(UP_BUTTON))
    {
      Serial.println("F");
      run(FORWARD);
    }
    else if (isPressed(DOWN_BUTTON))
    {
      Serial.println("B");
      run(BACKWARD);
    }
    else if (isPressed(LEFT_BUTTON))
    {
      Serial.println("L");
      run(LEFT);
    }
    else if (isPressed(RIGHT_BUTTON))
    {
      Serial.println("R");
      run(RIGHT);
    }
    else
      stop();
    break;
  }
  case 1:
  {
    int distance = getDistance();
    if (distance <= 20)
    {
      stop();
      digitalWrite(4, HIGH);
    }
    else
    {
      run(FORWARD);
      digitalWrite(4, LOW);
    }
    break;
  }
  case 2:
  {
    int distance = getDistance();
    if (distance <= 20)
    {
      stop();
      digitalWrite(4, HIGH);
      delay(1000);
      run(RIGHT);
      delay(250);
      stop();
    }
    else
    {
      run(FORWARD);
      digitalWrite(4, LOW);
    }
    break;
  }
  case 3:
  {
    int distance = getDistance();
    if (distance <= 35 && distance >= 10)
    {
      run(FORWARD);
    }
    else
    {
      stop();
    }
    break;
  }
  default:
    break;
  }
  delay(50);
}