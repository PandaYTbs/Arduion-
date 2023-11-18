const int trigPin = 11;
const int echoPin = 12;
#include <Servo.h>
// defines variables
Servo myservo;
int pos = 0;
int maxpos = -40;
long duration;
int distance;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  pos = maxpos - distance;
  if(distance <= 50){
    myservo.write(pos);
  }
  if(distance > 50){
    myservo.write(40);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
}
