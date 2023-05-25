int pinSensor = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinSensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valor = digitalRead(pinSensor);
  Serial.println(valor);
  delay(100);
}
