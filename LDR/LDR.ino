void setup() {
  Serial.begin(9600);
  

}

void loop() {
  int data = analogRead(A0);

  if (data < 500) {
    Serial.println("LIGHT : VERY LOW");
  } else if (data < 600) {
    Serial.println("LIGHT : LOW");
  } else if (data < 850) {
    Serial.println("LIGHT : HIGH");
  } else if (data <= 1023) {
    Serial.println("LIGHT : VERY HIGH");
  }

}
