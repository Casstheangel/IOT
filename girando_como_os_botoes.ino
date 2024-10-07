#include <Servo.h>

// Criando objeto do tipo Servo
Servo objservo;

// Variáveis para o servo e os botões
int servo = 2;
int botaoAvancar = 4;
int botaoRetornar = 8;
int posicao = 0;

void setup() {
  // Inicializando o servo motor na porta especificada
  objservo.attach(servo);
  
  // Posicionando o servo inicialmente em 0°
  objservo.write(0);
  
  // Definindo os pinos dos botões como entrada com pull-up interno
  pinMode(botaoAvancar, INPUT_PULLUP);
  pinMode(botaoRetornar, INPUT_PULLUP);
}

void loop() {
  // Se o primeiro botão for pressionado (LOW, pois estamos usando INPUT_PULLUP)
  if (digitalRead(botaoAvancar) == LOW && posicao < 180) {
    posicao++; // Incrementa a posição
    objservo.write(posicao); // Move o servo para a nova posição
    delay(50); // Pequena pausa para suavizar o movimento
  }
  
  // Se o segundo botão for pressionado (LOW, pois estamos usando INPUT_PULLUP)
  if (digitalRead(botaoRetornar) == LOW) {
    posicao = 0; // Define a posição como 0
    objservo.write(posicao); // Move o servo para 0°
    delay(50); // Pequena pausa para suavizar o movimento
  }
}
