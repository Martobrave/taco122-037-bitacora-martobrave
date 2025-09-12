#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir tamaño del display
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 48

// Dirección I2C típica (0x3C o 0x3D)
#define OLED_ADDR 0x3C  

// Crear objeto display
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire);

const char* lineasPoema[] = 
{
  "Dar vueltas una y otra vez",
  "y volver siempre al mismo lugar.",
  "Dar vueltas y no saber que hacer.",
  "Tomar decisiones sin sentido",
  "dentro de un espiral infinito.",
 
  "El mundo gira en direccion opuesta.",
  "Los opuestos nunca se atraen.",
  "Quien diga lo contrario está mintiendo.",
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
 Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    
    Serial.println(F("No se encontró pantalla SSD1306"));
    for(;;); // se queda detenido
  }
  }


void loop() {
  // nada que hacer en loop

for (int i = 0; i < 16; i++ ){
  delay(5000);


 display.clearDisplay();             // limpiar buffer
  display.setTextSize(1);             // tamaño del texto
  display.setTextColor(SSD1306_WHITE);// color del texto
  display.setCursor(0,0);          // posición (x,y)
  display.println(lineasPoema[i]);      // escribir texto

  display.display(); 


}

delay(5000);

}

