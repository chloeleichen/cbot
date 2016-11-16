/*
  Laser
*/
#ifndef Laser_h
#define Laser_h

#include "Arduino.h"

class Laser
{
  public:
    Laser(int laserPin);
    void on();
    void off();
  private:
    int _laserPin;
};

#endif
