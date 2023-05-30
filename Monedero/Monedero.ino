int IRPin10 = 43;
int IRPin20 = 41;
int IRPin50 = 42;
int IR10value = 0;
int IR20value = 0;
int IR50value = 0;
int dinero = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IRPin10, INPUT);
  pinMode(IRPin20, INPUT);
  pinMode(IRPin50, INPUT);
}

void loop() {
  IR10value = digitalRead(IRPin10);
  IR20value = digitalRead(IRPin20);
  IR50value = digitalRead(IRPin50);
  if(IR10value == 1){
    Serial.println("Moneda 10");
  }
  if(IR20value == 1){
    Serial.println("Moneda 20");
  }
  if(IR50value == 1){
    Serial.println("Moneda 50");
  }

}
