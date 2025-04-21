// Khai báo thư viện
#include <Arduino.h> // Thư viện cung cấp các hàm cơ bản của Arduino
#include <motors.h> // Thư viện cung cấp các hàm liên quan đến điều khiển động cơ
#include <controller.h> // Thư viện cung cấp các hàm liên quan đến nhận lệnh điều khiển từ điện thoại
#include <distance.h> // Thư viện cung cấp các hàm liên quan đến cảm biến khoảng cách

// Hàm thiết lập
void setup()
{
  // Mở serial kết nối với máy tính (Dùng để gỡ lỗi)
  Serial.begin();
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
  // cập nhật lệnh điều khiển mới từ app
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

  // nếu người dùng đã thay đổi chế độ
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
      // Hiển thị chữ "F" ra màn hình máy tính nếu đang chạy thẳng
      Serial.println("F");
      // Cho động cơ chạy thẳng
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
  case 1: // Chế độ chạy đến khi gặp vật cản
  {
    // Tại đây khoảng cách xe với vật thể trước mặt xe sẽ được lưu vào biến distance
    int distance = getDistance();
    // Điều kiện nếu khoảng cách bé hơn 20cm xe sẽ dừng lại
    if (distance <= 20)
    {
      // Lệnh dừng lại
      stop();
      // Hú còi
      digitalWrite(4, HIGH);
    }
    else
    {
      // Chạy thẳng
      run(FORWARD);
      // Tắt còi
      digitalWrite(4, LOW);
    }
    break;
  }
  case 2: // Chế độ tự động rẽ sang phải nếu gặp vật cản
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
  case 3: // Chế độ bám theo vật thể với khoảng cách 10 cm
  {
    int distance = getDistance();
    // Câu điều kiện có 2 vế, 2 vế phải cùng đúng thì mới thực thi
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