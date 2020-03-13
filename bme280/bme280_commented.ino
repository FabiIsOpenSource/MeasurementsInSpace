/*
    Autor: Fabian Schellenberg
    Date: 03/03/2020
    License: GNU GENERAL PUBLIC LICENSE VERSION 3.0
*/

#include <Wire.h>                             //include the libraries
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)        //define the normal air pressure 

Adafruit_BME280 bme;                          //name the sensor  

void setup() {                                //code that runs once
  Serial.begin(9600);                         //set the comunication speed
  Serial.println("BME280 test");              //print sth

  unsigned status;


  status = bme.begin();                       //print whether the sensor was detected
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor");
    Serial.print("SensorID was: 0x"); 
    Serial.println(bme.sensorID(), 16);
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    while (1);
  }
  Serial.println();                           //print a paragraph
}


void loop() {                                 //code that runs continous
  printValues();                              //points to void printvalues
  delay(1000);                                //delay
}


void printValues() {                          
  Serial.print("Temperature = ");             //print the temperature
  Serial.print(bme.readTemperature());  
  Serial.println(" *C");

  Serial.print("Pressure = ");                //print the pressure

  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");        //print the altitude
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");                //print the humidity
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();                           //print a paragraph
}
