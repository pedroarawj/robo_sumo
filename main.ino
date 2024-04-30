#define E1M1 8
#define E2M1 9 
#define E1M2 10
#define E2M2 11

#define pinSenE 13
#define pinSenD 12

#define ECHO 6 
#define TRIGGER 7

unsigned int duracao;
unsigned int distancia;

const int velocidade;

void setup() {
  pinMode(E1M1, OUTPUT);
  pinMode(E2M1, OUTPUT);
  pinMode(E2M1, OUTPUT);
  pinMode(E2M2, OUTPUT);
}

void loop() {
  
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  duracao = pulseIn(ECHO, HIGH);
  distancia = duracao * 0.0175;
  bool estadoSensorD = digitalRead(pinSenD);
  bool estadoSensorE = digitalRead(pinSenE);
  // Andar para frente
  digitalWrite(E1M1, HIGH);
  digitalWrite(E2M1, LOW);
  digitalWrite(E1M2, HIGH);
  digitalWrite(E2M2, LOW);
  
  // Ir para trás
  /*
  digitalWrite(E1M1, LOW);
  digitalWrite(E2M1, HIGH);
  digitalWrite(E1M2, LOW);
  digitalWrite(E2M2, HIGH);

  */

  // Parar
  /*
  digitalWrite(MOTOR_ESQUERDA_PINO1, LOW);
  digitalWrite(MOTOR_ESQUERDA_PINO2, LOW);
  digitalWrite(MOTOR_DIREITA_PINO1, LOW);
  digitalWrite(MOTOR_DIREITA_PINO2, LOW);
  */

  // Virar p esquerda
  /*
  digitalWrite(E1M1, LOW);
  digitalWrite(E2M1, HIGH);
  digitalWrite(E1M2, HIGH);
  digitalWrite(E2M2, LOW);
  analogWrite(MOTOR_ESQUERDA_PINO1, VELOCIDADE_MINIMA);
  analogWrite(MOTOR_DIREITA_PINO1, VELOCIDADE_MINIMA);
  */

  // Virar p direita
  /*
  digitalWrite(E1M1, HIGH);
  digitalWrite(E2M1, LOW);
  digitalWrite(E1M2, LOW);
  digitalWrite(E2M2, HIGH);
  analogWrite(MOTOR_ESQUERDA_PINO1, VELOCIDADE_MINIMA);
  analogWrite(MOTOR_DIREITA_PINO1, VELOCIDADE_MINIMA);
  */
}

/*
void setup() {
 
pinMode(11, INPUT);
pinMode(12, INPUT);
pinMode(13, INPUT);
 
pinMode(2, INPUT_PULLUP);
 
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
 
Serial.begin(9600);
 
while (digitalRead(2) == 0) {
delay(1);
stop();
Serial.println("aguardando");
}
}
 
void loop() {
 
if (!digitalRead(12) || !digitalRead(13)) {//verifica
Serial.println("linha detectada");
stop();
delay(1);
re();
delay(300);
stop();
delay(1);
girar();
delay(600);
stop();
}
 
frente();
delay(1);
}
void re() {
Serial.println("Re");
analogWrite(5, 0);
analogWrite(6, 200);
analogWrite(9, 0);
analogWrite(10, 200);
}
void frente() {
Serial.println("Frente");
analogWrite(5, 200);
analogWrite(6, 0);
analogWrite(9, 200);
analogWrite(10, 0);
}
void girar() {
Serial.println("Girando");
analogWrite(5, 0);
analogWrite(6, 200);
analogWrite(9, 200);
analogWrite(10, 0);
}
void stop() {
Serial.println("parado");
analogWrite(5, 0);
analogWrite(6, 0);
analogWrite(9, 0);
analogWrite(10, 0);
 
}*\
