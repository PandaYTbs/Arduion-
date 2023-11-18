const int trigPin = 11;
const int echoPin = 12;
#define LED_PIN 10
// defines variables
long duration;
int distance;
void setup() {
  pinMode(LED_PIN, OUTPUT);
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
  if(distance < 40){
    delay(10 * distance);
    digitalWrite(LED_PIN, HIGH);
    delay(10 * distance);
    digitalWrite(LED_PIN, LOW);
  }
  if(distance > 9){
    digitalWrite(LED_PIN, LOW);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
}
