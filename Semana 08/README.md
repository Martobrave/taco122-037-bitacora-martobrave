# Clase 08

Se usará Encoder rotatorio. Con sus sistema, se puede saber cuando giro (si hubo un cambio), cual es la dirección y hay un botón. Este se conecta de la forma: (se ve en la pagina del profe)

Se descarga la librería RotaryEncoder.

Se utilizan el codigo en arduino: ```

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

Para hacer la unión con el processing:


