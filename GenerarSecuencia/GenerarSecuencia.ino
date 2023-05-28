#include <Servo.h>

Servo servo;
Servo servo2;
int servoPin = 10; // servo que empuja las barritas
int servoPin2 = 5; //servo que controla las barritas (abajo)

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo2.attach(servoPin2);
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.parseInt();  // Lee el número introducido en el puerto serie

    if (command == 1) {
      servo2.write(10);
      delay(500);
      servo.write(10);
    } else if (command == 2) {
      servo2.write(180);
      delay(500);
      servo.write(115);
    }
  }
}
