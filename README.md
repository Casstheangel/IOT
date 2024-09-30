## Projeto: Horta Automática com Sensor de Umidade do Solo
-----------------------------------
objetivo: Uma orta automática que através do sensor irá verificar a 
umidade do solo, regando sempre que necessário através de uma bomba ligada
ao sistema de forma automática.

# Componentes

LCD 16 x 2 - 1 unidade
Optoacoplador - 1 unidade 
12,5  Fonte de energia - 1 unidade
100 Ω Resistor - 1 unidade
220 Ω Resistor - 1 unidade
200 Ω Resistor - 1 unidade
Motor CC - 1 unidade
Arduino Uno R3 - 1 unidade
Verde LED - 1 unidade
Vermelho LED - 1 unidade
Laranja LED - 1 unidade
Azul LED - 1 unidade
250 kΩ Potenciômetro - 1 unidade
TIP120 - 1 unidade
300 Ω Resistor - 1 unidade
Relé SPDT - 1 unidade

# Codigo
 <LiquidCrystal.h>  // Inclui a biblioteca para controlar o display LCD

// Declaração de variáveis globais
int a = 0;  // Contador para loops
int b = 0;  // Contador para loops
int c = 0;  // Contador para loops

// Criação do objeto lcd com os pinos de conexão
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);  // Inicia a comunicação serial a 9600 bps
  pinMode(A1, INPUT);  // Define o pino A1 como entrada (sensor de umidade)
  pinMode(10, OUTPUT); // Pino 10 como saída
  pinMode(9, OUTPUT);  // Pino 9 como saída
  pinMode(8, OUTPUT);  // Pino 8 como saída
  pinMode(7, OUTPUT);  // Pino 7 como saída (bomba)
  pinMode(6, OUTPUT);  // Pino 6 como saída (LED)

  lcd.begin(16, 2);    // Inicializa o LCD com 16 colunas e 2 linhas
}

void loop() {
  // Lê o valor analógico do sensor de umidade
  float saida = analogRead(A1);
  
  // Normaliza o valor lido (0-1023) para uma porcentagem (0-100)
  saida = (saida / 1023) * 100; 

  // Condição para umidade baixa (0% a 40%)
  if (saida <= 40) { 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade do Solo");  
    lcd.setCursor(0, 1);
    lcd.print(saida);
    lcd.print("% Baixa  ");
    digitalWrite(10, LOW);  // Desliga LED no pino 10
    digitalWrite(9, LOW);   // Desliga LED no pino 9
    digitalWrite(8, HIGH);  // Liga LED no pino 8 (indica baixa umidade)
    delay(3000);            // Espera 3 segundos

    // Sequência para ligar a água
    for (a = 3; a >= 1; a--) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ligando a Agua");
      lcd.setCursor(0, 1);
      lcd.println(a);
      delay(3000); // Espera 3 segundos
    }

    // Regando a planta
    for (a = 5; a >= 0; a--) {
      digitalWrite(7, HIGH); // Liga a bomba de água
      lcd.setCursor(0, 0);
      lcd.print("Regar a Planta");
      lcd.setCursor(0, 1);
      lcd.println(a);
      delay(1000); // Espera 1 segundo
    }

    digitalWrite(7, LOW); // Desliga a bomba de água

    // Loop para nova leitura
    for (c = 3; c >= 0; c--) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nova Leitura");
      lcd.setCursor(0, 1);
      lcd.println(c);
      digitalWrite(10, HIGH); // Liga LED no pino 10
      delay(900);             // Espera 0,9 segundos
      digitalWrite(10, LOW);  // Desliga LED no pino 10
      delay(600);             // Espera 0,6 segundos
    }
  }

  // Condição para umidade média (40% a 75%)
  if (saida > 40 && saida <= 75) { 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade do Solo");    
    lcd.setCursor(0, 1);
    lcd.print(saida);
    lcd.print("% Media  ");
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH); // Liga LED no pino 9 (indica umidade média)
    digitalWrite(8, LOW);
    delay(3000); // Espera 3 segundos

    // Sequência para ligar a água
    lcd.clear();
    for (a = 3; a >= 1; a--) {
      lcd.setCursor(0, 0);
      lcd.print("Ligando a Agua");
      lcd.setCursor(0, 1);
      lcd.println(a);
      delay(3000); // Espera 3 segundos 
    }

    // Regando a planta
    for (a = 3; a >= 0; a--) {
      digitalWrite(7, HIGH); // Liga a bomba de água
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Regar a Planta");
      lcd.setCursor(0, 1);
      lcd.println(a);
      delay(1000); // Espera 1 segundo
    }

    digitalWrite(7, LOW); // Desliga a bomba de água

    // Loop para nova leitura
    for (c = 3; c >= 0; c--) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nova Leitura");
      lcd.setCursor(0, 1);
      lcd.println(c);
      digitalWrite(9, HIGH); // Liga LED no pino 9
      delay(900);             // Espera 0,9 segundos
      digitalWrite(9, LOW);  // Desliga LED no pino 9
      delay(600);             // Espera 0,6 segundos
    }
  }

  // Condição para umidade alta (> 75%)
  if (saida > 75) { 
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.print("Umidade do Solo");    
    lcd.setCursor(0, 1);
    lcd.print(saida);
    lcd.print("% Alta  ");
    digitalWrite(8, LOW);  // Desliga LED no pino 8
    digitalWrite(9, LOW);   // Desliga LED no pino 9
    digitalWrite(10, HIGH); // Liga LED no pino 10 (indica umidade alta)
    delay(3000);  // Espera 3 segundos
    digitalWrite(10, LOW); // Desliga LED no pino 10
    digitalWrite(9, LOW);   // Desliga LED no pino 9
    digitalWrite(8, LOW);   // Desliga LED no pino 8

    // Pisca LED azul
    for (b = 10; b >= 0; b--) {
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("Aguardando");
      lcd.setCursor(0, 1);
      lcd.println(b);
      digitalWrite(6, HIGH); // Liga LED no pino 6
      delay(900); // Espera 0,9 segundos
      digitalWrite(6, LOW);  // Desliga LED no pino 6
      delay(600); // Espera 0,6 segundos 
    }
  }
}
