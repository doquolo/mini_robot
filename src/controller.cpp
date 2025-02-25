#include "controller.h"

// ble instance
HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

// gamepad state
bool gamepad_state[9] = {0, 0, 0, 0, 0, 0, 0, 0};

void initGamepad()
{
    if (!bleSerial.beginAndSetupBLE(BLE_NAME))
    {
        while (true)
        {
            Serial.println("failed to initialize HardwareBLESerial!");
            delay(250);
        }
    }
}

void updateGamepad()
{
    // this must be called regularly to perform BLE updates
    bleSerial.poll();

    while (bleSerial.available() > 0)
    {
        if (bleSerial.read() == 0x21) // if "!" is detected
        {
            switch (bleSerial.read())
            {
            case 'B':
            { // process button
                char button = bleSerial.read();
                char state = bleSerial.read();
                Serial.printf("Button event: button %d - %s\n", (int)(button - '0'), (atoi(&state)) ? "pressed" : "released");
                gamepad_state[(int)(button-'0')-1] = atoi(&state);
                // DEBUG
                for (int i = 0; i < 8; i++) {
                    Serial.printf("%d ", gamepad_state[i]);
                }
                Serial.println();
                // END_DEBUG
                break;
            }
            default:
                break;
            }
        }
    }
}

bool isPressed(int button) { 
    return gamepad_state[button-1];
}