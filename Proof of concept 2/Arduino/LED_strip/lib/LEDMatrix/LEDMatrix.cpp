#include <LEDMatrix.h>
#include <Communication.h>
#include <BTN_controller.h>
#include <LED_controller.h>


int rx = 10;
int tx = 11;

Communication comm(rx, tx);
BTN_controller btn_controller(2);
LED_controller led_controller(1);

LEDMatrix::LEDMatrix(int btnPin, int rxPin, int txPin)
{
    _btnPim = btnPin;
    rx = rxPin;
    tx = txPin;
}

void LEDMatrix::Begin()
{
    Serial.begin(9600);
    Serial.println("Led strip started");
}

void LEDMatrix::Update()
{
    int msg = comm.ReadSerial();
    bool ledson = btn_controller.GetState();
    led_controller.TurnOff(ledson);
    led_controller.SetLed(msg);
}
