// C++ code
//biblioteca do lcd
#include <LiquidCrystal.h>
// criar variavel do lcd
LiquidCrystal lcd (2,3,4,9,10,11,12);

int ledLcd = 13;

long distancia(int trigger, int echo ){
  
  pinMode(trigger,OUTPUT);
  digitalWrite(trigger,LOW);
  delay(5);
  
  digitalWrite(trigger,HIGH);
   delay(10);
   digitalWrite(trigger,LOW);
  
  pinMode (echo,INPUT);
  return pulseIn(echo,HIGH);

}
 void setup()
{
  pinMode (ledLcd,OUTPUT);// DEFINIR LEDLCD SAIDA
  digitalWrite(ledLcd, HIGH); // LIGAR OS LEDS DO LCD
  lcd.begin(16,2);//informar que  o lcd tem 16 colunas e 2 linhas
  lcd.clear();// iniciar lcd limpo
  
}

void loop()

{
    int cm = 0.01723 * distancia(8, 8);
  
  if(cm<100){
    lcd.setCursor(0,0);//iniciar a escrita na linha 0 coluna 0
    lcd.print("Proxima Parada ");
    lcd.setCursor(0,1);
    lcd.print("Santa ines, MA");
    
  }else{
     lcd.clear();
      
  }
  
  
}