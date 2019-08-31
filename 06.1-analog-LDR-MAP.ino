
// Define o pino dos LEDs
#define LedVd D0
#define LedAm D1
#define LedVm D2
#define LedAz D4

//Define pino dos Botões
#define Botao1 D3
#define Botao2 D5

//Define pino do Analógico
#define Sensor A0


// Definição das variáveis
int analogValue = 0 ;    //Inicializa Variável Valor Entrada Analógica

void setup()
{
  Serial.begin(9600); //Set da velocidade 9600 bps
}
void loop()
{
  analogValue = analogRead(Sensor);     //Lendo Entrada Analógica
  Serial.print("Valor LDR=");   //Print Valor LDR na Serial
  Serial.println(analogValue);  //Print Valor Entrada Analógica na Serial
  Serial.print("Valor %=");   //Print Valor LDR na Serial
  Serial.println(map(analogValue,0,1023,0,100));  //Print Valor Entrada Analógica na Serial

  delay(200);

}
