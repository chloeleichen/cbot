#include <NewPing.h>
#include "Sound.h"
//#include "Led.h"
#include "Laser.h"
#include <Servo.h>
#include <LiquidCrystal.h>


char response = 'c';
// responseCode


int speakerPin = 2;
int laserPin = 3;
int leftArmPin = 4;
int rightArmPin = 5;
int trigPin = 6;
int echoPin = 7;

Servo leftArm;
Servo rightArm;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


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
      rightArm.write(0);
      leftArm.write(0);
      lcd.begin(16, 2);
      laser.off();
      // Print a message to the LCD.
      lcd.print("hi, I am R2!");
}

void loop()
{
  Serial.println(response);
  Serial.println('a');
  switch(response) {
     case 'a'  :
        rest();
        break;
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
     default :
     return;
  }
};


void rest(){
  lcd.clear();
  rightArm.write(0);
  leftArm.write(0);
  laser.off();
  sound.pause();
  response = 'a';
  return;
}

void greeting(){
  lcd.clear();
  rightArm.write(90);
  lcd.print("hi, how are you?");
  sound.ohhh();
  delay(1000);
}


void danger(){
  lcd.clear();
  laser.off();
  int distance = sonar.ping_cm();
  rightArm.write(90);
  leftArm.write(90);
  lcd.setCursor(0, 0);
  lcd.print("do no approach!");
  
  sound.closeEncounters();
  if(distance < 100){
    lcd.clear();
    laser.on();
    lcd.setCursor(0, 0);
    lcd.print("distance:");
    lcd.print(distance);
    lcd.setCursor(0, 1);
    lcd.println("shooting!");
    sound.ariel();
  }
  delay(200);
}


void catcall(){
  lcd.clear();
  sound.catcall();
  lcd.print("hi there");
  delay(1000);
}
