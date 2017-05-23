
#include <Servo.h>

Servo PinchServo;
Servo RotateServo; 
// create servo objects to control a servo
// a maximum of eight servo objects can be created

int posPinchServo = 0;
// variable to store the pinch servo position
int posRotateServo = 0;
// variable to store the rotate servo position

void setup() {
  // put your setup code here, to run once:
  PinchServo.attach(7); // attaches the pinch servo on pin 7 to the servo object
  RotateServo.attach(6); // attaches the rotate servo on pin 6 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:

  // Pinch servo tests
  //PinchServo.write(180); // 180 fermé
  //PinchServo.write(60); // 60 ouvert

  // Position initiale (verticale)
  RotateServo.write(84);
  delay(500);
   
  ouverturePince();
  delay(500);
  fermeturePince();
  delay(500);

  //Rotation d'un quart de tour -> position horizontale
  RotateServo.write(175);
  delay(500);
  RotateServo.write(84);
  delay(500);

  //On dépose le cylindre
  deposerCylindre();
  delay(500);
  fermeturePince();

  //Remise en position initiale
  RotateServo.write(84);

  //Attente fin cycle
  delay(10000);
}

void ouverturePince(){
  // ouverture de la pince
  // pour modifier la vitesse, il faut modifier le delay
  for(posPinchServo = 180; posPinchServo > 59; posPinchServo -=1)
  {
    PinchServo.write(posPinchServo);
    delay(8);
  }
}

void fermeturePince(){
  // fermeture de la pince
  // pour modifier la vitesse, il faut modifier le delay
  for(posPinchServo = 60; posPinchServo <= 180; posPinchServo +=1)
  {
    PinchServo.write(posPinchServo);
    delay(8);
  }
}

void rotateToHorizontal(){
  for(posRotateServo = 180; posRotateServo = 89; posRotateServo -=1)
  {
    RotateServo.write(posPinchServo);
    delay(8);
  }
}

void rotateToVertical(){
  
}

void deposerCylindre(){
  RotateServo.write(155);
  delay(500);
  ouverturePince();
}

