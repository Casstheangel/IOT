int sensorPIR = 3;
int buzzer = 5;

void setup() {
  pinMode(sensorPIR, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int detectarPresenca = digitalRead(sensorPIR);
  
  if (detectarPresenca == 1) {
    // Frequências típicas de sirenes
    tone(buzzer, 660); // Tom agudo
    delay(500);        // Meio segundo
    tone(buzzer, 440); // Tom grave
    delay(500);        // Meio segundo
  } else {
    noTone(buzzer);    // Desligar o buzzer quando não há detecção
  }
}
