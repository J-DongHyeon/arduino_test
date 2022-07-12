#include <Wire.h>

int MPU = 0x68;

int acx, acy, acz, tmp, gyx, gyy, gyz;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);
  Wire.write(0b00001000);
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


  Serial.print(acx);
  Serial.print(" ");
  Serial.print(acy);
  Serial.print(" ");
  Serial.print(acz);
  
  Serial.print(" ");
  Serial.print(tmp);

  Serial.print(" ");
  Serial.print(gyx);
  Serial.print(" ");
  Serial.print(gyy);
  Serial.print(" ");
  Serial.println(gyz);

  Wire.endTransmission();

  delay(2);
  

  

}
