#include <EEPROM.h>

void setup() {
  for(int i = 0; i<30; i++) {
    EEPROM.write(i, i);
  }

  Serial.begin(9600);

}

void loop() {
  for (int i=0; i<30; i++) {
    int data = EEPROM.read(i);

    Serial.println(data);
  }

  while(true);

}
