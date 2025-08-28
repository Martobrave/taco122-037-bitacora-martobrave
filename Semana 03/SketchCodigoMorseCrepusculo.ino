
int ledPin=13;
int tiempoOn=200;
int tiempoOff=100;
int tiempoPunto=100;
int separador=50;
int tiempoRaya=500;
int finCaracter=100;

void setup() {
  
pinMode(ledPin,OUTPUT);

}

void loop() {

Serial.begin(9600);

//El
punto();
l();

//leon
l();punto();o();n();

//se
s();punto();

//enamoro
punto();n();a();m();o();r();o();

//de
d();punto();

//la
l();a();

//oveja
o();v();punto();j();a();

delay(finCaracter);
delay(tiempoOff);

}

void punto() {
digitalWrite(ledPin,HIGH);
Serial.println("Me prendi");
delay(tiempoPunto);

digitalWrite(ledPin,LOW);

delay(separador);

}

void raya(){
digitalWrite(ledPin,HIGH);
delay(tiempoRaya);
digitalWrite(ledPin,LOW);
}

void l(){
punto();raya();punto();punto();
}

void o(){
raya();raya();raya();
}

void n(){
raya();punto();
}

void s(){
punto();punto();punto();
}

void a(){
punto();raya();
}

void m(){
raya();raya();
}  

void r(){
punto();raya();punto();
}   

void d(){
raya();punto();punto();
}   

void v(){
punto();punto();punto();raya();
}

void j(){
punto();raya();raya();raya();
}
