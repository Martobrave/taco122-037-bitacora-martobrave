
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
