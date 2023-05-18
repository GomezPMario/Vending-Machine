#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 3

MFRC522 rfid(SS_PIN, RST_PIN);  // Crear instancia del lector RFID
Servo servo;                    // Crear instancia del servo

void setup() {
  Serial.begin(9600);  // Iniciar la comunicación serial
  SPI.begin();         // Iniciar la comunicación SPI
  rfid.PCD_Init();     // Inicializar el lector RFID
  servo.attach(SERVO_PIN);  // Conectar el servo al pin 3
  
  Serial.println("Acerca una tarjeta RFID al lector...");
  Serial.println();
}

void loop() {
  // Verificar si se ha detectado una tarjeta RFID
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Obtener el UID de la tarjeta RFID
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""));
      uid.concat(String(rfid.uid.uidByte[i], HEX));
    }
    
    // Mostrar el UID en la consola
    Serial.print("UID de la tarjeta: ");
    Serial.println(uid);
    Serial.println();
    
    // Verificar si el UID es correcto (sustituye "AABBCCDD" por el UID correcto)
    if (uid == "c9c68498" || uid == "f9f548b3") {
      // Mover el servo a 90 grados
      servo.write(90);
      delay(1000);  // Esperar 1 segundo
      
      // Volver el servo a 0 grados
      servo.write(0);
    }
    
    // Finalizar la lectura de la tarjeta RFID
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
