#include <LiquidCrystal.h>
int a =0;
int b = 0;
int c = 0;
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7 ,OUTPUT);
  pinMode(6, OUTPUT);

    lcd.begin(16, 2);
}

void loop() {
          
  float saida = analogRead(A1);
  
saida = (saida/1023);
saida = saida* 100.; 
    
     if ( saida <= 40) { 
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Umidade do Solo");  
     lcd.setCursor(0,1);
     lcd.print(saida);
     lcd.print("% Baixa  ");
     digitalWrite(10,LOW);
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     delay (3000);//Espera 3 segundos
  
// ligar agua 
    
         for (a = 3; a >= 1; a -= 1) {
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("Ligando a Agua");
           lcd.setCursor(0,1);
           lcd.println(a);
           delay(3000); // Espera 3 segundos
         }
       
// REGANDO 
       
         for (a = 5; a >= 0; a -= 1) {
   
           digitalWrite(7,HIGH);
           lcd.setCursor(0,0);
           lcd.print("Regar a Planta");
           lcd.setCursor(0,1);
           lcd.println(a);
           delay(1000); // Espera 1 segundo
         }
       
         
         digitalWrite(7,LOW); 
    
  
        for (c = 3; c >= 0; c -= 1) {
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Nova Leitura");
          lcd.setCursor(0,1);
          lcd.println(c);
          digitalWrite(10, HIGH);
          delay(900); // Espera 0,9 segundos
          digitalWrite(10, LOW);
          delay(600); // Espera 0,6 segundos
           
        }
       
     }

  
     if ( saida > 40 && saida <= 75) { 
       
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Umidade do Solo");    
       lcd.setCursor(0,1);
       lcd.print(saida);
       lcd.print("% Media  ");
       digitalWrite(10,LOW);
       digitalWrite(9,HIGH);
       digitalWrite(8,LOW);
       delay (3000);// espera 3 segundos
       
// ligar agua
       
       lcd.clear();
    
       for (a = 3; a >= 1; a -= 1) {
    
         lcd.setCursor(0,0);
         lcd.print("Ligando a Agua");
         lcd.setCursor(0,1);
         lcd.println(a);
         delay(3000); // Espera 3 segundos 
      }
       
// REGANDO 
       
       for (a = 3; a >= 0; a -= 1) {
   
         digitalWrite(7,HIGH);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Regar a Planta");
         lcd.setCursor(0,1);
         lcd.println(a);
         delay(1000); // Espera 1 segundo
       }
       
       
       digitalWrite(7,LOW); 
    
       for (c = 3; c >= 0; c -= 1) {
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Nova Leitura");
         lcd.setCursor(0,1);
         lcd.println(c);
         digitalWrite(9, HIGH);
         delay(900); // Espera 0,9 segundo
         digitalWrite(9, LOW);
         delay(600); // Espera 0,6 segundo
         
       }  
    
    
     }
  
     if ( saida > 75) { 
       
       lcd.clear();  
       lcd.setCursor(0,0);
       lcd.print("Umidade do Solo");    
       lcd.setCursor(0,1);
       lcd.print(saida);
       lcd.print("% Alta  ");
       digitalWrite(8,LOW);
       digitalWrite(9,LOW);
       digitalWrite(10,HIGH);
       delay(3000);  // Espera 3 segundos
       digitalWrite(10,LOW);
       digitalWrite(9,LOW);
       digitalWrite(8,LOW);
    
//pisca led azul     
       
        for (b = 10; b >= 0; b -= 1) {
    
          
          lcd.clear(); 
          lcd.setCursor(0,0);
          lcd.print("Aguardando");
          lcd.setCursor(0,1);
          lcd.println(b);
          digitalWrite(6, HIGH);
          delay(900); //Espera 0,9 segundos
          digitalWrite(6, LOW);
          delay(600); // Espera 0,6 segundos 
         
       }
    
     }
  
}
  