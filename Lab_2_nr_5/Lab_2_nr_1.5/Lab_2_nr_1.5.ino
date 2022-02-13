const int EN1 = 11;
const int IN1 = 13;
const int IN2 = 12;
const int potPin = A0;
const int tiltPin = 2;




void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(tiltPin, INPUT);

}

void raskare(int pin){
  for(int i = 80; i < 200; i++){
    analogWrite(pin, i);
    delay(30);
  }
}

void saktare(int pin){
  for(int i = 200; i > 80; i--){
    analogWrite(pin, i);
    delay(30);
  }
}

void loop(){
  while(digitalRead(tiltPin) == HIGH){
    int fart = analogRead(potPin);
  
    if (fart < 460){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      float framover = map(fart, 0, 460, 180, 80);
      analogWrite(EN1, framover);
    }
  
    else if(fart > 460 && fart < 560){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(EN1, 0);
    }
  
    else if(fart > 560){
      float bakover = map(fart, 560, 1024, 80, 180);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(EN1, bakover);
    }
  }
}
