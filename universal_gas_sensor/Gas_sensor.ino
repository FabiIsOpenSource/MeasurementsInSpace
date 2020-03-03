/*
    Autor: Fabian Schellenberg
    Date: 03/03/2020
    License: GNU GENERAL PUBLIC LICENSE VERSION 3.0
*/

int led = 8;
int sensor = A0;
int sensorValue = 0;
int sensorThreshold = 500;

void setup() {
  pinMode(pin8, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  sensorValue = analogRead(sensor);
  Serial.println(sensorValue, DEC);
  
  if (sensorValue > sensorThreshold) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }

}
