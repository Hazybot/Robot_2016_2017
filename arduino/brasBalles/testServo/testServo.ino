#include <Servo.h>

/*position pour la pince*/
#define POS_OUVERTE 35
#define POS_FERME 180


/*position pour le bras*/
#define POS_ATTRAPE 15
#define POS_MID 90
#define POS_STOCK 180

Servo pince;
Servo bras;

int flag = 1;

void setup(){
   pince.attach(6);
   bras.attach(5);
   Œ
   bras.write(POS_STOCK);
   pince.write(POS_FERME);
  
}

void loop(){
  moveToGrap();
}


void moveToGrap(){
    bras.write(POS_MID);
    delay(1000);
    pince.write(POS_OUVERTE);
    delay(1000);
    bras.write(POS_ATTRAPE);
    delay(1000);
    pince.write(POS_FERME);
    delay(1000);
    bras.write(POS_STOCK);
    delay(1500);
    pince.write(POS_OUVERTE);
    delay(1000);
    bras.write(POS_STOCK);
    delay(1000);
    pince.write(POS_FERME);
    delay(1000);
}
