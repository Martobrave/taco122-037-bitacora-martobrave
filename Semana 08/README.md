# Clase 08

Se usará Encoder rotatorio. Con sus sistema, se puede saber cuando giro (si hubo un cambio), cual es la dirección y hay un botón. Este se conecta de la forma: (se ve en la pagina del profe)

Se descarga la librería RotaryEncoder.

Se utilizan el codigo en arduino: 

```

//examples, rotatoryEncoder, AceleraterRotator

//#include <Arduino.h>
#include <RotaryEncoder.h>

//Hay que definir lo que es ARDUINO_AVR_UNO

#define ARDUINO_AVR_UNO

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO_EVERY)
// Example for Arduino UNO with input signals on pin 2 and 3, son las patas que está conectado, es digital, no análogo
#define PIN_IN1 2
#define PIN_IN2 3

#elif defined(ESP8266)
// Example for ESP8266 NodeMCU with input signals on pin D5 and D6
#define PIN_IN1 D5
#define PIN_IN2 D6

#endif

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);

void setup()
{
  Serial.begin(9600);
  while (! Serial);
  Serial.println("SimplePollRotator example for the RotaryEncoder library.");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  // definiendo como static, hacemos que sea local (solo dentro del loop)
  // y SOLO la primera vez parte en 0
  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    Serial.print("pos:");
    Serial.print(newPos);
    Serial.print(" dir:");
    Serial.println((int)(encoder.getDirection()));
    pos = newPos;
  } // if
} // loop ()

// The End



```

Con esto, se genera un infinito al mover el encoder. El new pos, variable, se utiliza para comunicarse con el processing.

Para efectos educativos, se utilizará una varibale que enviará al processing :

```


// This example checks the state of the rotary encoder in the loop() function.
// The current position and direction is printed on output when changed.

// Hardware setup:
// Attach a rotary encoder with output pins to
// * A2 and A3 on Arduino UNO.
// * D5 and D6 on ESP8266 board (e.g. NodeMCU).
// Swap the pins when direction is detected wrong.
// The common contact should be attached to ground.

//#include <Arduino.h>
#include <RotaryEncoder.h>

//Definimos que existe ARDUINO_AVR_UNO
#define ARDUINO_AVR_UNO

//creo variable donde envío el número a processing
int valorAEnviar = 0;

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO_EVERY)
// Example for Arduino UNO with input signals on pin 2 and 3
#define PIN_IN1 2
#define PIN_IN2 3

#elif defined(ESP8266)
// Example for ESP8266 NodeMCU with input signals on pin D5 and D6
#define PIN_IN1 D5
#define PIN_IN2 D6

#endif

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);


void setup()
{
  Serial.begin(9600);
  while (! Serial);
  Serial.println("SimplePollRotator example for the RotaryEncoder library.");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  //definiendola como static, hacemos que sea local (solo dentro del loop)
  //y SOLO la primera vez parte en 0
  static int pos = 0;
  //Esta función es la más importante de la biblioteca
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    // Serial.print("pos:");
    // Serial.print(newPos);
    // Serial.print(" dir:");
    // Serial.println((int)(encoder.getDirection()));
    pos = newPos;
  } // if

  //siempre valorAEnviar va a ser newPos
  valorAEnviar=newPos;
  Serial.println(valorAEnviar);

} // loop ()

// The End

```

Para hacer la unión con el processing, lo que hice en la clase, corresponde a 

ARDUINO:

```

const int pinCLK = 2;
const int pinDT = 3;

int lastCLKState;
int currentLine = 0;

const int numLines = 16;

// Poema almacenado en Arduino
String poema[numLines] = {
  "Dar vueltas una y otra vez",
  "y volver siempre al mismo lugar.",
  "Dar vueltas y no saber que hacer.",
  "Tomar decisiones sin sentido",
  "dentro de un espiral infinito.",
 
  "El mundo gira en direccion opuesta.",
  "Los opuestos nunca se atraen.",
  "Quien diga lo contrario esta mintiendo.",
  "Y quien miente dice la verdad.",
  "Engañamos para mostrar lo que realmente somos.",
 
  "Estudiamos para no saber nada.",
  "La ignorancia nos acompaña toda la vida.",
  "Aprendemos a quererla con el tiempo.",
  "Para no vomitar cuando giramos. ",  
  "Para creer que cada vuelta es distinta.",

" Helice - Enrique Jorquera, Santiago, Chile (2021)",
};

void setup() {
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);
  Serial.begin(9600);
  lastCLKState = digitalRead(pinCLK);

  // Mostrar primera línea
  Serial.println(poema[currentLine]);
}

void loop() {
  int currentCLKState = digitalRead(pinCLK);

  if (currentCLKState != lastCLKState) {
    if (digitalRead(pinDT) != currentCLKState) {
      currentLine++;
    } else {
      currentLine--;
    }

    // Hacer que el índice del poema sea cíclico
    currentLine = (currentLine + numLines) % numLines;

    // Enviar línea correspondiente
    Serial.println(poema[currentLine]);
  }

  lastCLKState = currentCLKState;
}

```

Y en PROCESSING:

```

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

```

## Motor Arduino

El motor es paso a paso, porqeue segun el pulso, gira cierta cantidad del ángulo.
Siemrpe un motor necesita un intermediario, un driver, porque el arduino no lo tiene solo, un driver con 8 pines dispoinibles. Se descarga en Arduino libreria Stepper:

```

/*
 Stepper Motor Control - one step at a time

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor will step one step at a time, very slowly.  You can use this to
 test that you've got the four wires of your stepper wired to the correct
 pins. If wired correctly, all steps should be in the same direction.

 Use this also to count the number of steps per revolution of your motor,
 if you don't know it.  Then plug that number into the oneRevolution
 example to see if you got it right.

 Created 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(1);
}


```

Con un acoplamiento flexible, se le puede colocar un motor por un lado y por el otro un disco, o lo que se le quiera montar.



