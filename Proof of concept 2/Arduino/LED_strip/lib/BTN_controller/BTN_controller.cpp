#include <BTN_controller.h>

volatile bool ledState = false;
void ButtonISR();

BTN_controller::BTN_controller(int btnPin)
{
    _btnPin = btnPin;
    pinMode(_btnPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_btnPin), ButtonISR, LOW);
}

bool BTN_controller::GetState()
{
    return ledState;
}

void ButtonISR()
{
    ledState = !ledState;
}