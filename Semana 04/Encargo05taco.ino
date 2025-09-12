int tiempo=0;
int ledPin=9;
int potPin=A0;
int valorPot=0;
int potMapeado=0;

int intensidadLuz=0;

unsigned long tiempoActual=0;
unsigned long tiempoAnterior=0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {

  valorPot=analogRead(potPin);
  potMapeado=map(valorPot,0, 1023,0,255);
intensidadLuz=potMapeado;

analogWrite(ledPin,intensidadLuz);
   Serial.println(intensidadLuz);

if (valorPot < 50)
    {
    	intensidadLed = 255;
    } 

if (valorPot >= 50 && valorPot < 100)
    {
    	intensidadLed = 10;
    } 

if (valorPot >= 100 && valorPot < 150)
    {
    	intensidadLed = 115;
    } 

if (valorPot >= 150 && valorPot < 200)
    {
    	intensidadLed = 0;
    } 

if (valorPot > 200)
    {
    	intensidadLed = 255;
    } 

}