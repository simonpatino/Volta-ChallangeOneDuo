#include <Servo.h>
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

Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFourth;

int pos = 0;   

float temperature, altitude, pressure ; //degree celcius, meters , Hpa 

float preAltitude = 0; //in meters 
unsigned long time = 0;  //in miliseconds
unsigned long preTime = 0;  //in miliseconds

#define ejection_pin 5 //a digital pin 
#define minimumAltitude 30   //in meters

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

  //Wire.begin(A4, A5); // Start I2C communication

//#################### End GENERAL ##############################



//#################### Init SERVOS ##############################

  pinMode(Servo_one, OUTPUT);

  pinMode(Servo_two, OUTPUT);

  pinMode(Servo_one, OUTPUT);

//#################### End SERVOS ###############################


//######################## Init MPU9250 #########################

  mpu.initialize();

  mpu.setFullScaleGyroRange(90);
  
  mpu.setFullScaleAccelRange(90);


//######################### End MPU9250 #########################



//######################### BME280 setup #########################

if (!bme.begin(0x76)) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}
  
   
//######################### End BME280 setup #########################

//######################## Init Servo ################################

    //servoOne.attach(Servo_one);

    //servoTwo.attach(Servo_two);

    //servoThree.attach(Servo_three);

    

//######################## End  Servo #################################

//########################  init ejection system ######################

  pinMode(ejection_pin, HIGH); 

//########################  end ejection system ######################

  }



//------------------------------------------------------------------------------------
void loop(){

//##################### Init BME280 #############################

 temperature = bme.readTemperature();

 //Pressure =  bme.readPressure() / 100.0F;

 altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

 

 Serial.print(Temperature);

 Serial.print(",");

 Serial.print(Altitude);

 Serial.print(",");

 

//####################### End BME280 ############################



//######################## Init MPU9250 #########################

 int16_t ax, ay, az, gx, gy, gz;
 
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

 //########################### Debug #############################

 //Serial.println(gx);
 //Serial.print(",");
 //Serial.print(gy);
 //Serial.print(",");
 //Serial.println(gz);

 //delay(500);

//######################### End MPU9250 #########################


//######################## Init servo test ######################


//for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    servoOne.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);

    
//  }

//   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    servoOne.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//  }


//######################## End servo test ######################


 


//####################### Ejection system #######################


float  deltaAltitude = altitude - preAltitude;

unsigned float  deltaTime = time - pretime;

preAltitude = altitude;

float height_dot = deltaAltitude/deltaTime;

if ( (Altitude > minimumAltitude) &&  ( height_dot > 0) ) {         


  digitalWrite(ejection_pin, HIGH);


   }

//end loop 
}


  
