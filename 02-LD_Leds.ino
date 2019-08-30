
// Define o pino dos LEDs
#define LedVd D0
#define LedAm D1
#define LedVm D2
#define LedAz D4
#define Botao D3


String st1; // Variável String

void setup()
{
  Serial.begin(9600); //Set da velocidade 9600 bps

  pinMode(LedVd, OUTPUT); // Define LED como Saida
  digitalWrite(LedVd, LOW); // Desliga o LED

  pinMode(LedAm, OUTPUT); // Define LED como Saida
  digitalWrite(LedAm, LOW); // Desliga o LED

  pinMode(LedVm, OUTPUT); // Define LED como Saida
  digitalWrite(LedVm, LOW); // Desliga o LED

  pinMode(LedAz, OUTPUT); // Define LED como Saida
  digitalWrite(LedAz, LOW); // Desliga o LED

  Serial.println();
  Serial.println("4 LEDS"); // Imprime na Serial
  delay(2000);
}
void loop()
{
  while (Serial.available())
  {
    int resultado;
    st1 = Serial.readString();
    Serial.println("Foi digitado:" + st1);


    // Led Verde
    resultado = st1.indexOf("VDL"); // VerDe Ligar
    if (resultado != -1) {
      digitalWrite(LedVd, HIGH);
      Serial.println("Led Verde ligado.");
    }
    resultado = st1.indexOf("VDD"); // VerDe Desligar
    if (resultado != -1) {
      digitalWrite(LedVd, LOW);
      Serial.println("Led Verde desligado.");
    }

   // Led Amarelo
    resultado = st1.indexOf("AML"); // AMarelo Ligar
    if (resultado != -1) {
      digitalWrite(LedAm, HIGH);
      Serial.println("Led Amarelo ligado.");
    }
    resultado = st1.indexOf("AMD"); // AMarelo Desligar
    if (resultado != -1) {
      digitalWrite(LedAm, LOW); 
      Serial.println("Led Amarelo desligado.");
    }

    // Led Vermelho
    resultado = st1.indexOf("VML"); // VerMelho Ligar
    if (resultado != -1) {
      digitalWrite(LedVm, HIGH);
      Serial.println("Led Vermelho ligado.");
    }
    resultado = st1.indexOf("VMD"); // VerMelho Desligar
    if (resultado != -1) {
      digitalWrite(LedVm, LOW); 
      Serial.println("Led Vermelho desligado.");
    }

     // Led Azul
    resultado = st1.indexOf("AZL"); // VerMelho Ligar
    if (resultado != -1) {
      digitalWrite(LedAz, HIGH);
      Serial.println("Led Azul ligado.");
    }
    resultado = st1.indexOf("AZD"); // VerMelho Desligar
    if (resultado != -1) {
      digitalWrite(LedAz, LOW); 
      Serial.println("Led Azul desligado.");
    }


  }
}
