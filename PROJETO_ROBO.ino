#include <Servo.h>

Servo meuservo;  // Cria um objeto servo para controlar o servo motor
int triggerPin = 12;  // Pino TRIG do sensor ultrassônico
int echoPin = 13;     // Pino ECHO do sensor ultrassônico
int ledPin = 8;      // Pino do LED
int servoPin = 3;    // Pino do servo motor

void setup() {
  meuservo.attach(servoPin);  // Conecta o servo motor ao pino 3
  pinMode(triggerPin, OUTPUT);  // Define o pino TRIG (agora triggerPin) como saída
  pinMode(echoPin, INPUT);      // Define o pino ECHO como entrada
  pinMode(ledPin, OUTPUT);      // Define o pino do LED como saída
}

void loop() {
  long duracao, distancia;

  // Limpa o pino TRIG
  digitalWrite(triggerPin, LOW);
  delay(2);

  // Define o pino TRIG como HIGH por 10 microsegundos
  digitalWrite(triggerPin, HIGH);
  delay(10);
  digitalWrite(triggerPin, LOW);

  // Lê o tempo de retorno do pino ECHO
  duracao = pulseIn(echoPin, HIGH);

  // Calcula ea distância em centímetros
  distancia = duracao * 0.05534 / 2;

  // Verifica se há um obstáculo próximo
  if (distancia < 50) {  // Ajuste a distância conforme necessário
    digitalWrite(ledPin, HIGH);  // Acende o LED vermelho
    delay(1000);  // Espera 1 segundo
    meuservo.write(180);  // Gira o servo motor para 180 graus
    delay(1000);  // Espera 1 segundo
    digitalWrite(ledPin, LOW);  // Apaga o LED vermelho
  } else {
    meuservo.write(0);  // Mantém o servo motor na posição inicial
  }

  delay(500);  // Espera 500 milissegundos antes de repetir o loop
}