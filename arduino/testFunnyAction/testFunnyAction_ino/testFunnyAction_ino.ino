#include <Servo.h>

Servo funnyActionServo;

int posFunnyActServo = 0;

void setup(){
  funnyActionServo.attach(11);
  //funnyActionServo.detach();
  
  funnyActionServo.write(90); 
  delay(500);
  funnyActionServo.detach();
}

void loop() {
  
delay(900000);
//launchFunnyAction();

}

void launchFunnyAction(){
  funnyActionServo.write(90); 
  delay(500);
  funnyActionServo.detach();
}
