/*
 * HC-SR0HFS-DC06h example sketch
 */

const int radarOut = 2;
const int radarLed = 6;

void setup() {
  pinMode(radarOut, INPUT);
  pinMode(radarLed, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.print("Radar detection: ");
  Serial.println(digitalRead(radarOut));

  if (digitalRead(radarOut))
    digitalWrite(radarLed, HIGH);
  else
    digitalWrite(radarLed, LOW);
  delay(100);
}
