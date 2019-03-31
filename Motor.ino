int motor1 = 9; //red
int motor2 = 10; //yellow
// defines pins numbers
const int trigPin1 = 3; //checkLeft()
const int echoPin1 = 2; //checkLeft()
const int trigPin2 = 5; //checkRight()
const int echoPin2 = 4; //checkRight()
// defines variables
long duration;
long distanceRight;
long distanceLeft;

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {

  checkRight();
  checkLeft();
  if (distanceRight < 35 && distanceLeft >35)
  {
    turnLeft();
  }
  else if (distanceLeft < 35 && distanceRight >35)
  {
    turnRight();
  }
  else if (distanceLeft <35 && distanceRight <35)
  {
    turnRight();
    turnRight();
  }
  else
  {
    moveForward();
  }

}

void moveForward(){
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  delay(2000);
}

void turnLeft(){
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  delay(1000);
}

void turnRight(){
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  delay(1000);
}

void checkLeft()
{
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distanceLeft= (duration*343.21/2)/10000;
  // Prints the distance on the Serial Monitor
  Serial.print("DistanceLeft: ");
  Serial.println(distanceLeft);
}

void checkRight()
{
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distanceRight= (duration*343.21/2)/10000;
  // Prints the distance on the Serial Monitor
  Serial.print("DistanceRight: ");
  Serial.println(distanceRight);
}
