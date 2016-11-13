const int a_direction = 12;
const int a_break = 9;
const int a_speed = 3;
const int a_current_sensing = 0;

const int b_direction = 13;
const int b_break = 8;
const int b_speed = 11;
const int b_current_sensing = 1;

const int trigPin = 4;
const int echoPin = 5;
long int duration;
long distanceFront = 0;
int startAvoidanceDistance = 20;


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


void moveForward(int speed)
{
   //Motor A forward @ full speed
  digitalWrite(a_direction, HIGH); //Establishes forward direction of Channel A
  digitalWrite(a_break, LOW);   //Disengage the Brake for Channel A
  analogWrite(a_speed, speed);   //Spins the motor on Channel A at full speed

  //Motor B backward @ full speed
  digitalWrite(b_direction, HIGH);  //Establishes forward direction of Channel B
  digitalWrite(b_break, LOW);   //Disengage the Brake for Channel B
  analogWrite(b_speed, speed);    //Spins the motor on Channel B full speed
  delay(2000);
}

void moveBackward(int speed)
{

  //Motor A backward @ full speed
  digitalWrite(a_direction, LOW);  //Establishes backward direction of Channel A
  digitalWrite(a_break, LOW);   //Disengage the Brake for Channel A
  analogWrite(a_speed, speed);    //Spins the motor on Channel A at full
  
  //Motor B backward @ full speed
  digitalWrite(b_direction, LOW); //Establishes backward direction of Channel B
  digitalWrite(b_break, LOW);   //Disengage the Brake for Channel B
  analogWrite(b_speed, speed);   //Spins the motor on Channel B at full speed
  delay(2000);
}


void moveBackRight(int speed)
{
  //Motor A backward @ full speed
  digitalWrite(a_direction, LOW);  //Establishes backward direction of Channel A
  digitalWrite(a_break, LOW);   //Disengage the Brake for Channel A
  analogWrite(a_speed, speed);    //Spins the motor on Channel A at full
  
  //Motor B backward @ half speed
  digitalWrite(b_direction, LOW); //Establishes forward direction of Channel B
  digitalWrite(b_break, LOW);   //Disengage the Brake for Channel B
  analogWrite(b_speed, speed/2);   //Spins the motor on Channel B at full speed
}

void moveTurnLeft(int speed)
{
   //Motor A forward @ half speed
  digitalWrite(a_direction, HIGH);  //Establishes backward direction of Channel A
  digitalWrite(a_break, LOW);   //Disengage the Brake for Channel A
  analogWrite(a_speed, speed/2);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(b_direction, HIGH); //Establishes forward direction of Channel B
  digitalWrite(b_break, LOW);   //Disengage the Brake for Channel B
  analogWrite(b_speed, speed);   //Spins the motor on Channel B at full speed
  
}

void stop(void)
{
  digitalWrite(a_break, HIGH);  //Engage the Brake for Channel A
  digitalWrite(b_break, HIGH);  //Engage the Brake for Channel B
}


void setup() {
  Serial.begin(9600);
  
  //Setup Channel A
  pinMode(a_direction, OUTPUT); //Initiates Motor Channel A pin
  pinMode(a_break, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(b_direction, OUTPUT); //Initiates Motor Channel A pin
  pinMode(b_break, OUTPUT);  //Initiates Brake Channel A pin
}

void loop(){
  moveForward(250);
  delay(2000);
}


