// C++ code
//
int led = 7;
int sensordeluminosidade = A0;
// variavel para 
int luz =0;
void setup()
{
  // led e de saida
  pinMode(led,OUTPUT);
  // sensor e de entrada
  pinMode(sensordeluminosidade,INPUT);
}

void loop()
{
  // capturar o que o sensor leu no ambiente
  //analogRead e usado para leitura analogico
  luz = analogRead(sensordeluminosidade);
  // as portas analogicas capturam dados que variam de 0 ate 1023
  if(luz<500){
     digitalWrite(led,HIGH);//ligar led
  }else{
     digitalWrite(led,LOW);//DESLIGAR LED
  }
}