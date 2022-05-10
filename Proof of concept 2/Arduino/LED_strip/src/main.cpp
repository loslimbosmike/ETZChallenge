#include <Arduino.h>
#include <LEDMatrix.h>

LEDMatrix ledmatrix(2,10,11);

// To make the LED strip work you have to fill in some information in the #define lines in the ../lib/LEDMatrix/LedStrip_info.h file.
// First in #define NUMLEDS you have to put in the number of leds that you have. (To get number of leds you count each individual led in the led strip)
// Second in #define COLUMNS you have to put in the number of column that your matrix has.
// Third in #define LED_DATA_PIN you have to put in the number of the pin on the Arduino that the led strip is connected to.
// This setup has to be done this was because the program needs constants to run.
// The rest of the setup is done by changing the values in the LEDMatrix constructor.
// The RXpin is by default pin 10 and the TXpin is by default pin 11

void setup (){
  ledmatrix.Begin();
}

void loop (){
  ledmatrix.Update();
}