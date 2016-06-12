// A mini mia robot
// Chloe Chen
// 12 June 2016

#include <Servo.h>

const int trigPin = 4;
const int echoPin = 5;
const int frontPin = 2;
const int rearPin = 3;

Servo frontServo;
Servo rearServo;

int centerPos = 90;
int frontRightUp = 70;
int frontLeftUp = 110;
int backRightForward = 70;
int backLeftForward = 110;

int centerTurnPos = 81;
int frontTurnRightUp = 63;
int frontTurnLeftUp = 117;
int backTurnRightForward = 66;
int backTurnLeftForward = 96;

// ping 

long int duration;
long distanceFront = 0;
int startAvoidanceDistance = 20;


int delayLong = 125;
int delayShort = 65;
int walkSpeed = 150;

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long distanceCm(){
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  return microsecondsToCentimeters(duration);
}

void center(){
  frontServo.write(centerPos);
  rearServo.write(centerPos);
}

void moveForward()
{
  frontServo.write(frontRightUp);
  rearServo.write(backLeftForward);
  delay(delayLong);

  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(delayShort);

  frontServo.write(frontLeftUp);
  rearServo.write(backRightForward);
  delay(delayLong);

  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(delayShort);
  
}

void moveBackward(){
  frontServo.write(frontRightUp);
  rearServo.write(backRightForward);
  delay(delayLong);

  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(delayShort);

  frontServo.write(frontLeftUp);
  rearServo.write(backLeftForward);
  delay(delayLong);

  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(delayShort);
}

void moveBackRight(){
  frontServo.write(frontRightUp);
  rearServo.write(backRightForward - 6);
  delay(delayLong);

  frontServo.write(centerPos);
  rearServo.write(centerPos - 6);
  delay(delayShort);

  frontServo.write(frontLeftUp + 9);
  rearServo.write(backLeftForward - 6);
  delay(delayLong);

  frontServo.write(centerPos);
  rearServo.write(centerPos);
  delay(delayShort);
}

void moveTurnLeft()
{
  frontServo.write(frontTurnRightUp);
  rearServo.write(backTurnLeftForward);
  delay(delayLong);

  frontServo.write(centerTurnPos);
  rearServo.write(centerTurnPos);
  delay(delayShort);

  frontServo.write(frontTurnLeftUp);
  rearServo.write(backTurnRightForward);
  delay(delayLong);

  frontServo.write(centerTurnPos);
  rearServo.write(centerTurnPos);
  delay(delayShort);
  
}


void setup() {
  frontServo.attach(frontPin);
  rearServo.attach(rearPin);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distanceFront = distanceCm();
  Serial.print(distanceFront);
  Serial.println();
  if (distanceFront > 1){
    if(distanceFront < startAvoidanceDistance){
      for(int i = 0; i <= 8; i ++){
        moveBackRight();
        delay(walkSpeed);
      }
      for(int i = 0; i <= 10; i++){
        moveTurnLeft();
        delay(walkSpeed);
      }
    }else{
      moveForward();
      delay(walkSpeed);
    }
    
  }
  moveForward();
  delay(walkSpeed);
}



