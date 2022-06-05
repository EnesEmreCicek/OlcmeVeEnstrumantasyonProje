
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;
float temp;
float accX, accY, accZ;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  temp = mpu6050.getTemp();
  temp = temp * 100;
  accX = mpu6050.getAccX();
  accX = accX * 100;
  accY = mpu6050.getAccY();
  accY = accY * 100;
  accZ = mpu6050.getAccZ();
  accZ = accZ * 100;
  
  if(millis() - timer > 10){
    Serial.println((String)"T" + temp + "X" + accX + "Y" + accY + "Z" + accZ);  
    timer = millis();
    
  }

}
