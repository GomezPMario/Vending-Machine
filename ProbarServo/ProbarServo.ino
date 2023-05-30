#include <Servo.h>

Servo servo;
int servoPin = 12;
int servoPosition = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.parseInt();  // Lee el número introducido en el puerto serie

    if (command == 1) {
      servo.write(40);  // Mueve el servo a 5 grados
    } else if (command == 2) {
      servo.write(90);  // Mueve el servo a 100 grados
    }
  }
}
