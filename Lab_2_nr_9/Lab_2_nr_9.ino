#include <Servo.h> // importera servo biblioteket

const int8_t EN1 = 11;
const int8_t IN1 = 13;
const int8_t IN2 = 12; // gir pin-ane beskrivande namn
const int potPin = A0; // potpin er no photoresistorane, ikkje potmeter
const int servoPin = 9;

Servo servo;

void setup() {
  pinMode(EN1, OUTPUT); // gir pin-ane funksjon
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(potPin, INPUT);
  servo.attach(servoPin); // pin-en til servoen har litt meir spesiell
  // fuksjon frå biblioteket dens
}


void loop(){
  int fart = analogRead(potPin); // leser av signalet frå photoresistorane

  int grader = map(fart, 0, 1023, 0, 180); // overføre forholdet mellom signalet på spekteret 0 til 1023,
                                           //til spekteret 0 til 180
  servo.write(grader);// skriv kva grader servoen skal stille seg inn på. 
  delay(20); // ein liten delay den ikkje skal bytte stille for fort.

  if (fart < 460){
    float framover = map(fart, 0, 480, 180, 80); // resten er likt frå oppg. 5.
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
