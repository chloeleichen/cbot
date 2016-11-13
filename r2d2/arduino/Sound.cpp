#include "Arduino.h"
#include "Sound.h"
#include "musical_notes.h"

Sound::Sound(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}


void Sound::beep (float noteFrequency, long noteDuration)
{
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)   
          {   
              digitalWrite(_pin,HIGH); 
              delayMicroseconds(microsecondsPerWave); 
              digitalWrite(_pin,LOW); 
              delayMicroseconds(microsecondsPerWave); 
          } 
}

void Sound::scale()
{
          beep(note_C7,500); //C: play the note C for 500ms
          beep(note_D7,500); //D
          beep(note_E7,500); //E
          beep(note_F7,500); //F
          beep(note_G7,500); //G
          beep(note_A7,500); //A
          beep(note_B7,500); //B
          beep(note_C8,500); //C
}

void Sound::r2D2(){
          beep(note_A7,100); //A
          beep(note_G7,100); //G
          beep(note_E7,100); //E
          beep(note_C7,100); //C
          beep(note_D7,100); //D
          beep(note_B7,100); //B
          beep(note_F7,100); //F
          beep(note_C8,100); //C
          beep(note_A7,100); //A
          beep(note_G7,100); //G
          beep(note_E7,100); //E
          beep(note_C7,100); //C
          beep(note_D7,100); //D
          beep(note_B7,100); //B
          beep(note_F7,100); //F
          beep(note_C8,100); //C
}

void Sound::closeEncounters() {
          beep(note_Bb5,300); //B b
          delay(50);
          beep(note_C6,300); //C
          delay(50);
          beep(note_Ab5,300); //A b
          delay(50);
          beep(note_Ab4,300); //A b
          delay(50);
          beep(note_Eb5,500); //E b
          delay(500);

          beep(note_Bb4,300); //B b
          delay(100);
          beep(note_C5,300); //C
          delay(100);
          beep(note_Ab4,300); //A b
          delay(100);
          beep(note_Ab3,300); //A b
          delay(100);
          beep(note_Eb4,500); //E b
          delay(500);

          beep(note_Bb3,300); //B b
          delay(200);
          beep(note_C4,300); //C
          delay(200);
          beep(note_Ab3,300); //A b
          delay(500);
          beep(note_Ab2,300); //A b
          delay(550);
          beep(note_Eb3,500); //E b
}

void Sound::ariel() {

          beep(note_C6,300); //C
          delay(50);
          beep(note_D6,300); //D
          delay(50);
          beep(note_Eb6,600); //D#
          delay(250);

          beep(note_D6,300); //D
          delay(50);
          beep(note_Eb6,300); //D#
          delay(50);
          beep(note_F6,600); //F
          delay(250);

          beep(note_C6,300); //C
          delay(50);
          beep(note_D6,300); //D
          delay(50);
          beep(note_Eb6,500); //D#
          delay(50);
          beep(note_D6,300); //D
          delay(50);
          beep(note_Eb6,300); //D#
          delay(50);
          beep(note_D6,300); //D
          delay(50);
          beep(note_Eb6,300); //D#
          delay(50);
          beep(note_F6,600); //F
          delay(50);

}


void Sound::chuckle() {
          beep(note_C6,200); //C
          beep(note_E6,200); //E
          beep(note_G6,200); //G
          beep(note_C7,200); //C
          beep(note_C6,200); //C
          delay(50);
          beep(note_C6,200); //C
          beep(note_E6,200); //E
          beep(note_G6,200); //G
          beep(note_C7,200); //C
          beep(note_C6,200); //C
          delay(50);
          beep(note_C6,50); //C
          delay(50);
          beep(note_C6,50); //C
          delay(50);
          beep(note_C6,50); //C
          delay(50);
          beep(note_C6,50); //C
          delay(50);
          beep(note_C6,50); //C
          delay(50);
          beep(note_C6,50); //C
          delay(50);
          beep(note_C6,50); //C

}

void Sound::squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    beep(i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    beep(i,20);
  }
}

void Sound::waka() {
  for (int i=1000; i<3000; i=i*1.05) {
    beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(i,10);
  }
}

void Sound::catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    beep(i,10);
  }
 delay(300);

  for (int i=1000; i<3000; i=i*1.03) {
    beep(i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    beep(i,10);
  }
}

void Sound::ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    beep(i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    beep(i,10);
  }
}

void Sound::uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    beep(i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    beep(i,30);
  }
}

void Sound::laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(i,10);
  }
  delay(50);
}
