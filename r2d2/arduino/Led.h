/*
  RGB LED
*/
#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led
{
  public:
    Led(int redPin, int greenPin, int bluePin);
    void setColor(int red, int green, int blue);
  private:
    int _redPin;
    int _greenPin;
    int _bluePin;
};

#endif
