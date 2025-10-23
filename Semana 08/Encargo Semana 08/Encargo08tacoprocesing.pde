
import processing.serial.*;

Serial myPort;
String lineaActual = "";

void setup() {
  size(800, 400);
  printArray(Serial.list()); // Muestra los puertos disponibles
  myPort = new Serial(this, Serial.list()[0], 9600); // Asegúrate que el índice es correcto
  myPort.bufferUntil('\n');
  textAlign(CENTER, CENTER);
  textSize(24);
}

void draw() {
  background (mouseY);
  ellipse(224, 184, 500, 500);
  ellipse(224, 184, 350, 350);
  ellipse(224, 184, 280, 280);
ellipse(224, 184, 220, 220);
fill(mouseY);
ellipse(224, 184, 180, 180);

fill(255,0,0);

  text(lineaActual, width / 2, height / 2);
  
  fill(41,114,51);

    fill(mouseY);
}

void serialEvent(Serial myPort) {
  String received = myPort.readStringUntil('\n');
  if (received != null) {
    lineaActual = trim(received);
  }
}
