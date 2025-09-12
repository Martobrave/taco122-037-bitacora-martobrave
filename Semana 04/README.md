# Semana 04

28/08/2025

Apuntes de clases:

Hoy se usará un LED, ub potenciómetro (se usa como una perilla de volumen), un protoboard, cable dupont (hay 3 variantes: que tiene punta por 2, punta en 1 puro lado y en el otro un hueco, y otro que son huecos por ambos lados). La resistencia de mide en Ohms(omega), un K es mil, y la resistencia de 1kOHM, café-negro-rojo-dorado, esas son las resitencias (la que estamos ocupando es de 1/4 de Whats). Corriente es el voltaje/resistencia, esa es la proporción, ley de Ohm, y se cumple la ley en todo el circuito. Y de esa ley también se deduce la potencia, que es le voltaje*corriente. Arduino, en sus salidas, es hacer que hayan fuentes de voltaje disponibles hacia afuera, y en cada salida, que son 14, hay 14 disponibilidades para entregar voltaje (5 volts).

Arduino, en la pata 13 vamos a conectar, como protección de 1 k, un LED de aprox. 10 Amperes. La resietcnai es la misma para ambas lados, da igual como se conecte, pero el LED no, tiene un apta más larga que la otra, la Pata larga es la +. LED es diodo emitor de luz. Si se dan vueltas las patas, o no enciende o se quema (porque la corriente va en un solo sentido). Además, que si se mira por dentro, estan concetados con terminales, el más chiquitito es el que esyá conectado al +

La protoboard, e sun temrinal que permite conectar cosas sin huincha aisladora, superficie con muchas conexiones usbterraneas (puras rayas de metal, como conector), y se ve en las lienas que toda la región es la misma conección. Y hay un rio, con 2 lados a los rios, con 5 puntos de conexión cada ino. Entonces colocnado la resistencia en 2 patitas verticalemnte (la resistencia de 1k), y al colcoar el led, y eo se hace colocando la pata positiva del + en la misma vertical (N°) con la resietcnia. Ocupando los cables,se coloca desde el led hasta el Ground (tierra, suelo), o sea, del - del led al - de más abajo. y luego otro cable desde esa misma linea - al Grpound del arduino. Grn del arudino tiene qu estar conectadop al Grn del Proto, conectar el cable del 13 de arduino a la resistencia + inicial. Con esto, el codigo morse que se hizo previamente se puede ver en la lucecita LED titilando con el mismo ritmo. 

Vimos que del 13 se conecta en el circuito, ya que la semana pasada ocupamos el 13 como salida del arduino.

Para ver el Led On y Off, ocupo la funcipon Write. Output es Write, y input es Read. Hoy veremos Analog Read, y se ocupa ahí el potenciómetro. Esta resistecnia está hecha de carbón, y egún la cantidad de carbóm. hay un resistencia en espeífico. El potenci+ometro tiene muhco carbón dentro, al rededor del circulo como reloj, y la pata central uno mueve y selecciona un lote de carbón. 

Ese potenciómetro, el simbolo es una reistecnia con una flecha entre medio. El potenciómetro dice 10 K, y eso es la resistencia que hay en total. Ahí uno puede colcoar el % de ese valor total. Conectamos el potenciometro con 1 pata hacia ground proto, otra al 5 V, y otra a cero (A0). Por ahora el potenciometro no afectaría al circuito principal. Pra que haga algo, hay que programarlo. Queremos que se lea el potenciometro en el monitor serial. 

Serial.begin(9600);

Hay que decir en donde está nuestri potencimetro, y eso se hace antes del Set up, que se llama


int potPin=A0;

Y se ve que, colocando Serial.println("hola tu");, se ven muchos hola tu en el lector bajando de forma rápida. 


```
int potPin=A0;

void setup() {

Serial.begin(9600);  
  
}

void loop() {
  
Serial.println("hola tu");
}
```

Entonces, crearemos una variable en donde, lo que va a guardar lo que mida neuatro potenciometro, y lo inicializamos en 0

int valorPot=0;

Y lo acetualiamos el valor del potenciometro, queremos que valga algo, que sea dependiente de la lectura del potenciometro que esta cnectado en A0. Si para prender un led, escribimos enccender, este com es análogo y hay que leerlo, se coloca;

valorPot=analogRead(potPin); 
y cambiando "hola tu" por valorPot, al girar la perilla, cambiamos el numero de lectura, ahora lo estamos imprimiendo. Al maximo de un lado dice 0, y por el otro 1023. Este 1023 viene del 2 elevado a un numero basico (del 0 al 9). AnalogRead patra el potenciometro, funciona entre 0 - 1023. Si quisiera trabajae de un numero del 0 al 100 en vez de 1023, se puede cambiar de rango, en donde se proporciona, con regla de 3. Arduino trae ya una fucnión para ello, que es maps (mapear), en ddonde la vaiu¿riabl es 

int potMapeado=0;

Y ahí se va a guardar elk nuevo rango del potenciometro y se le da un valor:

potMapeado=map (valorPot,0,1023,0,100);

en donde map (vaslor qur quiero converir, desde el inerioir, al meximo que, al valor que quiero, y al maximo)

Serial.println(potMapeado);

```
int potPin=A0;
int valorPot=0;
int potMapeado=0;

void setup() {

Serial.begin(9600);  
  
}

void loop() {
  
valorPot=analogRead(potPin); 
potMapeado=map (valorPot,0,1023,0,100);
Serial.println(potMapeado);

}

```

Para vincular el parpadeo del potenciómetro, entonces por ej, ponemos que el ledPin ya no es 13, si no que 7, y eso es un probkenma porque el proto esta conectado al 13, y colcoar que ese pin es una slaida, colocaldndo 

pinMode(ledPin, Output);

Y para hacer el blink, en el loop, se coloca

digitalWrite(ledPin, HIGH);

```
int potPin=A0;
int valorPot=0;
int potMapeado=0;
int ledPin=7;

void setup() {

Serial.begin(9600);  
pinMode(ledPin,OUTPUT);
}

void loop() {
  
valorPot=analogRead(potPin); 
potMapeado=map (valorPot,0,1023,0,100);
digitalWrite(ledPin,HIGH);
delay(1000);
digitalWrite(ledPin,LOW);
delay(1000);


Serial.println(potMapeado);

}
```

aL GIRAR LA PERILLA, EL NUMERO CAMBIA SOLO CUANDO parpadea el led, debido al delay, y recién cuando apague y liego enciende, imprime.

Digamos que queremos que el ptenciometro modifique lavelocidad del potenciometeo
potMapeado=map (valorPot,0,1023,0,2000);
 para cambiar ka veklocidad de 100 a 2000 ms.

 Para eso, necesitamos ua variable que 

 int tiempoParpadeo=100;

 Y apara controlar el tiempo, por mapeado, se dice que 

 tiempoParpadeo=potMapeado;

 Para ecerca del 0 es nas rapdo que cuando el numero es muy alto.

 
```
int potPin=A0;
int valorPot=0;
int potMapeado=0;
int ledPin=7;
int tiempoParpadeo=100;

void setup() {

Serial.begin(9600);  
pinMode(ledPin,OUTPUT);
}

void loop() {
  
tiempoParpadeo=potMapeado;
valorPot=analogRead(potPin); 
potMapeado=map (valorPot,0,1023,0,2000);
digitalWrite(ledPin,HIGH);
delay(1000);
digitalWrite(ledPin,LOW);
delay(tiempoParpadeo);


Serial.println(tiempoParpadeo);

}
```

Millis()
Millis significa milisegundos, y tiene como función el contar en ms el tiempo que lleva prendidoel arduiono, y si se coloca que está difvififo en 1000, cuenta emn segnodos. Es para hacer un blink sin delay


```
int tiempo=0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  tiempo=millis();

  Serial.println(tiempo/1000);

}
```

Entonces, podemos encender el arduino, y con el millis va a etsar ese numero creciendo, y queremoas que se prensa y apague a cada intervalo, entonces lo que queremos es que nuestro codio vaya en el tiempo creciendo, y ciando llegue a 1000 lo sepa, y ahí ocurre cosas, y ciuando llegue a 2000 que ocurra otra cosa, y etc, entonces queremos trabajar en intervalos de 1000 (o X), entonces hayq ue decir que cuando llegue a 1000, que ocurra algo y que vueva a 0 para que parta contando. Entonces para eso hay que crear 2 variables.

Int tiene u ¿n numero maximxo, el cual es 16000, colocando

unsigned int=65535, ya que si llrga al maximo y se pasa, arduino no reconoce, entonces se utiliza

unsigned long, parte desde 0 y tiene 32 bits para gusrdar ese numero, 4 -5 millones aprox. 

Se declara IF como condición, si es mayor, menbor o igual a algo, y luego entre muerclagos lo que se declara, la condición.

bool es variable que solo puede ser 0 o 1, apagado o encendido.

! el negativo de algo.

```
int tiempo=0;
int ledPin=7;
int intervalo=1000;
bool estadoLed=0;
int potPin=A0;

unsigned long tiempoActual=0;
unsigned long tiempoAnterior=0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  tiempoActual=millis();
if (tiempoActual-tiempoAnterior>intervalo){
  estadoLed=!estadoLed;
  Serial.println("Se cumplió la condición");

  tiempoAnterior=tiempoActual;
  }
  digitalWrite(ledPin,estadoLed);
  
}
```



```
int tiempo=0;
int ledPin=7;
int intervalo=1000;
bool estadoLed=0;
int potPin=A0;
int valorPot=0;
int potMapeado=0;


unsigned long tiempoActual=0;
unsigned long tiempoAnterior=0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  tiempoActual=millis();
  valorPot=analogRead(potPin);

  potMapeado=map(valorPot,0, 1023, 100,2000);
intervalo=potMapeado;

if (tiempoActual-tiempoAnterior>intervalo){
  estadoLed=!estadoLed;
 

  tiempoAnterior=tiempoActual;
  }
  digitalWrite(ledPin,estadoLed);
   Serial.println(intervalo);

}
```

Ahora responde mucho más rápido al mover la perilla. Framecount es en processing, y millis en arduino.



Y si queresmoe escribir analógicamente, analog write. 
TRabajaremos en el pin 9, no en el 7, esto es importante porque en el 9, que tiene el signo de cola de chancho (virgulilla), y ese simbolo indica que se puede escribir en valor analógico (PWM).

int intensidadLed=0;

que el led se prenda más o menos. Mapear de 0-1023 a 0-255.AnalogLed

Al mover el potenciometro, la luz se apaga o enciende. 

Encargo 05
IF para alterar el brillo de Led para otros comportamientos. Ej, potenciometro, mide 100, que la intendisad sea maxima, y si mide en tre 100 y 500, que sea intensidad media, etc.

else if es cuando no se cunple pero pasa otra cosa.

```
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

}
```

## Encargo 05

Van a usar la estructura if para alterar el brillo del led a otros comportamientos. Por ejemplo, si el potenciometro mide hasta 100, que la intensidad sea maxima, si mide entre 100 y 500, que sea intensidad media, etc.

Ejemplo:

```
if (valorPot < 100)
    {
    	intensidadLed = 255;
    } 
  
  	if (valorPot >= 100 && valorPot < 200)
    {
    	intensidadLed = 255;
    } 
```

