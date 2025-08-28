# Semana 03

21/08/2025

## Comentarios de la clase:

Se retroalimenta lo visto previamente con processing. Se muestra como agregar y eliminar archivos/carpetas. Para en el processing colocar los códigos sin que se muestre los cambios como tales, se coloca 3 acentos graves al inicio y al final, lo cual se muestran los códigos. Para colocarle los colores de cuales se vean en el processing, se coloca posterior a los primeros 3 acentos graves la palabra **processing**, y con ello se ve con colores.

La palabra FORK es un tenedor en inglés, y en github, hay unas cosas llamadas Brunches, es una linea de timepo del repositorio, pero a veces la gente se lo lleva en sus computadores, lo modifican, y luego lo trae al original, entonces es una variante que se inserta en el repositorio original, eso se conoce como Brunchie y como FORK, lo cual es que se pueda hacer una derivación de otro lugar. Forked from indica de donde se copia/modifica, e indica cuantas ramas se encuentra atrasado de la rama principal. Si se quiere editar frente a una copia, tengo que editar en una copia, y que la persona te otorgue acceso para poder colocar las modificaciones para la copia.

Para ***colocar _imágenes_***, se puede colocar ya sea imagenes de internet, o del mismo repositorio. Para el mismo repositorio, tengo que crear la carpeta /imagenes/borrar.text, ya que github no me permite tener carpretas vacias. Entonces queda un archivo vacío en esa carpeta (esa acción se conoce como _placeholders_). Entonces la foto desde mi computador, en la carpaetam Upload files la imagen (jpg), entonces ahí queda como un archivo. Para que se vea en el Readme.md de una carpeta (markdown images se puede investigar sobre ello, manual), e indica que se le conozca un signo de exclamación, un texto alternativo (que cuente de que era por en caso de que se rompa la imagen) el texto entre corchetes, y luego entreparentesis el link en donde se encuentra la imagen. Lo puedo colocar el link como (./imagenes/gatos.jpg), en donde ./ indica el "aquí", en donde está este archivo. Arriba de cada reamd indica un Preview, y si salió bien, entonces debería de salir ahí la imagen. Evitar tildes y espacios, ya que complican un poco.

## ARDUINO

Arduino 1 es un microcontrolador, con un chip de 28 patas con nombre de ATMEGA328P, y la empresa de ese arduino facilitó el trabajo con todo lo que está por encima y los hoyitos que se encuentrs po los extremos.
Arduino pícaro.
Arduino clon tienen todo lo mismo por dentro, pero los originales tienen elementos de seguridad. El mio es clon, dice UNO, el original dice Arduino y tiene una placa de acrilico por debajo, para cuidar de corriente del soporte. La clon/china tiene una traba, que nbo es original, entonces requiere de un externo para hackear y actuar como original. Hay que bajar un driver, que es el driver ch3540, haciendo que el arduino chino se comunique con el computador. Y reiniciar.

Vamos a descargar en arduino.cc/en/software la aplicación para utilizar con el Arduino.

Tinkercad.com es un Arduino virtual.

Conectamos el arduino al computador y abrimos la aplicación al respecto. Para corrobosr que funicone con el pc, nos vamoa a archivo/ejemplos/basicos/blink. Aparece un set up, y loop (es el draw), y al ahcer 1 variación, por ejemplo colocar en delay 100 en vez de 1000. Seleccionamos la placa, escribimos UNO que es mi arduino, seleccioamos Uno a secas,. el puerto, se acepta, y se coloca upload arriba en la izquierda. Estoy va a estar cargando, y temrinará diciendo Uploaded, y en la placa arduino aparecerá una luz roja o naranja titilando, eso indica que está conectado al sistema. 

Si colocamos Nuevo en el sistema de Arduinos, tenemos todo en blanco, y tenemos arriba en la izquierda dos botones, verificar y upload. 

Loop es tan rapido como pueda. Arduino es una caja nra, que recibe inputs y saca outputs. Arduino a través de sensores que recibe, lo convierte en datos, y se pueden ver afuera como actuadores. Sensores como LDR, botón, perilla, etc, esto detecta y hace función, como luces, motores y sonidos. Dentro de las luces podemos concocer luces Led y pantallas. Entonces si vemos la placa, vemos la parte de Digital, del 0 al 13, que pueden ser entra oa saludas, y ANALOG IN son solo entradas analogicas. Digital (o discreto) tiene pixeles, reticulas, con información, mientrasd que en algo analogico (o continuo) no hay pixeles, gradiwntes, flujo de colores. Analogico es fluido. Un reloj, la noción de hora es discreta, pero el tiempo no sabe de números, es un flujo contínuo.

En el arduino entonces, la parte Digital recibe o un 1 o un 0, apagado o encendido, o high o low, y todo lo que corresponde a binario. Lo analógico, no es solo de 0 a 1, si no como que tiene escala de grises, entonces de 0 a 1 y todo en su ranho, de forma discreta igual pero tiene un espacio gris. El led del arduino es anal+ogico porque está en el mundo real, pero el arduino lo reconoce como un 1 o 0, por lo que diremos que tiene un comportamiento digital, o está endendido o apagado.

En arduino, lo primero que hay que hacer es saber si los ´pines si son inputs o outputs, el led interno de arduino, 1 está conectado en la pata 13, entonces digamsole al arduino que el pin13 sea un output, una salida al mundo, y para ello hay su¿yntaxis, correspinente a:

pinMode(13,OUTPUT);

pinMode(nuimero de pin,INPUT U OUTPUT);, en el setup

Para encender el LED, hay que escribir en él, y dijimos que era digitial, apagadoi o encendido, entonces se usa la función digitalWrite(numero de pin, estado o 1);

digitalWrite(13,HIGH);

Entonces, se crea una varuiable para indicar en donde está el led;

int ledPin = 13;

Eso va a hacer que se modifique todo lod e abajo indicando que el 13 es el led.

Hay que hacer que encienda y apaguie, pero para que no sea tan rapidp y volver loco al arduino, hay que hacer una función delay, loop, vovler al principio, set up es solo 1 vez. Entonces vamos a encernder con la función delay(1000), con delay paralizamos el codigo por un tiempo, 1 milisegundo. Apagando de esta forma el led, se coloca debajo el digitalWrite(ledPin,LOW); se escribe delay(1000); antes y después del digitalWrite(ledPin,LOW);.

Haciendo una variación, arriba del setup, int tiempoOn=200; tiempoOff=100
, y abajo en el primer delay, colocar lo que tarde el tiempoOn,
delay(tiempoOn); , y en el ultimo tiempoOff.

Esto se vería por ahora;
```
int ledPin = 13;
int tiempoOn = 200;
int tiempoOff = 100;
void setup() {
  // put your setup code here, to run once:

pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(tiempoOn);
  digitalWrite(ledPin,LOW);
  delay(tiempoOff);
}
```

Acá, para imprimir, hay qye declararlo en el setup para hacerlo. Un cable USB (universal serial bus, universal porque es estpandar, serial porque va uno después de otro los bits, y el bus indica que va en un bus coomo de paquetitos electrónico quie es USB,) tiene 4 cables internos, con patas, una pata es VCC de 5V, y la otra GND, y usan esas patas basicas para cargar un computador, y hay otras 2 patiras que se lla Data + (D+) y D-, que van en sentidos contrarios, y esos 4 cables se conecta con el pc y el arduino. y si conectamos el arduino a la corriente, acctua igual que en el pc, debido a que sigue cocinando el mismo sistema que se le colocó como ultima vez en el pc, va a quedar siempre con el mismo código, ocupando la memoria que tiene ahí. si se le incorpora info, borra la anterior, lo escriben por encima. Lo que hacemos al subir el codigo, se actia la comunicación de D+ y D-, comunicación. y luego de eso, el computador actua como bateria para eñ arduino, y para ver lo que hace el arduino, tenemos que tener la comunicación, y para eso hay que instalar una linea en el set up, corresponsioente a Serial.begin(9600);, 9600 es el baud rate, o tasa de baudios, signifinca que esta circulando 9600 datos por segundo, la velocidad que ocupa el mouse del pc, se le puede colocar más pero es innecesario.
 Debajo del digitalwrite, se puede imprimir colcoando por ejemplo:
 Serial.printIn("me prendi");
 y en el digitalwrite final el Serial.println("me apague");

 Y se ve esas oalabras de forma intermedia.

 En el arduino se ven unas luces titilando, RX que esta recibiendo info, y L que e¿lo está dando (al parecer, por investigar).
 
```
 int ledPin = 13;
int tiempoOn = 200;
int tiempoOff = 100;
void setup() {
  // put your setup code here, to run once:

pinMode(ledPin,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
Serial.begin(9600);
digitalWrite(ledPin,HIGH);
Serial.println("me prendi");

  delay(tiempoOn);
  digitalWrite(ledPin,LOW);
  Serial.println("me apague");
  delay(tiempoOff);
}
```

Copmunicación binaria, se prende y apaga el led, como un semaforo por ejemplo, por probar vamos a hacer algo de morse, la A es un punto y raya (.-) actuando como un on y un off. Entonces para construir una A, el punto durará un tiempo punto
int timepoPunto=100;
un separador de tiempo
int separador = 50;
 y tiempo taya
 int tiempoRaya = 500;
 y tiempo de cierre de caracter
 int finCaracter = 100;

 todos son tiempos distintos

 Y en el Led actua como morse:

```
 int ledPin = 13;
int tiempoOn = 200;
int tiempoOff = 100;
int tiempoPunto=100;
int separador = 50;
 int tiempoRaya = 500;
 int finCaracter = 100;
void setup() {
  // put your setup code here, to run once:

pinMode(ledPin,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
Serial.begin(9600);
digitalWrite(ledPin,HIGH);
Serial.println("me prendi");

  delay(tiempoPunto);

  digitalWrite(ledPin,LOW);

  delay(separador);
digitalWrite(ledPin,HIGH);
Serial.println("raya");
delay(tiempoRaya);
digitalWrite(ledPin,LOW);

delay(finCaracter);

  Serial.println("me apague");
  delay(tiempoOff);
}
```

Para no hacer esto con cada palabra, por ejemplo con la O, vamos a hacer una función:

void punto() {}

Queremos que el punto sea toda la parte del On, correspoodniente a encender, apagar, y esperar el tiempo, entonces colocamos todo dentro de la funciónl y depsués solo colocamos el punto ()

```
void punto() {
digitalWrite(ledPin,HIGH);
Serial.println("me prendi");

  delay(tiempoPunto);

  digitalWrite(ledPin,LOW);

  delay(separador);

}
```

## [Encargo 04](https://github.com/Martobrave/taco122-037-bitacora-martobrave/blame/12f79bc93f2f3b0ae6efc3b041bb8e0a717efe11/Semana%2003/SketchCodigoMorseCrepusculo.ino)
Encargo, escribir un texto con morse.
