# Encargo 03

Instrucciones:

Generar un afiche con algunas variaciones de movimiento, que incluya el texto seleccionado en el primer encargo. Referente: constructivismo ruso

Investigar variables de tipo "String" para escribir palabras

String palabra = "hola terricolas soy un String";

void setup() {

size (600, 250);
textSize(23);
frameRate(30);
}

void draw() {
//verde 41,114,51
//celeste 48,118,130
//rojo 255,0,0
//gris 156,156,156
  background (48,118,130);
  ellipse(224, 184, 500, 500);
  ellipse(224, 184, 350, 350);
  ellipse(224, 184, 280, 280);
ellipse(224, 184, 220, 220);
fill(255,0,0);
ellipse(224, 184, 180, 180);

fill(0);
 triangle(560,250, 590,50, 620, 250);
 triangle(520,250, 550,100, 580, 250);
 triangle(490,250, 520,130, 550, 250);
 triangle(460,250, 490,160, 520, 250);
 triangle(430,250, 460,190, 490, 250);

  fill(41,114,51);
rect(250, 0+frameCount, 190, 33);
    fill(mouseY);
text ("Que estúpida oveja", 250, 22+frameCount);

  fill(156,156,156);
rect(0+frameCount, 30, 300, 33);
    fill(mouseY);
text ("El león se enamoró de la oveja", frameCount, 50);


 fill(156,156,156);
rect(480-frameCount, 215, 270, 33);
    fill(mouseY);
text ("Y que masoquista es el león", 480-frameCount, 240);




}
