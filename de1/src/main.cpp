// Khai báo thư viện
#include <Arduino.h> // Thư viện cung cấp các hàm cơ bản của Arduino
#include <motors.h> // Thư viện cung cấp các hàm liên quan đến điều khiển động cơ
#include <controller.h> // Thư viện cung cấp các hàm liên quan đến nhận lệnh điều khiển từ điện thoại

// Hàm thiết lập
void setup()
{
  // Mở serial kết nối với máy tính (Dùng để gỡ lỗi)
  Serial.begin();
  // Bật module điều khiển động cơ
  initMotor();
  // Uncomment dòng này để thay đổi tốc độ động cơ
  // setSpeed(255);
  // Bật tính năng điều khiển từ xa
  initGamepad();
}

// Hàm làm việc chính
void loop()
{
  // cập nhật lệnh điều khiển mới từ app
  updateGamepad();

  // Đọc nút
  if (isPressed(UP_BUTTON)) // nếu nút đi lên được bấm
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
  else // nếu không có nút nào được bấm -> robot dừng lại
    stop();
  delay(50);
}