void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop() {

  int data = analogRead(A0);

  float analog_volt = data * (5 / 1023.0);

  Serial.println(analog_volt);

}
