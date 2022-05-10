#ifndef Communication_h
#define Communication_h

#include <Arduino.h>
#include <SoftwareSerial.h>

#define startChar (';')
#define endChar ('#')
#define buffLeng 32

class Communication
{
private:

public:
    Communication(int rxPin, int txPin);
    int ReadSerial();
};

#endif