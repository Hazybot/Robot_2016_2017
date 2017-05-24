#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calculAngle.h"

extern double angle;
extern int positionX;
extern int positionY;

const int diametreRoue = 100;//100 ou 123 en mm
const int nbTilt = 64;
const int diametreRobot = 300;//en mm

void mouvement(int tilt1,int tilt2,int tilt3){
    if(tilt1 > 0 && tilt2 > 0 && tilt3 > 0){
        tourne((tilt1+tilt2+tilt3)/3);
    }
    else if(tilt1 < 0 && tilt2 < 0 && tilt3 < 0){
        tourne((tilt1+tilt2+tilt3)/3);
    }
    else{
        avance((tilt1-tilt2)/2);
    }
}

void tourne(int valeur){
    angle = angle + (valeur*diametreRoue)/(nbTilt*diametreRobot);
}

void avance(int valeur){
    positionX = (diametreRoue*valeur/nbTilt)*cos(angle);
    positionY = (diametreRoue*valeur/nbTilt)*sin(angle);
}
