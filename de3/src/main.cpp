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
  if (getDistance() <= 1) { // nếu khoảng cách trước mặt robot bé hơn hoặc bằng 1cm
    stop(); // dừng lại
  } else {
    run(FORWARD); // nếu khoảng cách trước mặt của robot lớn hơn 1cm thì chạy thẳng
  }
  delay(50);
}