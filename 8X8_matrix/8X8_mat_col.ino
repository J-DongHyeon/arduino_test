unsigned int data [] = {0x00, 0x21, 0x43, 0x45, 0x49, 0x51, 0x21, 0x00};

void setup() {
  for(int i=0; i<=15; i++) {
  pinMode(i, OUTPUT);

  }

  for(int k=8; k<=15; k++) {
    digitalWrite(k, HIGH);
  }


}

void loop() {
  for(int i=8; i<=15; i++) {
    digitalWrite(i, LOW);
    
    if (data[i-8] & 0x01) {
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }
    if (data[i-8] & 0x02) {
      digitalWrite(6, HIGH);
    } else {
      digitalWrite(6, LOW);
    }
    if (data[i-8] & 0x04) {
      digitalWrite(5, HIGH);
    } else {
      digitalWrite(5, LOW);
    }
    if (data[i-8] & 0x08) {
      digitalWrite(4, HIGH);
    } else {
      digitalWrite(4,LOW);
    }
    if (data[i-8] & 0x10) {
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(3, LOW);
    }
    if (data[i-8] & 0x20) {
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }
    if (data[i-8] & 0x40) {
      digitalWrite(1, HIGH);
    } else {
      digitalWrite(1, LOW);
    }
    if (data[i-8] & 0x80) {
      digitalWrite(0, HIGH);
    } else {
      digitalWrite(0, LOW);
    }
  delay(2);
  digitalWrite(i, HIGH);   
  }

}
