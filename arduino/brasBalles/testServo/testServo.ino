
#include <Servo.h>

#define POS_OUVERTE 35
#define POS_FERME 180

#define POS_ATTRAPE 10
#define POS_STOCK 180
Servo pince;
Servo bras;

int flag = 1;

void setup(){
   pince.attach(6);
   bras.attach(5);

}

void loop(){
  while(flag){
    pince.write(POS_OUVERTE);
    delay(1000);
    bras.write(POS_ATTRAPE);
    delay(1000);
    pince.write(POS_FERME);
    delay(1000);
    bras.write(POS_STOCK);
    delay(1000);
    bras.write(POS_OUVERTE);
    delay(1000);
    flag = 1;
  }
}

