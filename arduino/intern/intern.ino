#include <fuzzy_table.h>
#include <PID_Beta6.h>

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>

#include <MotorWheel.h>
#include <Omni3WD.h>

#include <SONAR.h>
#include <EEPROM.h>

SONAR s11=SONAR(0x11);
SONAR s12=SONAR(0x12);
SONAR s13=SONAR(0x13);

// Motors

irqISR(irq1,isr1);
MotorWheel wheel1(9,8,6,7,&irq1);        // Pin9:PWM, Pin8:DIR, Pin6:PhaseA, Pin7:PhaseB

irqISR(irq2,isr2);
MotorWheel wheel2(10,11,14,15,&irq2);    // Pin10:PWM, Pin11:DIR, Pin14:PhaseA, Pin15:PhaseB

irqISR(irq3,isr3);
MotorWheel wheel3(3,2,4,5,&irq3);        // Pin3:PWM, Pin2:DIR, Pin4:PhaseA, Pin5:PhaseB

Omni3WD Omni(&wheel1,&wheel2,&wheel3);


int pulse1 = 0;
int pulse2 = 0;
int pulse3 = 0;

int calculDistanceAvance(int tilt){
    return 80*tilt/350;
}
int calculDistanceRecule(int tilt){
    return 80*tilt/350;
}
int calculDistanceTourne(int tilt){
    return 80*tilt/350;
}

int mouvement(int tilt1,int tilt2,int tilt3){
    int tiltAction1 = tilt1-pulse1;
    int tiltAction2 = tilt2-pulse2;
    int tiltAction3 = tilt3-pulse3;
    int valeur;
    if(tiltAction1 < 0 && tiltAction2 < 0 && tiltAction3 < 0 ){
        valeur = calculDistanceTourne((tiltAction1 + tiltAction2 + tiltAction3)/3);
    }
    else if(tiltAction1 > 0 && tiltAction2 > 0 && tiltAction3 > 0 ){
        valeur = calculDistanceTourne((tiltAction1 + tiltAction2 + tiltAction3)/3);
    }
    else if(tiltAction1 > 0 ){
        valeur = calculDistanceAvance((tiltAction1+tiltAction2)/2);
    }
    else{
        valeur = calculDistanceRecule((tiltAction1+tiltAction2)/2);
    }
    return valeur;
}

void getDistance(){
    char s[150];
    sprintf(s, "#%d!", mouvement(wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse()));
    Serial.print(s);
}

void getAngle(){
     char s[150];
     sprintf(s, "#%d!", mouvement(wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse()));
     Serial.print(s); 
}

void getPulses(){
	char s[150];
	sprintf(s, "#%ld-%ld-%ld!", wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse());
	Serial.print(s);
}

void forward(){
	Omni.setCarAdvance(200);
}

void backward(){
	Omni.setCarBackoff(200);
}

void turnLeft(){
	Omni.setCarRotateLeft(200);
}

void turnRight(){
	Omni.setCarRotateRight(200);
}

void stop(){
	Omni.setCarSlow2Stop(100);
	Omni.delayMS(100);
}

void sonar(){

	char tampon[25];

	//Récupération des données des capteurs
    s11.trigger();
    s12.trigger();
    s13.trigger();
    
    delay(SONAR::duration);
    
    //Affichage
    
    //s11.showDat();
	
	sprintf(tampon, "#%x:%x:%x!", s11.getDist(), s12.getDist(), s13.getDist());
    Serial.print(tampon);
}

void setup() {
  TCCR1B=TCCR1B&0xf8|0x01;    // Pin9,Pin10 PWM 31250Hz
  TCCR2B=TCCR2B&0xf8|0x01;    // Pin3,Pin11 PWM 31250Hz

  //
  Omni.PIDEnable(0.46,0.2,0,10);
  Serial.begin(19200);
  /*wheel3.runPWM(50, HIGH);
  wheel2.runPWM(50, LOW);*/
  stop();
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
				Serial.print("#i!");
				break;
			case 's':
				stop();
				break;
			case 'f':
				forward();
				break;
			case 'b':
				backward();
				break;
			case 'r':
				turnRight();
				break;
			case 'l':
				turnLeft();
				break;
			case 'u':
				sonar();
				break;
			case 'p':
				getPulses();
				break;
		}
	}
	
	Omni.delayMS(100);

}
