/*
-------------------------------------------------------
Project : Arduino Ultrasonic Distance Test
-------------------------------------------------------

Description:
This project demonstrates how to measure distance using
an HC-SR04 ultrasonic sensor with Arduino.

The sensor sends an ultrasonic sound wave and waits
for the echo to return. Arduino calculates the distance
based on the travel time of the sound wave.

The measured distance will be displayed in the
Serial Monitor.

-------------------------------------------------------
Components:
- 1x Arduino Uno / Arduino Nano
- 1x HC-SR04 Ultrasonic Sensor
- Jumper wires
- Breadboard (optional)

-------------------------------------------------------
Wiring:

HC-SR04        Arduino
-----------------------
VCC      ->    5V
GND      ->    GND
TRIG     ->    D9
ECHO     ->    D10

-------------------------------------------------------
*/

const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Arduino Ultrasonic Distance Test");
}

void loop() {

  // Clear the TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}