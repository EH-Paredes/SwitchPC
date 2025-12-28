#define BLYNK_TEMPLATE_ID //introducir id blynk
#define BLYNK_TEMPLATE_NAME //introducir nombre blynk
#define BLYNK_AUTH_TOKEN  //introducir token blynk
#define BLYNK_PRINT Serial 
#include <WiFi.h> 
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h>
char ssid[] = ; //introducir ssid
char pass[] = ;//introducir contraseña
const int relePin = 12; 
void setup() { 
  Serial.begin(115200); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
  pinMode(relePin, OUTPUT); 
  digitalWrite(relePin, LOW); 
} 
BLYNK_WRITE(V1) { 
  int pinValue = param.asInt(); 
  if (pinValue == 1) {
   digitalWrite(relePin, HIGH);
    Serial.println("Relé activado"); 
  } else {
    digitalWrite(relePin, LOW); 
    Serial.println("Relé desactivado"); 
  } 
} 
void loop() {
  Blynk.run(); 
}