#include <NewPing.h>
#include "Sound.h"
//#include "Led.h"
#include "Laser.h"
#include <Servo.h>
#include <LiquidCrystal.h>


char response = 'a';
// responseCode


int speakerPin = 8;
int laserPin = 13;
int leftArmPin = 9;
int  rightArmPin = 10;
int trigPin = 7;
int echoPin = 6;

Servo leftArm;
Servo rightArm;
LiquidCrystal lcd(12,11,5,4,3,2);



Sound sound(speakerPin);
Laser laser(laserPin);
NewPing sonar(trigPin, echoPin, 500);

void greeting();
void danger();
void catcall();
void rest();


void setup()
{
      Serial.begin(9600);
      leftArm.attach(leftArmPin);
      rightArm.attach(rightArmPin);
      rightArm.write(20);
      leftArm.write(20);
      delay(1000);
      lcd.begin(16, 2);
      // Print a message to the LCD.
      lcd.print("hello, world!");
}

void loop()
{ 
  if (Serial.available()) {
    response = Serial.read();
  }
  switch(response) {
     case 'a'  :
        return;
     case 'b'  :
        greeting();
        rest();
        break;
     case 'c' :
        danger();
        break;
     case 'd':
        catcall();
        break;
     case 'e':
         printSerialInput();
        break;
     default :
        return;
  }
};


void rest(){
  laser.off();
  sound.pause();
  response = 'a';
  return;
}

void greeting(){
  lcd.clear();
  lcd.print("hello to you too");
  sound.ohhh();
  leftArm.write(10);
  delay(1000);
  leftArm.write(70);
  delay(1000);
}


void danger(){
  int distance = sonar.ping_cm();
  if(distance < 20){
    lcd.clear();
    rightArm.write(90);
    laser.on();
    lcd.setCursor(0, 0);
    lcd.print("distance:");
    lcd.print(distance);
    lcd.setCursor(0, 1);
    lcd.println("shooting target");
    sound.r2D2();
  } else {
    lcd.clear();
    laser.off();
    rightArm.write(10);
    lcd.setCursor(0, 0);
    lcd.print("do no approach!");
    Serial.println(distance);
    sound.closeEncounters();
  }
  delay(200);
}


void catcall(){
  lcd.clear();
  sound.catcall();
  lcd.print("hi there");
  delay(1000);
}


void printSerialInput(){
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    lcd.setCursor(0, 0);
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}


