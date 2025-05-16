// Khai báo thư viện
#include <Arduino.h> // Thư viện cung cấp các hàm cơ bản của Arduino
#include <motors.h> // Thư viện cung cấp các hàm liên quan đến điều khiển động cơ
#include <distance.h> // Thư viện cung cấp các hàm liên quan đến cảm biến khoảng cách
#include <controller.h> // Thư viện cung cấp các hàm liên quan đến cảm biến khoảng cách

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

int khoangCachDung = 1; // biến lưu trữ khoảng cách dừng 

// Hàm làm việc chính
void loop()
{
  updateGamepad(); // Đọc dữ liệu tay cầm
  // cập nhật biến lưu trữ khoảng cách dừng
  if (isPressed(BUTTON1)) khoangCachDung = 1; // bấm nút 1 thì xe sẽ dừng trước vật cản 1cm
  else if (isPressed(BUTTON2)) khoangCachDung = 10; // bấm nút 2 thì xe sẽ dừng trước vật cản 10cm
  else if (isPressed(BUTTON1)) khoangCachDung = 20; // bấm nút 3 thì xe sẽ dừng trước vật cản 20cm

  if (getDistance() <= khoangCachDung) { // nếu khoảng cách trước mặt robot bé hơn hoặc bằng khoảng cách dừng
    stop(); // dừng lại
  } else {
    run(FORWARD); ; // nếu không thì tiếp tục chạy thẳng
  }
  delay(50);
}