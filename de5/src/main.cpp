// Khai báo thư viện
#include <Arduino.h> // Thư viện cung cấp các hàm cơ bản của Arduino
#include <motors.h> // Thư viện cung cấp các hàm liên quan đến điều khiển động cơ
#include <distance.h> // Thư viện cung cấp các hàm liên quan đến cảm biến khoảng cách

// Hàm thiết lập
void setup()
{
  // Mở serial kết nối với máy tính (Dùng để gỡ lỗi)
  Serial.begin();
  // Bật module điều khiển động cơ
  initMotor();
  // Uncomment dòng này để thay đổi tốc độ động cơ
  // setSpeed(255);
}

// Hàm làm việc chính
void loop()
{
  if (getDistance() <= 5) { // nếu khoảng cách trước mặt robot bé hơn hoặc bằng 5cm
    stop(); // dừng lại
    run(RIGHT); // rẽ phải
    delay(200); // chờ rẽ phải 1/4s
  } else {
    run(FORWARD); // nếu khoảng cách trước mặt của robot lớn hơn 1cm thì chạy thẳng
  }
  delay(50);
}