#include <Servo.h>

Servo funnyActionServo;

int posFunnyActServo = 0;

void setup(){
  funnyActionServo.attach(11);
}

void loop() {
delay(500);
launchFunnyAction();
delay(500);
}

void launchFunnyAction(){
  funnyActionServo.write(90); 
}
