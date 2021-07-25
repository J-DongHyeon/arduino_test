unsigned int data[] = {0xFD, 0x61, 0xDB, 0xF3, 0x67, 0xB7, 0xBF, 0xE5, 0xFF, 0xE7};

void setup() {
  for (int i=0; i<8; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  for(int i=0; i<11; i++) {
    if(data[i] & 0x80) {
      digitalWrite(0, HIGH);
    } else {
      digitalWrite(0, LOW);
    }
    if(data[i] & 0x40) {
      digitalWrite(1, HIGH);
    } else {
      digitalWrite(1, LOW);
    }
    if(data[i] & 0x20) {
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }
    if(data[i] & 0x10) {
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(3, LOW);
    }
    if(data[i] & 0x08) {
      digitalWrite(4, HIGH);
    } else {
      digitalWrite(4, LOW);
    }
    if(data[i] & 0x04) {
      digitalWrite(5, HIGH);
    } else {
      digitalWrite(5, LOW);
    }
    if(data[i] & 0x02) {
      digitalWrite(6, HIGH);
    } else {
      digitalWrite(6, LOW);
    }
    if(data[i] & 0x01) {
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }
   delay(500);
 }

  

}
