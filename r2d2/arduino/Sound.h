#ifndef Sound_h
#define Sound_h

#include "Arduino.h"

class Sound
{
public:
  Sound(int pin);
  void scale();
  void r2D2();
  void closeEncounters();
  void ariel();
  void chuckle();
  void squeak();
  void waka();
  void catcall();
  void ohhh();
  void uhoh();
  void laugh();
private:
  int _pin;
  void beep(float noteFrequency, long noteDuration);
};

#endif
