
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//####### GENERAL ########

#define Servo_one 9
#define Servo_two 6
#define Servo_three 5
#define SS 10
#define MOSI 11
#define MISO 12
#define SCL A5
#define SDA A4
#define SCK 13

//########################


//##### BME280 #####

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

//######End BME280########





void setup(){

//#################### Init GENERAL #######################

  Serial.begin(9600);



//#################### End GENERAL #######################



//#################### Init SERVOS ########################

  pinMode(Servo_one, OUTPUT);
  pinMode(Servo_two, OUTPUT);
  pinMode(Servo_one, OUTPUT);

//#################### End SERVOS ########################
  
   
  }

void loop(){

  bme.readTemperature();


//####### BME280 ############

bme.readTemperature();

bme.readPressure() / 100.0F ;

bme.readAltitude(SEALEVELPRESSURE_HPA);

//######End BME280############



//######## MPU 9250 ##########







//######## End MPU 9250 ######
  
    
  }
