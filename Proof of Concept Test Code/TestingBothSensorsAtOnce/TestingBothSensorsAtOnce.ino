/*
 * Testing Both Sensors
 */

//Quick Config
const int minDistanceUltra = 10;
const int maxDistanceUltra = 50;

//define Ultrasonic vars
const int trigPin = 11;
const int echoPin = 12;
const int ultraLed = 7;
float duration, distance;
bool ultraDetection = 0;

//define Radar vars
const int radarOut = 2;
const int radarLed = 6;
bool radarDetection = 0;

void setup() {

  //init ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ultraLed, OUTPUT);

  //init radar
  pinMode(radarOut, INPUT);
  pinMode(radarLed, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {

  //Ultrasonic Pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.029)/2; // This calculation is inaccurate!

  //Radar pulses automatically. 

  //Ultrasonic read info
  if(distance < maxDistanceUltra && distance > minDistanceUltra)
    ultraDetection = true;
  else
    ultraDetection = false;
  
  //Radar read info
  if(digitalRead(radarOut))
    radarDetection = true;
  else
    radarDetection = false;

  //Output to LEDs

  //Output to ultra LED
  if (ultraDetection)
    digitalWrite(ultraLed, HIGH);
  else
    digitalWrite(ultraLed, LOW);

  //Output to radar LED
  if (radarDetection)
    digitalWrite(radarLed, HIGH);
  else
    digitalWrite(radarLed, LOW);

  //Output to serial
  Serial.print("Ultrasonic Detection:  ");
  Serial.println(ultraDetection);
  Serial.print("Ultrasonic Distance:  ");
  Serial.println(distance);
  Serial.print("Radar Detection:  ");
  Serial.println(radarDetection);
  delay(1000);
}
