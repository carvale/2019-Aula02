
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

#define BCOEFFICIENT 3950
#define TEMPERATURENOMINAL 25
#define SERIESRESISTOR 10000  
#define THERMISTORNOMINAL 10000  


// Definição das variáveis
float Vo = 0 ;    //Inicializa Variável Valor Entrada Analógica


void setup()
{
  Serial.begin(9600); //Set da velocidade 9600 bps
}
void loop()
{
  Vo = analogRead(Sensor);     //Lendo Entrada Analógica

  Serial.print("Analog=");   //Print Valor na Serial
  Serial.println(Vo);  //Print Valor Entrada Analógica na Serial
  
  Vo = 1023 / Vo - 1;
  Vo = SERIESRESISTOR / Vo;

  Serial.print("R1=");   //Print Valor na Serial
  Serial.println(Vo);  //Print Valor Entrada Analógica na Serial

  
  float steinhart;
  steinhart = Vo / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C

  
  
  Serial.print("Temperatura *C=");   //Print Valor na Serial
  Serial.println(steinhart);  //Print Valor Entrada Analógica na Serial
  

  delay(1000);

}
