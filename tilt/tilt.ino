const int SensorPin = 0;     // the number of the Sensor pin
 
// variables will change:
int SensorState = 0;         // variable for reading the Sensor status
 
void setup() {
  Serial.begin(9600);     
}
 
void loop(){
  // read the state of the Sensor value:
  SensorState = analogRead(SensorPin);
  Serial.print(SensorState);
  Serial.print("\n");
  delay(1000);
}
