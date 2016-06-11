// Connect and move a single servo
// Chloe Chen
// 11 June 2016

#include <Servo.h>

Servo servo0;

void setup() {
  servo0.attach(2);
  servo0.write(180);

}

void loop() {
  delay(1000);
  servo0.write(90);
  delay(1000);
  servo0.write(180);
  delay(1000);
}
