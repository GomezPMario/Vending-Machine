#include <Servo.h>
#include <Keypad.h>

Servo servo;
Servo servo2;
Servo servo3;
Servo servo4;

int servoPin = 11; // servo que empuja las barritas
int servoPin2 = 12; // servo que controla las barritas (abajo)
int servoPin3 = 52; // servo que controla los lacasitos
int servoPin4 = 10; // servo que controla la rampa

// Define la matriz de conexiones del teclado matricial
const byte filas = 4;
const byte columnas = 4;
char teclas[filas][columnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define los pines utilizados para conectar el teclado matricial
byte pinFilas[filas] = {50, 48, 46, 44};
byte pinColumnas[columnas] = {51, 49, 47, 45};

// Crea el objeto Keypad
Keypad keypad = Keypad(makeKeymap(teclas), pinFilas, pinColumnas, filas, columnas);

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '1') {
      servo2.write(170);
      delay(500);
      servo.write(100);
      delay(1000);
      servo2.write(10);
      delay(500);
      servo.write(20);
    } else if (key == '2') {
      servo3.write(92);
      delay(400);
      servo3.write(18);
    } else if (key == '3') {
      servo4.write(90);
      delay(1000);
      servo4.write(40);
    }
  }
}
