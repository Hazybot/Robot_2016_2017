#include <SONAR.h>

SONAR s11=SONAR(0x11);
SONAR s12=SONAR(0x12);
SONAR s13=SONAR(0x13);

void setup() {
    SONAR::init();
    delay(100);
    //s11.setAddr(0x11); // Warning!! It will set hardware address of all connected SONAR sensors to the given value
}

void loop() {
  
    //Récupération des données des capteurs
    s11.trigger();
    s12.trigger();
    s13.trigger();
    
    delay(SONAR::duration);
    
    //Affichage
    
    //s11.showDat();
    Serial.println(s11.getDist(),DEC);
    Serial.println(s11.getTemp(),DEC);
    
    Serial.println(s12.getDist(),DEC);
    Serial.println(s12.getTemp(),DEC);
    
    Serial.println(s13.getDist(),DEC);
    Serial.println(s13.getDist(),DEC);

    delay(500);
}


