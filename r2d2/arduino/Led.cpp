#include "Arduino.h"
#include "Led.h"

Led::Led(int redPin, int greenPin, int bluePin)
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
}

void Led::setColor(boolean* color)
{

  digitalWrite(_redPin, color[0]);
  digitalWrite(_greenPin, color[1]);
  digitalWrite(_bluePin, color[2]);
}
