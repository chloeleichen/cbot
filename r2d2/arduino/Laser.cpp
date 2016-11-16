#include "Arduino.h"
#include "Laser.h"

Laser::Laser(int laserPin)
{
  pinMode(laserPin, OUTPUT);
  _laserPin = laserPin;
}

void Laser::on()
{
  digitalWrite(_laserPin, HIGH);
}

void Laser::off()
{
  digitalWrite(_laserPin, LOW);
}
