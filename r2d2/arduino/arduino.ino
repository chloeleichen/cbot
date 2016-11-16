#include <NewPing.h>
#include "Sound.h"
#include "Led.h"
#include "Laser.h"
#include <Servo.h>

int speakerPin = 2; // speaker connected to digital pin 9
int laserPin = 13;
int servoPin = 3;
int leftArmPin = 6;
int rightArmPin = 5;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int noisePin = A0;
int touchPin = A1;

Servo servo;
Servo leftArm;
Servo rightArm;


Sound sound(speakerPin);
Laser laser(laserPin);
Led led(redPin, greenPin, bluePin);

//NewPing sonar(trigPin, echoPin, 200);

void setup()
{
      Serial.begin(9600);
      servo.attach(servoPin);
      leftArm.attach(leftArmPin);
      rightArm.attach(rightArmPin);
      servo.write(0);
      rightArm.write(0);
      leftArm.write(0);
      
      
}

void loop()
{ 
  rightArm.write(180);
  leftArm.write(90);
  delay(500);
  rightArm.write(0);
  leftArm.write(0);
  delay(500);
  servo.write(90);
  laser.on();  
  led.setColor(100, 100, 100);  
  sound.r2D2();
};
