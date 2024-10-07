// C++ code
int r = 6;// porta vermelha
int g = 3;//porta verde
int b = 5;//porta azul

int R = 11;
int G = 9;
int B = 10;

void setup()
{
 pinMode(r,OUTPUT);
 pinMode(g,OUTPUT);
 pinMode(b,OUTPUT);
  
 pinMode(R,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(B,OUTPUT);
  
}

void loop()
{
  //geraçao do numeros aleatorios
  int v1 = random(0,255);
  int v2 = random(0,255);
  int v3 = random(0,255);
  
  int v4 = random(0,255);
  int v5 = random(0,255);
  int v6 = random(0,255);
  
  analogWrite(r,v1);//qual valor de 0 a 255
  analogWrite(g,v2);//qual valor de 0 a 255
  analogWrite(b,v3);//qual valor de 0 a 255
  delay(50);//espere 5 segundo
  
  analogWrite(R,v4);//qual valor de 0 a 255
  analogWrite(G,v5);//qual valor de 0 a 255
  analogWrite(B,v6);//qual valor de 0 a 255
  delay(50);//espere 5 segundo
 
}