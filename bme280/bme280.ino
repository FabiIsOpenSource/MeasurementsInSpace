/*
    Autor: Fabian Schellenberg
    Date: 03/03/2020
    License: GNU GENERAL PUBLIC LICENSE VERSION 3.0
*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

unsigned long delayTime = 1000;

void setup() {
  Serial.begin(9600);
  Serial.println("BME280 test");

  unsigned status;


  status = bme.begin();
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    Serial.print("SensorID was: 0x"); 
    Serial.println(bme.sensorID(), 16);
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    while (1);
  }
  Serial.println();
}


void loop() {
  printValues();
  delay(delayTime);
}


void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");

  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}
