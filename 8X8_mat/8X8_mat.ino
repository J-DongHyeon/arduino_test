unsigned int data [] = {0x00, 0x3C, 0x42, 0x04, 0x08, 0x10, 0x20, 0x7E};

void setup() {
  for(int i=0; i<=15; i++) {
  pinMode(i, OUTPUT);

  }


}

void loop() {
  for(int i=0; i<=7; i++) {
    digitalWrite(i, HIGH);
    
    if (data[i] & 0x01) {
      digitalWrite(15, LOW);
    } else {
      digitalWrite(15, HIGH);
    }
    if (data[i] & 0x02) {
      digitalWrite(14, LOW);
    } else {
      digitalWrite(14, HIGH);
    }
    if (data[i] & 0x04) {
      digitalWrite(13, LOW);
    } else {
      digitalWrite(13, HIGH);
    }
    if (data[i] & 0x08) {
      digitalWrite(12, LOW);
    } else {
      digitalWrite(12,HIGH);
    }
    if (data[i] & 0x10) {
      digitalWrite(11, LOW);
    } else {
      digitalWrite(11, HIGH);
    }
    if (data[i] & 0x20) {
      digitalWrite(10, LOW);
    } else {
      digitalWrite(10, HIGH);
    }
    if (data[i] & 0x40) {
      digitalWrite(9, LOW);
    } else {
      digitalWrite(9, HIGH);
    }
    if (data[i] & 0x80) {
      digitalWrite(8, LOW);
    } else {
      digitalWrite(8, HIGH);
    }
  delay(2);
  digitalWrite(i, LOW);   
  }

}
