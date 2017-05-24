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

void moyenneImage(IplImage imageMoyenne,IplImage imageActuel){
    int index = 0;
    uchar *p;
    uchar *c;
    for(index = 0 ; index < imageMoyenne.imageSize ; index++){
        p = cvPtr2D(imageMoyenne,index/imageMoyenne.height,index%imageMoyenne.height,NULL);
        c = cvPtr2D(imageActuel,index/imageActuel.height,index%imageActuel.height,NULL);
        *p = ((*p)*TAMPON_MOYENNE-1+*c)/TAMPON_MOYENNE;
    }
}

void moyenneImagePrecis(IplImage imageMoyenne,IplImage imageActuel, int debutLigne,int debutColonne){
    int index = 0;
    int x;
    int y;
    uchar *p;
    uchar *c;
    for(x = 0 ; x < imageMoyenne.width ; x++){
        for(y = 0 ; y < imageMoyenne.height ; y++){
            index = x*imageMoyenne.height+y;
            p = cvPtr2D(imageMoyenne,index/imageMoyenne.height,index%imageMoyenne.height,NULL);
            c = cvPtr2D(imageActuel,debutLigne+index/imageActuel.height,debutLigne+index%imageActuel.height,NULL);
            *p = ((*p)*TAMPON_MOYENNE-1+*c)/TAMPON_MOYENNE;
        }
    }
}
