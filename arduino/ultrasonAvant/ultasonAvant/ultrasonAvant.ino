#include <stdio.h>

int trig = 2;
int echo = 3;
long lecture_echo;
long cm;

void setup()
{
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  getDistanceAvant();
}

void getDistanceAvant(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  
  char tampon[25];
  cm = lecture_echo / 58;
  sprintf(tampon,"distAvant:%ld",cm);
  Serial.println(tampon);
  delay(10);
}
