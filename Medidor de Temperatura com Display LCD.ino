#include <LiquidCrystal_I2C.h>

// Definir LCD com endereço I2C, 16 colunas e 2 linhas
LiquidCrystal_I2C telaLcd(0x20, 16, 2);

int sensorTMP = A1;
int valorlido = 0;

void setup() {
  pinMode(sensorTMP, INPUT);     // Configura o sensor como entrada
  telaLcd.init();                // Inicializa o LCD
  telaLcd.clear(); 
  // Limpa qualquer dado do display
  telaLcd.backlight();
}

void loop() {
  // Captura o valor do sensor de temperatura
  valorlido = analogRead(sensorTMP);

  // Converte o valor lido em tensão (assumindo que 5V é a referência do ADC)
  float tensao = (valorlido * 5.0) / 1024.0;

  // Converte a tensão em graus Celsius
  float temperatura = (tensao - 0.5) * 100.0; // Fórmula correta para TMP36

  // Exibe a temperatura no LCD
  telaLcd.setCursor(0, 0);
  telaLcd.print("Temperatura:");
  
  telaLcd.setCursor(0, 1);
  telaLcd.print(temperatura);
  telaLcd.print(" C");

  delay(1000); // Aguarda 1 segundo antes de atualizar
}
