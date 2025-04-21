#ifndef motor_h
#define motor_h

#include <Arduino.h>

// Khai báo chân mạch điều khiển động cơ
#define M1_PWM 5
#define M1_CW 7
#define M1_CCW 6

#define M2_PWM 10
#define M2_CW 8
#define M2_CCW 9

// Khai báo các tên thay thế cho các chế độ chạy
// FORWARD: Chạy thẳng
// BACKWARD: Chạy lùi
// LEFT: Xoay trái
// RIGHT: Xoay phải
// STOP: Dừng
#define FORWARD 0
#define BACKWARD 1
#define RIGHT 2
#define LEFT 3
#define STOP 4

// Hàm này dùng để bật module điều khiển động cơ
// Cần gọi hàm này ở void setup() để module điều khiển động cơ hoạt động
void initMotor();

// Hàm này dùng để làm động cơ dừng lại
// dùng hàm này khi muốn xe đứng lại
void stop();

// Hàm này dùng để ra lệnh cho xe di chuyển theo hướng mong muốn
// tham số truyền vào là các tên thay thế ở trên
// ví dụ: run(FORWARD) sẽ ra lệnh cho xe chạy thẳng
void run(int direction);

// Hàm này dùng để thay đổi tốc độ của xe
// tham số truyền vào là tốc độ của xe theo kiểu số thực (int), dải tốc độ từ 0->255
// với 0: 0% tốc độ xe 2
//     255: 100% tốc độ của xe
// ví dụ: setSpeed(128) sẽ khiến xe chạy 50% tốc độ của xe
void setSpeed(int new_speed);

#endif