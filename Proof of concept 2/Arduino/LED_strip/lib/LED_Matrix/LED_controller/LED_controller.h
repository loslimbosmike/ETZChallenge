#ifndef LED_controller_h
#define LED_controller_h

#include <Arduino.h>
#include <LedStrip_info.h>
#include <FastLED.h>
#define NUMROWS ((NUMlEDS) / (COLUMNS))

class LED_controller
{
private:
    int candleRow;
    int candleCol;
    bool turnedOff = true;
    CRGBArray<NUMlEDS> leds;
    int numLed(int row, int col);
public:
    LED_controller(int connected);
    void SetLed(int msg);
    void TurnOff(bool btnState);
};
 
#endif
