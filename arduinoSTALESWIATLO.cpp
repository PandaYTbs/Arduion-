const int trigPin = 11;
const int echoPin = 12;
#define LED_PIN_RED 10
#define LED_PIN_YELLOW 9
#define LED_PIN_GREEN 8
// defines variables
long duration;
int distance;
void setup() {
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YELLOW, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
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
  if(distance < 40 && distance > 25 ){
    digitalWrite(LED_PIN_GREEN, HIGH);
    digitalWrite(LED_PIN_RED, LOW);
    digitalWrite(LED_PIN_YELLOW, LOW);
    // delay(10 * distance);
    // digitalWrite(LED_PIN_GREEN, HIGH);
    // delay(10 * distance);
    // digitalWrite(LED_PIN_GREEN, LOW);
  }
  if(distance < 25 && distance > 10 ){
    digitalWrite(LED_PIN_YELLOW, HIGH);
    digitalWrite(LED_PIN_GREEN, LOW);
    digitalWrite(LED_PIN_RED, LOW);
    // delay(10 * distance);
    // digitalWrite(LED_PIN_YELLOW, HIGH);
    // delay(10 * distance);
    // digitalWrite(LED_PIN_YELLOW, LOW);
  }
  if(distance < 10){
    digitalWrite(LED_PIN_RED, HIGH);
    digitalWrite(LED_PIN_YELLOW, LOW);
    digitalWrite(LED_PIN_GREEN, LOW);
    // delay(10 * distance);
    // digitalWrite(LED_PIN_RED, HIGH);
    // delay(10 * distance);
    // digitalWrite(LED_PIN_RED, LOW);
  }

  if(distance > 39){
    digitalWrite(LED_PIN_RED, LOW);
    digitalWrite(LED_PIN_YELLOW, LOW);
    digitalWrite(LED_PIN_GREEN, LOW);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
}
