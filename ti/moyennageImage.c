#include "opencv/highgui.h"
e
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define sign(x) ((x) > 0 ? 1 : -1)

#define STEP_MIN 5
#define STEP_MAX 100

#define TAMPON_MOYENNE 5

void moyenneImage(cv::Mat imageMoyenne,cv::Mat imageActuel,int taille){
    int index = 0;
    uchar *p = imageActuel.ptr();
    uchar *c = imageMoyenne.ptr();
    for(index = 0 ; index < imageMoyenne.imageSize ; index++){
        *p = ((*p+index)*TAMPON_MOYENNE-1+*(c+index))/TAMPON_MOYENNE;
    }
}

/*void moyenneImagePrecis(cv::Mat imageMoyenne,cv::Mat imageActuel,int taille,int debutLigne,int debutColonne){
    int index = 0;
    int x;
    int y;
    uchar *p;
    uchar *c;
    for(x = 0 ; x < imageMoyenne.width ; x++){
        for(y = 0 ; y < imageMoyenne.height ; y++){
            index = x*imageMoyenne.height+y;
            *p = ((*p+index)*TAMPON_MOYENNE-1+*(c+index))/TAMPON_MOYENNE;
        }
    }
}*/
