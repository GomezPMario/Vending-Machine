#include <Servo.h>

Servo servo;
Servo servo2;
Servo servo3;
Servo servo4;

int servoPin = 11; // servo que empuja las barritas
int servoPin2 = 12; //servo que controla las barritas (abajo)
int servoPin3 = 52; //servo que controla los lacasitos
int servoPin4 = 10; //servo que controla la rampa

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.parseInt();  // Lee el número introducido en el puerto serie

    if (command == 1) {
      servo2.write(10);
      delay(500);
      servo.write(20);
    } else if (command == 2) {
      servo2.write(170);
      delay(500);
      servo.write(100);
    } else if (command == 3) {
      servo3.write(92);
      delay(400);
      servo3.write(18);
    } else if (command == 4){
      servo4.write(90);
      delay(1000);
      servo4.write(40);
    }
  }
}
