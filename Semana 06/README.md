### Semana 06

Pseudocódigo, es la escrito de codigos sueltos para tener una idea de lo que se quiere llegar.
Pensando en una caja negra, tenemos un input (sensor), y un ouput (actuador), y lo que se quiere es tener una información del mujnod y aplicarla ne algo. Cuando se tiene un fenómero a medir, como la luz, se requiere de un sensor, que va a la caja negra, y lo convierte en una señal, en electricidad, y esa electricidad es recibida en el emciroconrolador, que en su interior lo reinterpreta como información. Y este sensor se guarda como información en una variable, y luego con esa informaciión uso la variable, y con ello llego a un output, y luego puede llegar a un driver o a un interfaz, que lleve al actuador, que se va a transformar en un nuevo fenómeno; movimiento, luz, sonido, etc.


En Arduino:


Se tiene que primero declarar las variables, en donde definir las infos nuevas a guardar, y además la información que se va a utilizar. Se necesita saber primero el tipo de variable. Es ideal inicialiae las variables con algun numero con int, string palabras, si es con comas usar float, si son si o no se usa bool. El Set Up sería para inicializar, y con ello lo hacemos con el Serial.begin (9600). Decidimos si los pines van a ser input o outputs, en donde se recibe, y así se ocupan cosas como pinMode. Recordar que los analogIN son solop de entrada, no salida.


Para el caso del loop, podríamos usar un potenciómetro, y para eso, hay que decir en donde queremos guardar el valor, pero primero, en donde lo recibo, entonces se usa una variable para guardar la información, en donde podemos colocar arriba int informaciónm en donde dejaremos esa información. Ahí podemos usar AnalogRead, en donde podemos colocarlo como información. Eneotnces información = analogRead (A0);, y así se tiene guardada la información.

También uno tiene que actualizar, operar, preguntar la información que estoy recibienindo, tipo es mayor o menor que otra cosa, proporcional, a otro rango, quiero saber en que lugar está. Quiero saber si es mayor o menor que un umbral, entonces ahí coloco If (informaicón >=umbral), siendo int umbral=100;, y si no lo es, colocar else otra cosa. De esta forma, recibo la infomracipon, la admnistro y la uso, y la puedo ver con el display pantallita para verlo ahí. 


### Procesing (CAM)

En librerias, getting capture de Videolibrary for Processinf4.
se ve un Capture cam, esa no es una variable, si no que una Clase del tipo caprute. cuando la primera palabra tiene la primera letra en mayuscuka y luego la aegunda en minuscula, es una Clase.

En String cameras = cameras listi, es para que guarde todo el tipo de camaras ahí.

y en println sale un null en caso de que no haya camaras. Null es como un error, como por ejemplo que el pc no tenga camaras, pero la que me aparece para mostrar es la que tenga entre corchetes, si sale 0, es la p¿canara principal porque no hay otra, si se pone otra, tendrá que ser con un numero superior a 0.

Al final, hay un cam.start. que es el pinMode de la camara, es comoc decirle a la camara que autorice a mostrar imagen. Para el computador, la camara es un sensor, y con una matriz de pixeles, en donde cada uno tiene un valor de luz

```
{
  size(640, 480);

  String[] cameras = Capture.list();

  if (cameras == null) {
    println("Failed to retrieve the list of available cameras, will try the default...");
    cam = new Capture(this, 640, 480);
  } else if (cameras.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  } else {
    println("Available cameras:");
    printArray(cameras);

    // The camera can be initialized directly using an element
    // from the array returned by list():
    cam = new Capture(this, cameras[0]);

    // Or, the camera name can be retrieved from the list (you need
    // to enter valid a width, height, and frame rate for the camera).
    //cam = new Capture(this, 640, 480, "FaceTime HD Camera (Built-in)", 30);
  }

  // Start capturing the images from the camera
  cam.start();
}

```

Este es el ejemplo.


Al final del draw, se crearpa un ellipse, ejemplo 

eliipse(width/2, height/2, 100, 100);, y eso va a hacer que salga un circulo al medio de la camara. y si le colosco un fill (0,0,0,);, aparecerá e, circulo de color negro.

```
/**
 * Getting Started with Capture.
 * 
 * Reading and displaying an image from an attached Capture device. 
 */

import processing.video.*;

Capture cam;

void setup() {
  size(640, 480);

  String[] cameras = Capture.list();

  if (cameras == null) {
    println("Failed to retrieve the list of available cameras, will try the default...");
    cam = new Capture(this, 640, 480);
  } else if (cameras.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  } else {
    println("Available cameras:");
    printArray(cameras);

    // The camera can be initialized directly using an element
    // from the array returned by list():
    cam = new Capture(this, cameras[0]);

    // Or, the camera name can be retrieved from the list (you need
    // to enter valid a width, height, and frame rate for the camera).
    //cam = new Capture(this, 640, 480, "FaceTime HD Camera (Built-in)", 30);
  }

  // Start capturing the images from the camera
  cam.start();
}

void draw() {
  if (cam.available() == true) {
    cam.read();
    
  }
  image(cam, 0, 0, width, height);
  // The following does the same as the above image() line, but 
  // is faster when just drawing the image without any additional 
  // resizing, transformations, or tint.
  //set(0, 0, cam);
  
   fill (0,0,0);
  ellipse(width/2, height/2, 100, 100);
 
}

```

Y para cambiar el color del circulo, se le colca arriba como int variable el color c(); (ver esto en video). en donde se cambia el fill con los ceros con el fill c.

Y para cambiarle el color para que sea relativo según la función del puntero, según donde apunte, se tendrá un codifo de 
c=cam.get(mouseX, mouseY); se tiene la coordenada de donde marce el mousse con el pixcel de color (ver apuntes del profe).

Para el codigo sea con pixeles dependiendo de la cámara:

```
import processing.video.*;

Capture cam;
int step = 30; // Tamaño del bloque

void setup() {
  size(640, 480);
  String[] cameras = Capture.list();
  if (cameras.length == 0) {
    println("No se detectaron cámaras.");
    exit();
  } else {
    cam = new Capture(this, cameras[0]); // Para Processing 4
    cam.start();
  }
  textAlign(CENTER, CENTER);
  textSize(10);
  noStroke();
}

void draw() {
  if (cam.available()) cam.read();
  cam.loadPixels();
  background(0);

  for (int y = 0; y < cam.height; y += step) {
    for (int x = 0; x < cam.width; x += step) {
      int index = x + y * cam.width;
      color c = cam.pixels[index];

      // Calcular brillo (0–100 en Processing)
      float b = brightness(c);

      // Fondo en escala de grises
      fill(b);
      rect(x, y, step, step);

      // Texto: blanco en bloques oscuros, negro en bloques claros
      fill(b < 50 ? 255 : 0);
      text(int(b),x+step/2,y + step/2);
    }
  }
}

```


### Comunicación Arduino-Processing

Un LDR es una resistencia, que depende de la luz para cambiarm es como un potenciometro que requiere de la luz del ambiente, es bueno para saber si hay sombras, etc. Se conecta entrre 5V A0 una resistencia de 1000k, y de esa a tierra va el LDR.

```
int ldrPin = A0;

int valorLdr = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
valorLdr = analogRead(ldrPin);
Serial.println(valorLdr);
}

```

Y en Processing, buscamos el ejemplo. que tiene el profe en el github, así, colocamos el uesrto en donde estps conectado el arduino por temas de comunicación, y se tiene el codigo:

```

import processing.serial.*;

Serial miPuerto;   // objeto para la conexión
String datos;      
int valor;

void setup() {
  size(400, 200);
  println(Serial.list());              // lista los puertos disponibles
  miPuerto = new Serial(this, "COM5/dev/cu.usbmodem1101", 9600); 
  miPuerto.bufferUntil('\n');          // lee hasta salto de línea
}

void draw() {
  
  // en esta sección debería usar de alguna manera la variable "valor"
  background(200);
  fill(50);
  ellipse(width/2, height/2, valor,valor);    // dibuja una barra con el valor
}

void serialEvent(Serial miPuerto) {
  datos = miPuerto.readStringUntil('\n');  // lee la línea completa
  if (datos != null) {
    datos = trim(datos);                   // limpia espacios
    valor = int(datos);                    // convierte a número
  }
  println(valor);
}

```

En donde en procesing se abra una pantalla con un circulo que palpita, debido a que está el LDR está conectado con el sistema arduino y depende de la luz, entonces al colocar la mano por sobre el LDR, el circulo se agranda, debido a que genera sombra, y al usar luz del celular, el ciculo de achica.

Y para que la camara con pixeles dependa del arduino, con el LDR, el codigo sería:

```
import processing.video.*;
import processing.serial.*;

Capture cam;
int step = 50; // Tamaño del bloque

//variables que tienen con Serial
Serial miPuerto;   // objeto para la conexión
String datos;      
int valor;

void setup() {
  size(640, 480);
  String[] cameras = Capture.list();
  if (cameras.length == 0) {
    println("No se detectaron cámaras.");
    exit();
  } else {
    cam = new Capture(this, cameras[0]); // Para Processing 4
    cam.start();
  }
  textAlign(CENTER, CENTER);
  textSize(10);
  noStroke();
  
  //Imprime nombres puertos usb Serial disponibles
    println(Serial.list());              // lista los puertos disponibles
  // acá deberíamos poner el puerto donde está conectado el arduino
  //////////////
  miPuerto = new Serial(this, "/dev/cu.usbmodem11301", 9600);
  /////////////
  miPuerto.bufferUntil('\n');          // lee hasta salto de línea

}

void draw() {
  if (cam.available()) cam.read();
  cam.loadPixels();
  background(0);

  for (int y = 0; y < cam.height; y += step) {
    for (int x = 0; x < cam.width; x += step) {
      //acá hacemos que el tamaño de los px
      //dependa del valor recibido desde Arduino
      step = valor/10;
      int index = x + y * cam.width;
      color c = cam.pixels[index];

      // Calcular brillo (0–100 en Processing)
      float b = brightness(c);

      // Fondo en escala de grises
      fill(b);
      rect(x, y, step, step);

      // Texto: blanco en bloques oscuros, negro en bloques claros
      fill(b < 50 ? 255 : 0);
      text(int(b),x+step/2,y + step/2);
    }
  }
}

void serialEvent(Serial miPuerto) {
  datos = miPuerto.readStringUntil('\n');  // lee la línea completa
  if (datos != null) {
    datos = trim(datos);                   // limpia espacios
    valor = int(datos);                    // convierte a número
  }
  println(valor);

}

```
