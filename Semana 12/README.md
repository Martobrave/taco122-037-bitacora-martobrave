# Semana 12

Ver ml5.js para ver como entrenar a la IA.

### Avances del proyecto:

A primer paso, se hizo un sistema utilizando el Arduino un sistema donde, ocupando el protoboard para conectar el circuito. Se instaló el sensor ultrasónico HC-SR04 en el protoboard, conectando el VCC al la tira roja del protoboard, la cual se une al 5V del Arduino, el Grnd a la tira azul, y las conexiones Trg a 9 y Echo a 8 directamente al arduino. Y para enlazarlo con un Relé de 1 canal (el cual se une al motorreductor con llanta de goma, de 125 rpm), se conecta el Relé a la protoboard, con el VCC a la tira roja, el Grnd a tira azul, y IN1 a directamente al pin 11 del Arduino. Y el circuito con el motorreductor y las pilas como fuente del motor se conecta al Relé con la carga positiva en el COM y la negativa al NO.

Se utiliza el código en Arduino:

```

// --- Pines del Sensor Ultrasónico ---
const int pinTrigger = 9;
const int pinEcho = 10;

// --- Pin de Control del Relé ---
const int pinRele = 5; 

// Variables para el sensor
long duracion;
int distanciaCm;
int umbralDistancia = 50; // La distancia objetivo en centímetros

void setup() {
  Serial.begin(9600);
  
  // Configuración de pines
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinRele, OUTPUT);
  
  // Apagar el motor al inicio
  digitalWrite(pinRele, LOW); 
}

void loop() {
  // --- Lectura del Sensor Ultrasónico ---
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  duracion = pulseIn(pinEcho, HIGH);
  distanciaCm = duracion / 58;

  // --- Lógica de Control del Relé ---

  Serial.print("Distancia actual: ");
  Serial.print(distanciaCm);
  Serial.print(" cm | Umbral: ");
  Serial.print(umbralDistancia);
  Serial.print(" cm -> Estado del Motor: ");

  // Si la distancia es MENOR al umbral, encender el relé
  if (distanciaCm < umbralDistancia) {
    digitalWrite(pinRele, HIGH); 
    Serial.println("ENCENDIDO (Objeto cerca)");
  } else {
    // Si la distancia es MAYOR O IGUAL al umbral, apagar el relé
    digitalWrite(pinRele, LOW);
    Serial.println("APAGADO (Objeto lejos)");
  }

  delay(500); // Pequeña pausa para estabilizar las lecturas
}

```

Con ello, al colocar un objeto a 50 cms o menor distancia desde el sensor, el motorreductor gira, de forma constante, sin modificar la aceleración. Esto debido a que el Relé solo tiene como función en Encender/Apagar algo, como un bool, no puede cambiar de forma de mas variables (como análogo), por lo que actúa como un interruptor único. Esto puede servir, pero se seguirá probando con algún otro sistema que permita un cambio variable para que la aceleración sea distinta de cero.




Se procede a comprar un Conductor motor L298N, que permite el cambiar la aceleración del motorreductor de acuerdo con la distancia indicada con el sensor ultrasónico. Se conectan, ya sin la protoboard porque también se compraron más cables macho-hembra, y se utiliza el código:


```

// Definir los pines para el sensor ultrasónico
const int trigPin = 9;
const int echoPin = 10;

// Definir los pines para el driver L298N
const int motorEnablePin = 11; // Pin con capacidad PWM para controlar la velocidad
const int motorPin1 = 7;      // Pin de dirección 1
const int motorPin2 = 8;      // Pin de dirección 2

// Variables para la medición de distancia
long duracion;
int distancia;

void setup() {
  // Configurar los pines de entrada y salida
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Inicializar la comunicación serial para depuración
  Serial.begin(9600);

  // Asegurar que el motor esté apagado al inicio
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorEnablePin, 0);
}

void loop() {
  // Limpiar el pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Enviar un pulso de 10 microsegundos por el pin Trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir la duración del pulso de retorno en el pin Echo
  duracion = pulseIn(echoPin, HIGH);

  // Calcular la distancia en cm
  distancia = duracion * 0.034 / 2;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Mapear la distancia a un valor PWM para controlar la velocidad del motor
  int velocidad;
  if (distancia > 100) {
    velocidad = 0; // Detener el motor si la distancia es mayor a 100 cm
  } else if (distancia < 10) {
    velocidad = 255; // Velocidad máxima si la distancia es menor a 10 cm
  } else {
    // La función map() invierte la relación: a menor distancia, mayor velocidad
    // Rango de distancia: 100 a 10
    // Rango de velocidad (PWM): 0 a 255
    velocidad = map(distancia, 100, 10, 0, 255);
  }

  // Activar el motor en un solo sentido
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorEnablePin, velocidad);

  // Imprimir la velocidad del motor en el monitor serial
  Serial.print("Velocidad del motor (PWM): ");
  Serial.println(velocidad);

  // Pequeña pausa antes de la siguiente lectura
  delay(100);
}

```

Utilizando abora las conexiones de Sensor Ultrasónico en el arduino;
VCC → Pin 5V del Arduino.
GND → Pin GND del Arduino.
Trig → Pin digital 9 del Arduino.
Echo → Pin digital 10 del Arduino

Las conexiones del controlador L298N con el arduino;
VCC → Pin 5V del Arduino.
GND → Pin GND del Arduino.
ENA → Pin digital 11 del Arduino (necesitas quitar el jumper de ENA en el L298N).
IN1 → Pin digital 7 del Arduino.
IN2 → Pin digital 8 del Arduino.
OUT1 y OUT2 → Conecta las dos patillas del motorreductor.
+12V (o el voltaje de tu fuente de poder) → Terminal positivo de tu fuente de alimentación externa.
GND → Terminal negativo de tu fuente de alimentación externa.


