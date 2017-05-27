#include <string.h>

#include <fuzzy_table.h>
#include <PID_Beta6.h>

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>

#include <MotorWheel.h>
#include <Omni3WD.h>

#include <SONAR.h>
#include <EEPROM.h>

// Motors

irqISR(irq1,isr1);
MotorWheel wheel1(9,8,6,7,&irq1);        // Pin9:PWM, Pin8:DIR, Pin6:PhaseA, Pin7:PhaseB

irqISR(irq2,isr2);
MotorWheel wheel2(10,11,14,15,&irq2);    // Pin10:PWM, Pin11:DIR, Pin14:PhaseA, Pin15:PhaseB

irqISR(irq3,isr3);
MotorWheel wheel3(3,2,4,5,&irq3);        // Pin3:PWM, Pin2:DIR, Pin4:PhaseA, Pin5:PhaseB

Omni3WD Omni(&wheel1,&wheel2,&wheel3);

int time = 0;
int aaa = 0;
char lettre;

void advance(int miliseconds){
	int i;
	char* s = (char*) malloc(20 * sizeof(char));
	Omni.setCarAdvance(200);
	for(i = 1; i < miliseconds / 200 && time < 90000; i++){
		Omni.delayMS(200, false);
                time += 200;
	}
       	Omni.setCarStop();
        sprintf(s, "%ld-%ld-%ld\n", wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse());
        Serial.print(s);
        time+=200;
	free(s);
}

void recule(int miliseconds){
	int i;
	char* s = (char*) malloc(20 * sizeof(char));
	Omni.setCarAdvance(200);
	for(i = 1; i < miliseconds / 200 && time < 90000; i++){
		Omni.delayMS(200, false);
                time += 200;
	}
       	Omni.setCarStop();
        sprintf(s, "%ld-%ld-%ld\n", wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse());
        Serial.print(s);
        time+=200;
	free(s);
}

void tourneGauche(int miliseconds){
	int i;
	char* s = (char*) malloc(20 * sizeof(char));
	Omni.setCarRotateLeft(200);
	for(i = 1; i < miliseconds / 200; i++){
		Omni.delayMS(200, false);
                time += 200;
	}
        Omni.setCarStop();
        sprintf(s, "%ld-%ld-%ld\n", wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse());
        Serial.print(s);
        time += 200;
	free(s);
}

void tourneDroite(int miliseconds){
	int i;
	char* s = (char*) malloc(20 * sizeof(char));
        Omni.setCarRotateRight(200);
	for(i = 1; i < miliseconds / 200; i++){
		Omni.delayMS(200, false);
                time += 200;
	}
	Omni.setCarStop();
        sprintf(s, "%ld-%ld-%ld\n", wheel1.getCurrPulse(), wheel2.getCurrPulse(), wheel3.getCurrPulse());
        Serial.print(s);
        time += 200;
	free(s);
}



void setup() {
  TCCR1B=TCCR1B&0xf8|0x01;    // Pin9,Pin10 PWM 31250Hz
  TCCR2B=TCCR2B&0xf8|0x01;    // Pin3,Pin11 PWM 31250Hz

  //
  Omni.PIDEnable(0.46,0.2,0,10);
  Serial.begin(19200);
  /*wheel3.runPWM(50, HIGH);
  wheel2.runPWM(50, LOW);*/

  advance(300);
}

void loop() {
  
  if((lettre = Serial.read())!= -1){
    if(lettre == 'a'){
      aaa = 1;
    }
    if(lettre == 'r'){
      aaa = 6;
    }        
    if(lettre == 'g'){
      aaa = 10;
    }
    if(lettre == 'd'){
      aaa = 15;
    }
    if(lettre == 'u'){
       aaa = 0; 
    }
  }
  if(0 <aaa && aaa < 4){
     advance(aaa*500);
     aaa++;
  }
  if(5 <aaa && aaa < 9){
     recule((aaa-5)*500);
     aaa++;
  }
    if(10 <aaa && aaa < 14){
     tourneGauche((aaa-10)*500);
     aaa++;
  }
    if(15 <aaa && aaa < 19){
     tourneDroite((aaa-15)*500);
     aaa++;
  }
}
