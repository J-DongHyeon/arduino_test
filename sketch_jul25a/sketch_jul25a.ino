unsigned int data = 0x03;

void setup() {

 for(int i=8; i<=11; i++) {
 pinMode(i, OUTPUT);
 }
 
}

void loop() {
  if (data & 0x01) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
  if (data & 0x02) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
  if (data & 0x04) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  if (data & 0x08) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
delay(500);

}
