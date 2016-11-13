#include <NewPing.h>
#include "Sound.h"

int speakerPin = 9; // speaker connected to digital pin 9
Sound sound(speakerPin);
NewPing sonar(12, 11, 200);

void setup()
{
      Serial.begin(9600);
}

void loop()
{
    sound.laugh();
    delay(3000);
};
