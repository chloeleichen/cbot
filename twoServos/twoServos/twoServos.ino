// Connect and move two servo, super simple movement at this stage
// Chloe Chen
// 11 June 2016

#include <Servo.h>

Servo frontServo;
Servo rearServo;

void setup() {
  frontServo.attach(2);
  rearServo.attach(3);
  frontServo.write(90);
  rearServo.write(90);
}

void loop() {
  delay(1000);
  frontServo.write(180);
  rearServo.write(180);
  delay(1000);
  frontServo.write(90);
  rearServo.write(90);
}
