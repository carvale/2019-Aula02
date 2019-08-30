/*
  Simple DHT11
*/

#include <SimpleDHT.h>


int pinDHT11 = D6; // Pino onte está conectado o DHT11
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);

}

void loop() {
  //Variáveis
  byte temperatura = 0;
  byte umidade = 0;


  int err = SimpleDHTErrSuccess;
      
      if ((err = dht11.read(&temperatura, &umidade, NULL)) != SimpleDHTErrSuccess) {
        Serial.print("Leitua DHT11 com falha, err="); 
        Serial.println(err);
        delay(2000);
        return;
      }
      
      Serial.print("Leitura OK: ");
      Serial.print((int)temperatura); Serial.print(" *C, "); 
      Serial.print((int)umidade); Serial.println(" %");
      delay(2000);

}
