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


