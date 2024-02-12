#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

int angleRoll = 75, directionRoll = -5;
float timedRoll = 0;
bool directionejection, angleejection = false; 
const long interval = 1000;
unsigned long previousMillis = 0;

float roll, changedRoll;



void setup() {
  Serial.begin(9600);
  while (!Serial)
    delay(10);

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);   // Ranges of 2, 4, 8, 16 G
  // mpu.setGyroRange(MPU6050_RANGE_500_DEG);        // Ranges of 250, 500, 1000, 2000 dps
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);     // Ranges of 5, 10, 21, 44, 94, 184, 260 Hz

  delay(100);
}


void loop() {
  unsigned long currentMillis = millis();

  // If Gyro and Temp are useful
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  roll = atan2(accel.acceleration.y, accel.acceleration.z) * (180/PI);
  // float pitch = atan2((- accel.acceleration.x) , sqrt(accel.acceleration.y * accel.acceleration.y + accel.acceleration.z * accel.acceleration.z)) * (180/PI);

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    timedRoll = roll;
  }

  // Algorithm for angle change in time controlled ejection
  changedRoll = abs(roll - timedRoll);
  if (changedRoll > angleRoll && angleejection == false) {
    // angleEjection = true;
    Serial.println("Eyectado por diferencia de angulo");
    delay(10);    // If not used serial monitor blocks
  }

  // Algorithm for rocket direction controlled ejection
  if (roll < directionRoll && directionejection == false) {
    // directionEjection = true;
    Serial.println("Eyectado porque esta mierda apunta pa abajo");
    delay(10);    // If not used serial monitor blocks
  }
}