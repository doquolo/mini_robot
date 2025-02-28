#ifndef controller_h
#define controller_h

#include <HardwareBLESerial.h>

// gamepad input alias
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3
#define BUTTON4 4

#define UP_BUTTON 5
#define DOWN_BUTTON 6
#define LEFT_BUTTON 7
#define RIGHT_BUTTON 8

// ble device name
#define BLE_NAME "car3"

// using for init ble instance
void initGamepad();

// using for getting gamepad input
void updateGamepad();

// using for checking gamepad input
bool isPressed(int button);

// using for sending text to the builtin display
void sendText(String text);

#endif

