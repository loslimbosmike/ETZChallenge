#ifndef LEDMatrix_h
#define LEDMatrix_h

#include <Arduino.h>


class LEDMatrix
{
private:
    int _btnPim;
    bool ledState;
public:
    LEDMatrix(int btnPin, int rxPin, int txPin);
    void Begin();
    void Update();
};

#endif
