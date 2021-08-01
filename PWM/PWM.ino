
int button = 6;
int reading = LOW;
int read_last = LOW;
int real_state = LOW;

int button2 = 7;
int reading2 = LOW;
int read_last2 = LOW;
int real_state2 = LOW;

unsigned long push = 0;
unsigned long chattering = 50;

unsigned long push2 = 0;

unsigned char duty_ratio = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(button2, INPUT); 
  Serial.begin(9600);
}

void loop() {

  reading = digitalRead(button);
  reading2 = digitalRead(button2);

  if (reading != read_last) {
    push = millis();
  }

  if (reading2 != read_last2) {
    push2 = millis();
  }

  if (millis() - push > chattering) {
    if (real_state != reading) {
      real_state = reading;

      if (real_state == HIGH) {

        if (duty_ratio >= 225) {
          duty_ratio = 255;
        } else {
          duty_ratio += 30;
        }

        Serial.print(duty_ratio);
      }
    }
  }

  if (millis() - push2 > chattering) {
    if (real_state2 != reading2) {
      real_state2 = reading2;

      if (real_state2 == HIGH) {

        if (duty_ratio <= 30) {
          duty_ratio = 0;
        } else {
          duty_ratio -= 30;
        }

        Serial.print(duty_ratio);
      }
    }
  }

  analogWrite(3, duty_ratio);
  
  read_last = reading;
  read_last2 = reading2;

}
