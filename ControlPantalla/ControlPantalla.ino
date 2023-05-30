#include <LiquidCrystal.h>

// Configuración de los pines de la pantalla LCD
const int rs = 12;   // Pin RS de la pantalla LCD conectado al pin digital 12 del Arduino
const int en = 11;   // Pin EN de la pantalla LCD conectado al pin digital 11 del Arduino
const int d4 = 5;    // Pin D4 de la pantalla LCD conectado al pin digital 5 del Arduino
const int d5 = 4;    // Pin D5 de la pantalla LCD conectado al pin digital 4 del Arduino
const int d6 = 3;    // Pin D6 de la pantalla LCD conectado al pin digital 3 del Arduino
const int d7 = 2;    // Pin D7 de la pantalla LCD conectado al pin digital 2 del Arduino

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Crea un objeto LiquidCrystal

void setup() {
  lcd.begin(16, 2);  // Inicializa la pantalla LCD con 16 columnas y 2 filas

}

void loop() {
  // El código principal puede ir aquí si deseas realizar alguna otra acción en bucle
    lcd.print("Hola mundo");  // Muestra "Hola mundo" en la pantalla LCD
}
