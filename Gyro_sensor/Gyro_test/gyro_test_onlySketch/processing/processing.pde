import processing.serial.*;

Serial port;
float phi, theta, psi;

void setup() {

  println(Serial.list());
  port = new Serial(this, Serial.list()[0], 115200);
  port.bufferUntil('\n');
  size(600, 600, P3D);
  
}

void draw() {
  background(0);
  lights();
  
  pushMatrix();
  fill(0, 255, 0);
  translate(width/2, height/2, -100);
  rotateX(radians(phi));
  rotateY(radians(psi));
  rotateZ(radians(theta));
 
  box(200, 100, 200);
  popMatrix();
}

void serialEvent(Serial p) {
 
  String buffer = port.readStringUntil('\n');
  String[] buffer_sub = split(buffer, ',');
  phi = float (buffer_sub[0]);
  theta = - float (buffer_sub[1]);
  psi = float (buffer_sub[2]);

}
