#include "pitches.h"

int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

int durations [] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
    for(int i=0; i<8; i++) {

      int duration = 1000 / durations[i];

      tone(0, melody[i], duration);

      int pause = duration * 1.3;

      delay(pause);

      noTone(0);
    }

}

void loop() {
  // put your main code here, to run repeatedly:

}
