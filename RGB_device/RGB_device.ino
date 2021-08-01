

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available() > 0 ){

    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    
    Serial.read();
    

    analogWrite(3, red); analogWrite(5, green); analogWrite(6, blue);
  }
}
