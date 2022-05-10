#include <LED_controller.h>

LED_controller::LED_controller(int connected)
{
    FastLED.addLeds<STRIP_TYPE, LED_DATA_PIN, COLOR_ORDER>(leds, NUMlEDS);
    FastLED.setBrightness(59);
    candleRow = 0;
    candleCol = 0;
}

void LED_controller::TurnOff(bool btnState){
    turnedOff = !btnState;
}

int LED_controller::numLed(int row, int col)
{
    int ledNum = 0;

    switch (row)
    {
    case 0:
        break;
    case 1:
        ledNum +=10;
        break;
    case 2:
        ledNum +=20;
        break;
    case 3:
        ledNum += 30;
        break;
    case 4:
        ledNum += 40;
        break;
    case 5:
        ledNum += 50;
        break;
    case 6:
        ledNum += 60;
        break;
    case 7:
        ledNum += 70;
        break;
    case 8:
        ledNum += 80;
        break;
    case 9:
        ledNum += 90;
        break;
    case 10:
        ledNum += 100;
        break;
    }

    ledNum += col;

    return ledNum;
}

void LED_controller::SetLed(int msg)
{
    if (!turnedOff){
        int columnsNeeded;
        int repeatTimes;
        int col = 0;
        int led;
        CRGB color;
        CRGB color1; 
        CRGB color2; 
        CRGB color3; 
        CRGB color4; 

        switch(msg)
        {
            case 0:
                fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                columnsNeeded = 5;
                repeatTimes = COLUMNS / columnsNeeded;
                color = CRGB(255, 0, 0);
                for (int i = 0; i < repeatTimes; i++)
                {
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    led = numLed(3,col);
                    leds[led] = color;
                    led = numLed(4,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    FastLED.show();
                }
                break;
            case 1:
                fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                columnsNeeded = 5;
                repeatTimes = COLUMNS / columnsNeeded;
                color = CRGB(0, 255, 0);
                for (int i = 0; i < repeatTimes; i++)
                {
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    led = numLed(3,col);
                    leds[led] = color;
                    led = numLed(4,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    FastLED.show();
                }
                break;
            case 2:
                fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                columnsNeeded = 8;
                repeatTimes = COLUMNS / columnsNeeded;
                color = CRGB(255, 255, 0);
                for (int i = 0; i < repeatTimes; i++)
                {
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(5,col);
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(5,col);
                    col++;
                    led = numLed(5,col);
                    col++;
                    led = numLed(1,col);
                    led = numLed(5,col);
                    col++;
                    led = numLed(1,col);
                    led = numLed(5,col);
                    col++;
                    led = numLed(1,col);
                    col++;
                    FastLED.show();
                }
                break;
            case 3:
                fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                columnsNeeded = 5;
                repeatTimes = COLUMNS / columnsNeeded;
                color1 = CRGB(255, 0, 0);
                color2 = CRGB(0, 255, 0);
                color3 = CRGB(255, 255, 0);
                color4 = CRGB(255, 165, 0);
                for (int i = 0; i < repeatTimes; i++)
                {
                    led = numLed(1,col);
                    leds[led] = color1;
                    led = numLed(2,col);
                    leds[led] = color1;
                    led = numLed(3,col);
                    leds[led] = color1;
                    led = numLed(4,col);
                    leds[led] = color1;
                    led = numLed(5,col);
                    leds[led] = color1;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color1;
                    led = numLed(2,col);
                    leds[led] = color2;
                    led = numLed(3,col);
                    leds[led] = color3;
                    led = numLed(4,col);
                    leds[led] = color4;
                    led = numLed(5,col);
                    leds[led] = color1;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color1;
                    led = numLed(2,col);
                    leds[led] = color2;
                    led = numLed(3,col);
                    leds[led] = color3;
                    led = numLed(4,col);
                    leds[led] = color4;
                    led = numLed(5,col);
                    leds[led] = color1;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color1;
                    led = numLed(2,col);
                    leds[led] = color2;
                    led = numLed(3,col);
                    leds[led] = color3;
                    led = numLed(4,col);
                    leds[led] = color4;
                    led = numLed(5,col);
                    leds[led] = color1;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color1;
                    led = numLed(2,col);
                    leds[led] = color1;
                    led = numLed(3,col);
                    leds[led] = color1;
                    led = numLed(4,col);
                    leds[led] = color1;
                    led = numLed(5,col);
                    leds[led] = color1;
                    col++;
                    FastLED.show();
                }
                break;
            case 4:
                fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                columnsNeeded = 10;
                repeatTimes = COLUMNS / columnsNeeded;
                color = CRGB(57, 255, 20);
                for (int i = 0; i < repeatTimes; i++)
                {
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(0,col);
                    leds[led] = color;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    col += 3;
                    led = numLed(4,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(2,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(4,col);
                    leds[led] = color;
                    col++;
                    FastLED.show();
                }
                break;
            case 5:
                fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                columnsNeeded = 10;
                repeatTimes = COLUMNS / columnsNeeded;
                color = CRGB(186, 56, 13);
                for (int i = 0; i < repeatTimes; i++)
                {
                    led = numLed(2,col);
                    leds[led] = color;
                    col++;
                    led = numLed(4,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(3,col);
                    leds[led] = color;
                    led = numLed(4,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(3,col);
                    leds[led] = color;
                    led = numLed(4,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(1,col);
                    leds[led] = color;
                    led = numLed(3,col);
                    leds[led] = color;
                    led = numLed(4,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    led = numLed(4,col);
                    leds[led] = color;
                    led = numLed(5,col);
                    leds[led] = color;
                    col++;
                    FastLED.show();
                }
                break;
            case 6:
                long currTime = millis();
                long prvTime;
                const int eventTime = 250;
                FastLED.setBrightness(45);
                color = CRGB(186, 56, 13);
                if ((candleRow == 0 && candleCol == 0) || (candleRow == NUMROWS && candleCol == COLUMNS))
                {
                    fill_solid(leds, NUMlEDS, CRGB(0, 0, 0));
                    FastLED.show();
                    candleCol = 0;
                    candleRow = 0;
                }
                if (currTime - prvTime >= eventTime)
                {
                    candleRow++;
                    if (candleRow >= NUMROWS)
                    {
                        candleCol++;
                    }
                }
                for (int i = 0; i <= candleRow; i++)
                {
                    led = numLed(i,candleCol);
                    leds[led] = color;
                    FastLED.show();
                }
                break;
        }
    }
    else
    {
        CRGB black = CRGB(0, 0, 0);
        for (int i = 0; i < NUMlEDS; i++)
        {
            leds[i] = black;
            FastLED.show();
        }
            
    }
}