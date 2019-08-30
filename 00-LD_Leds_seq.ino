
// Define o pino dos LEDs
#define LedVd D0
#define LedAm D1
#define LedVm D2
#define LedAz D4
#define Botao1 D3
#define Botao2 D5


String st1; // Variável String
boolean leds = 0;

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
 
  digitalWrite(LedVd, HIGH); 
  delay(50);
  digitalWrite(LedAm, HIGH); 
  delay(50);
  digitalWrite(LedVm, HIGH); 
  delay(50);
  digitalWrite(LedAz, HIGH); 
  delay(50);
  digitalWrite(LedAz, LOW); 
  delay(50);
  digitalWrite(LedVm, LOW); 
  delay(50);
  digitalWrite(LedAm, LOW); 
  delay(50);
  digitalWrite(LedVd, LOW); 
  delay(50);
    
}
