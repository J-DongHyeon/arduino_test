
int read_now, read_last, real_state;
int led_state;


unsigned long push_time;
unsigned int chattering = 50;



void setup() {
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);

  read_last = HIGH;
  real_state = HIGH;
  led_state = LOW;
}

void loop() {

  read_now = digitalRead(7);

  if (read_now != read_last) {
    push_time = millis();
  }

  if (millis() - push_time > chattering) {
    
    if (real_state != read_now) {
      real_state = read_now;
    
      if (real_state == LOW) {
        led_state = !led_state;
        
        
      }
    }

    
  }
  



  read_last = read_now;
  digitalWrite(8, led_state);
  

}
