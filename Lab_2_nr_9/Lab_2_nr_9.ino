#include <Servo.h>

const int8_t EN1 = 11;
const int8_t IN1 = 13;
const int8_t IN2 = 12;
const int potPin = A0;
const int servoPin = 9;

Servo servo;

void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(potPin, INPUT);
  servo.attach(servoPin);
}

void raskare(int pin){
  for(int i = 80; i < 200; i++){
    analogWrite(pin, i);
    delay(50);
  }
}


void saktare(int pin){
  for(int i = 200; i > 80; i--){
    analogWrite(pin, i);
    delay(50);
  }
}


void loop(){
  int fart = analogRead(potPin);

  int grader = map(fart, 0, 1023, 0, 180);
  servo.write(grader);
  delay(20);

  if (fart < 460){
    float framover = map(fart, 0, 480, 180, 80);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, framover);
  }

  else if(fart > 480 && fart < 540){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, 0);
  }

  else if(fart > 540){
    float bakover = map(fart, 540, 1024, 80, 180);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN1, bakover);
  }
}
