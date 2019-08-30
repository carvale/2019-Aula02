
// Define o pino dos LEDs
#define LedVd D0
#define LedAm D1
#define LedVm D2
#define LedAz D4
#define Botao1 D3
#define Botao2 D5


String st1; // Variável String

void setup()
{
  Serial.begin(9600); //Set da velocidade 9600 bps

  pinMode(Botao1, INPUT_PULLUP); //
  pinMode(Botao2, INPUT_PULLUP); //

  pinMode(LedVd, OUTPUT); // Define LED como Saida
  digitalWrite(LedVd, LOW); // Desliga o LED

  pinMode(LedAm, OUTPUT); // Define LED como Saida
  digitalWrite(LedAm, LOW); // Desliga o LED

  pinMode(LedVm, OUTPUT); // Define LED como Saida
  digitalWrite(LedVm, LOW); // Desliga o LED

  pinMode(LedAz, OUTPUT); // Define LED como Saida
  digitalWrite(LedAz, LOW); // Desliga o LED

  Serial.println();
  Serial.println("4 LEDS + 2 Botoes"); // Imprime na Serial
  delay(2000);
}
void loop()
{

  // Desliga os Led com Botao 1 Apertado
  boolean estadoBotao1 = digitalRead(Botao1);
  //Serial.println(estadoBotao1);

  if (!estadoBotao1) {
    digitalWrite(LedVd, LOW);
    digitalWrite(LedAm, LOW);
    digitalWrite(LedVm, LOW);
    digitalWrite(LedAz, LOW);
    Serial.println("Todos os Leds Desligados.");
  }

  // Liga os Led com Botao 2 Apertado
  boolean estadoBotao2 = digitalRead(Botao2);
  //Serial.println(estadoBotao2);

  if (!estadoBotao2) {
    digitalWrite(LedVd, HIGH);
    digitalWrite(LedAm, HIGH);
    digitalWrite(LedVm, HIGH);
    digitalWrite(LedAz, HIGH);
    Serial.println("Todos os Leds ligado.");
  }



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
