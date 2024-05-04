#define E1M1 8   
#define E2M1 9
#define E1M2 10
#define E2M2 11

#define btn 5

bool estado_botao = 0;

#define pinSenE 13
#define pinSenD 12

#define ECHO 7
#define TRIGGER 6

unsigned int duracao;
unsigned int distancia;

bool ligado = false;
int estadobotao = LOW;
int ultimoestadobotao = LOW;

void setup() {
  //MOTORES 
  pinMode(E1M1, OUTPUT);
  pinMode(E2M1, OUTPUT);
  pinMode(E1M2, OUTPUT);
  pinMode(E2M2, OUTPUT);

  //Sensor de linha
  pinMode(pinSenE, INPUT);
  pinMode(pinSenD, INPUT);

  //Sensor ultrasonico
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  
  pinMode(btn, INPUT);
}

void loop() {
  //Sensor ultrassônico
  digitalWrite(TRIGGER, LOW);
  delay(2);
  digitalWrite(TRIGGER, HIGH);
  delay(10);
  digitalWrite(TRIGGER, LOW);
  duracao = pulseIn(ECHO, HIGH);
  distancia = duracao * 0.0175;

  //sensor de linha
  bool estadoSensorD = digitalRead(pinSenD);
  bool estadoSensorE = digitalRead(pinSenE);


  desviar();
  centro();
  if (distancia < 25){
    frente();
  } else {
    parar();
  }

}

void tras(){
  analogWrite(E1M1, 160);
  analogWrite(E2M1, 0);
  analogWrite(E1M2, 160);
  analogWrite(E2M2, 0);
}

void frente(){
  analogWrite(E1M1, 0);
  analogWrite(E1M2, 0);
  analogWrite(E2M1, 200);
  analogWrite(E2M2, 200);
}

void parar(){
  analogWrite(E1M1, 0);
  analogWrite(E1M2, 0);
  analogWrite(E2M1, 0);
  analogWrite(E2M2, 0);
}

void esquerda(){
  analogWrite(E1M1, 140);
  analogWrite(E2M1, 0);
  analogWrite(E1M2, 0);
  analogWrite(E2M2, 140);
}

void direita(){
  analogWrite(E1M1, 0);
  analogWrite(E2M1, 140);
  analogWrite(E1M2, 140);
  analogWrite(E2M2, 0);
}

void desviar(){
  direita();
  delay(500);
  frente();
  delay(700);
}

void centro(){
  esquerda();
  delay(900);
  frente();
  delay(200);
  esquerda();
  delay(800);
  frente();
  delay(400);
  parar();
  delay(30000);
}

void atacar(){
    analogWrite(E1M1, 0);
    analogWrite(E1M2, 0);
    analogWrite(E2M1, 200);
    analogWrite(E2M2, 200);
}
