#include <Wire.h>

const int MPU_ADDR = 0x68;
const double raw_to_acc = 16384 / 9.8;
const double rad_to_deg = 180 / 3.141592;

int16_t acX, acY, acZ;
double acX_cal, acY_cal, acZ_cal;

double phi, theta;

void setup() {
  setting();

  Serial.begin(115200);
}

void loop() {
  getData();

  acX_cal = (acX) / raw_to_acc;
  acY_cal = (acY) / raw_to_acc;
  acZ_cal = (acZ) / raw_to_acc;

  phi = atan(acY / sqrt(pow(acX, 2) + pow(acZ, 2))) * rad_to_deg;
  theta = atan(-acX / sqrt(pow(acY, 2) + pow(acZ, 2))) * rad_to_deg;

//  Serial.print("X축 가속도 : "); Serial.print(acX_cal); Serial.print("\t");
//  Serial.print("Y축 가속도 : "); Serial.print(acY_cal); Serial.print("\t");
//  Serial.print("Z축 가속도 : "); Serial.println(acZ_cal);

  Serial.print("phi : "); Serial.print(phi); Serial.print("\t");
  Serial.print("theta : "); Serial.println(theta);


}

void setting() {
   Wire.begin();
   Wire.beginTransmission(MPU_ADDR);
   Wire.write(0x6B);
   Wire.write(0);
   Wire.endTransmission();
}

void getData() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6);
  acX = Wire.read() << 8 | Wire.read();
  acY = Wire.read() << 8 | Wire.read();
  acZ = Wire.read() << 8 | Wire.read();
  Wire.endTransmission();

  delay(2);
}
