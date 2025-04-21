#ifndef controller_h
#define controller_h

#include <HardwareBLESerial.h>

// Tên thay thế cho các nút bấm
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3
#define BUTTON4 4

#define UP_BUTTON 5
#define DOWN_BUTTON 6
#define LEFT_BUTTON 7
#define RIGHT_BUTTON 8

// Tên thiết bị
#define BLE_NAME "car1"

// Hàm này dùng để bật điều khiển từ xa
// Cần gọi hàm này ở void setup() để điều khiển từ xa hoạt động
void initGamepad();

// Hàm này dùng để đọc thông tin phím bấm từ điện thoại
// hàm này cần được gọi liên tục trong hàm void loop() để có tác dụng cập nhật
void updateGamepad();

// Hàm này được dùng để kiểm tra nút bấm có được bấm hay không
// sẽ trả về giá trị Đúng (true) nếu nút được bấm trên điện thoại, Sai (false) nếu nút không được bấm
bool isPressed(int button);

// Hàm này được dùng để gửi 1 đoạn văn bản về màn hình điện thoại
// kiểu dữ liệu đầu vào là 1 chuỗi kí tự, ví dụ "Xin chao"
void sendText(String text);

#endif

