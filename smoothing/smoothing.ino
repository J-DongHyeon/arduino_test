
int array_size = 8;
float total = 0;
float avg = 0;
int now_index = 0;
float smoothing[8];
int data;
float analog_volt;

void setup() {
  pinMode(A0, INPUT);

  Serial.begin(9600);
  for (int i =0 ;i<8; i++) {
    smoothing[i] = 0;
  }

}

void loop() {
  data = analogRead(A0);
  analog_volt = data * (5 / 1023.0);
  
  total -= smoothing[now_index];
  smoothing[now_index] = analog_volt;
  total += smoothing[now_index];

  avg = total / array_size;

  Serial.println(avg);
  
  now_index++;
  now_index &= 0x7;

  delay(1);
  
}
