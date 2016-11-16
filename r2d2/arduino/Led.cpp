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

void Led::setColor(int red, int green, int blue)
{

  analogWrite(_redPin, red);
  analogWrite(_greenPin, green);
  analogWrite(_bluePin, blue);
}
