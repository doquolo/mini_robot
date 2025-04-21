#ifndef distance_h
#define distance_h

#include <Arduino.h>

#define TRIG 2
#define ECHO 3

// Khai báo các hằng số về vận tốc của âm thanh và các hằng số chuyển đổi đơn vị
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

// Hàm này được dùng để bật cảm biến khoảng cách
// Cần gọi hàm này ở void setup() để cảm biến khoảng cách hoạt động
void initDistance();

// Hàm này được dùng để lấy dữ liệu khoảng cách từ cảm biến khoảng cách
// kiểu dữ liệu trả về ở đây là kiểu số nguyên (1, 2, 3, 0.5, ....)
int getDistance();

#endif