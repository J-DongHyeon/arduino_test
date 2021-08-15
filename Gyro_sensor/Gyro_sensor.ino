#include <Wire.h>

int MPU = 0x68;

int acx, acy, acz, tmp, gyx, gyy, gyz;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
  Serial.begin(9600);

}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14);

  acx = Wire.read() << 8 | Wire.read();
  acy = Wire.read() << 8 | Wire.read();
  acz = Wire.read() << 8 | Wire.read();
  tmp = Wire.read() << 8 | Wire.read();
  gyx = Wire.read() << 8 | Wire.read();
  gyy = Wire.read() << 8 | Wire.read();
  gyz = Wire.read() << 8 | Wire.read();

  acx = 

  Serial.print("ACX = ");
  Serial.print(acx);
  Serial.print(" ACY = ");
  Serial.print(acy);
  Serial.print(" ACZ = ");
  Serial.print(acz);
  
  Serial.print("TMP = ");
  Serial.print(tmp);

  Serial.print("GYX = ");
  Serial.print(gyx);
  Serial.print(" GYY = ");
  Serial.print(gyy);
  Serial.print(" GYZ = ");
  Serial.println(gyz);

  Wire.endTransmission();

  delay(2000);
  

  

}
