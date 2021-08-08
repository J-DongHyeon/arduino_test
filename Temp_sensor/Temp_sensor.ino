void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
  

}

void loop() {
  int data = analogRead(A0);

  float analog_volt = data * (1.1 / 1023);

  float analog_temp = analog_volt * (110 / 1.1);

  Serial.println(String(analog_temp) + " C");
}
