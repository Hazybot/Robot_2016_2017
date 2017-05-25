#include <stdio.h>

int trig = 2;
int echo = 3;
long lecture_echo;
long cm;

Servo PinchServo;
Servo RotateServo; 
// create servo objects to control a servo
// a maximum of eight servo objects can be created

int posPinchServo = 0;
// variable to store the pinch servo position
int posRotateServo = 0;
// variable to store the rotate servo position

Servo funnyActionServo;

int posFunnyActServo = 0;


void getDistanceAvant(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  
  char tampon[25];
  cm = lecture_echo / 58;
  sprintf(tampon,"#distAvant:%ld!",cm);
  Serial.println(tampon);
  delay(10);
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
  //Rotation d'un quart de tour -> position verticale
  delay(100);
  RotateServo.write(84);
  delay(100);
}

void deposerCylindre(){
  RotateServo.write(155);
  delay(500);
  ouverturePince();
}

void launchFunnyAction(){
  funnyActionServo.write(90); 
}


void setup() {
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  PinchServo.attach(7); // attaches the pinch servo on pin 7 to the servo object
  RotateServo.attach(5); // attaches the rotate servo on pin 6 to the servo object
  
  funnyActionServo.attach(11);
}

void loop() {

  if(Serial.available()){
		char data = '\0';
		int i = 0;
		char car = '\0';
		do{
			car = Serial.read();
			if(car != '#' && car != '!'){
				data = car;
			}
		}while(Serial.available() && car != '!');

		switch(data){
			case 'i':
				Serial.print("#e!");
				break;
			case 'u':
				getDistanceAvant();
				break;
			case 'o':
				ouverturePince();
				break;
			case 'c':
				fermeturePince();
				break;
			case 'h':
				rotateToHorizontal();
				break;
			case 'v':
				rotateToVertical();
				break;
			case 'a':
				launchFunnyAction();
				break;
		}
	}
	
	delay(100);

}
