#include <Communication.h>

int _rxPin = 10;
int _txPin = 11;

SoftwareSerial userInput(_rxPin, _txPin);


Communication::Communication(int rxPin, int txPin)
{
    _rxPin = rxPin;
    _txPin = txPin;
}

int Communication::ReadSerial()
{
    int buff;
    int msg;
    userInput.begin(9600);

    while (userInput.available() > 0)
    {
        buff = userInput.read();
        msg = buff;
    }
    

    return msg;
}