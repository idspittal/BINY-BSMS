/*
 * HC-SR04 example sketch
 */

//Quick Config
const int minDistanceUltra = 10;
const int maxDistanceUltra = 50;

const int trigPin = 11;
const int echoPin = 12;
const int ultraLed = 7;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ultraLed, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.029)/2; // This calculation is inaccurate!
  if(distance < maxDistanceUltra && distance > minDistanceUltra)
    digitalWrite(ultraLed, HIGH);
  else
    digitalWrite(ultraLed, LOW);
  Serial.print("Ultrasonic Detection: ");
  Serial.println(distance);
  delay(100);
}
