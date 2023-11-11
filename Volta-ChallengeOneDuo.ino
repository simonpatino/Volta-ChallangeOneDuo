
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <MPU6050.h>

//########################## GENERAL ###########################

#define Servo_one 9
#define Servo_two 6
#define Servo_three 5
#define SS 10
#define MOSI 11
#define MISO 12
#define SCL A5
#define SDA A4
#define SCK 13

//####################### End General ##########################


//######################### Init BME280 ########################

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

//####################### End BME280 ############################



//######################## Init MPU9250 #########################

  MPU6050 mpu;

//######################### End MPU9250 #########################


//------------------------------------------------------------------------------------
void setup(){

//#################### Init GENERAL #############################

  Serial.begin(9600);

   Wire.begin();

//#################### End GENERAL ##############################



//#################### Init SERVOS ##############################

  pinMode(Servo_one, OUTPUT);
  pinMode(Servo_two, OUTPUT);
  pinMode(Servo_one, OUTPUT);

//#################### End SERVOS ###############################


//######################## Init MPU9250 #########################

  mpu.initialize();

  mpu.setFullScaleGyroRange(0);
  
  mpu.setFullScaleAccelRange(0);


//######################### End MPU9250 #########################
  
   
  }


//------------------------------------------------------------------------------------
void loop(){

  bme.readTemperature();


//##################### Init BME280 #############################

bme.readTemperature();

bme.readPressure() / 100.0F;

bme.readAltitude(SEALEVELPRESSURE_HPA);

//####################### End BME280 ############################



//######################## Init MPU9250 #########################

 int16_t ax, ay, az, gx, gy, gz;
 
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

//######################### End MPU9250 #########################



  
    
  }
