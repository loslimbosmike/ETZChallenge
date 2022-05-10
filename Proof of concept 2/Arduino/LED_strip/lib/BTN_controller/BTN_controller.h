#ifndef BTN_controller_h
#define BTN_controller_h

#include <Arduino.h>

class BTN_controller
{
private:
    int _btnPin;

public:
    BTN_controller(int btnPin=2);
    bool GetState();
};

#endif