#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//On considère que l'on connait la position des tour en x,y donner par :
const int X1 = 0;
const int Y1 = 0;

const int X2 = 1;
const int Y2 = 10;

const int X3 = 10;
const int Y3 = 2;

//const int rapport1_2 = (X1*X1-X2*X2+Y1*Y1-Y2*Y2);
//const int rapport1_3 = (X1*X1-X3*X3+Y1*Y1-Y3*Y3);
//const int rapportConstanteY; = (2*((Y2-Y1)*(X3-X1)-(Y3-Y1)*(X2-X1)));

void calculPosition(int *positionX,int *positionY, int distance1,int distance2,int distance3){
    /*
        distance1 = (X-X1)^2+(Y-Y1)^2;
        distance2 = (X-X2)^2+(Y-Y2)^2;
        distance3 = (X-X3)^2+(Y-Y3)^2;

        distance1-distance2 = 2*(X2-X1)*X+2*(Y2-Y1)*Y+X1^2-X2^2+Y1^2-Y2^2;
        distance1-distance3 = 2*(X3-X1)*X+2*(Y3-Y1)*Y+X1^2-X3^2+Y1^2-Y3^2;

        (distance1-distance2)*(X3-X1) = 2*(X2-X1)*(X3-X1)*X+(X3-X1)*(2*(Y2-Y1)*Y+X1^2-X2^2+Y1^2-Y2^2);
        (distance1-distance3)*(X2-X1) = 2*(X3-X1)*(X2-X1)*X+(X2-X1)*(2*(Y3-Y1)*Y+X1^2-X3^2+Y1^2-Y3^2);

        (distance1-distance2)*(X3-X1)-(distance1-distance3)*(X2-X1)
        -(X3-X1)*(X1^2-X2^2+Y1^2-Y2^2)+(X2-X1)*(X1^2-X3^2+Y1^2-Y3^2)
            = 2*((X3-X1)*(Y2-Y1)-(X2-X1)*(Y3-Y1))*Y


        (distance1-distance2)*(X3-X1)-(distance1-distance3)*(X2-X1)-(X3-X1)*(X1^2-X2^2+Y1^2+Y2^2)+(X3-X1)*(+X1^2-X3^2+Y1^2+Y3^2) =
         2*((Y3-Y1)(X2-X1)-(Y3-Y1)(X2-X1))*Y;
         Y =
         ((distance1-distance2)*(X3-X1)-(distance1-distance3)*(X2-X1)-(X3-X1)*(X1^2-X2^2+Y1^2+Y2^2)+(X3-X1)*(+X1^2-X3^2+Y1^2+Y3^2))/
         (2*((Y3-Y1)(X2-X1)-(Y3-Y1)(X2-X1)));
        X = (distance1-distance2)*(X3-X1)-(X3-X1)*(-2*(Y2-Y1)*Y+X1^2-X2^2+Y1^2+Y2^2)/2*(X2-X1)*(X3-X1);

        //(distance1-distance2-2*(Y2-Y1)*Y-X1^2+X2^2-Y1^2+Y2^2)/(2*(X2-X1)) = X;
    */
    int variable = (distance1*distance1-distance2*distance2)*(X3-X1)-(distance1*distance1-distance3*distance3)*(X2-X1);
    int variable2 = (2*((Y2-Y1)*(X3-X1)-(Y3-Y1)*(X2-X1)));
    int variable3 = (X2-X1)*(X1*X1-X3*X3+Y1*Y1-Y3*Y3)-(X3-X1)*(X1*X1-X2*X2+Y1*Y1-Y2*Y2);
    //variable3 = (X2-X1)*(X1*X1-X3*X3+Y1*Y1-Y3*Y3)-(X3-X1)*(X1*X1-X2*X2+Y1*Y1-Y2*Y2);
    printf("%d %d %d\n",variable,variable2,variable3);
    *positionY = (variable+variable3)/variable2;
    printf("Ok");
    //(distance1-distance2-2*(Y2-Y1)*Y-X1^2+X2^2-Y1^2+Y2^2)/(2*(X2-X1)) = X;
    *positionX = (distance1*distance1-distance2*distance2-2*(Y2-Y1)*(*positionY)-X1*X1+X2*X2-Y1*Y1+Y2*Y2)/(2*(X2-X1));

}

void calculPositionfloat(float *positionX,float *positionY, float distance1,float distance2,float distance3){
    /*
        distance1 = (X-X1)^2+(Y-Y1)^2;
        distance2 = (X-X2)^2+(Y-Y2)^2;
        distance3 = (X-X3)^2+(Y-Y3)^2;

        distance1-distance2 = 2*(X2-X1)*X+2*(Y2-Y1)*Y+X1^2-X2^2+Y1^2-Y2^2;
        distance1-distance3 = 2*(X3-X1)*X+2*(Y3-Y1)*Y+X1^2-X3^2+Y1^2-Y3^2;

        (distance1-distance2)*(X3-X1) = 2*(X2-X1)*(X3-X1)*X+(X3-X1)*(2*(Y2-Y1)*Y+X1^2-X2^2+Y1^2-Y2^2);
        (distance1-distance3)*(X2-X1) = 2*(X3-X1)*(X2-X1)*X+(X2-X1)*(2*(Y3-Y1)*Y+X1^2-X3^2+Y1^2-Y3^2);

        (distance1-distance2)*(X3-X1)-(distance1-distance3)*(X2-X1)
        -(X3-X1)*(X1^2-X2^2+Y1^2-Y2^2)+(X2-X1)*(X1^2-X3^2+Y1^2-Y3^2)
            = 2*((X3-X1)*(Y2-Y1)-(X2-X1)*(Y3-Y1))*Y


        (distance1-distance2)*(X3-X1)-(distance1-distance3)*(X2-X1)-(X3-X1)*(X1^2-X2^2+Y1^2+Y2^2)+(X3-X1)*(+X1^2-X3^2+Y1^2+Y3^2) =
         2*((Y3-Y1)(X2-X1)-(Y3-Y1)(X2-X1))*Y;
         Y =
         ((distance1-distance2)*(X3-X1)-(distance1-distance3)*(X2-X1)-(X3-X1)*(X1^2-X2^2+Y1^2+Y2^2)+(X3-X1)*(+X1^2-X3^2+Y1^2+Y3^2))/
         (2*((Y3-Y1)(X2-X1)-(Y3-Y1)(X2-X1)));
        X = (distance1-distance2)*(X3-X1)-(X3-X1)*(-2*(Y2-Y1)*Y+X1^2-X2^2+Y1^2+Y2^2)/2*(X2-X1)*(X3-X1);

        //(distance1-distance2-2*(Y2-Y1)*Y-X1^2+X2^2-Y1^2+Y2^2)/(2*(X2-X1)) = X;
    */
    float variable = (distance1*distance1-distance2*distance2)*(X3-X1)-(distance1*distance1-distance3*distance3)*(X2-X1);
    float variable2 = (2*((Y2-Y1)*(X3-X1)-(Y3-Y1)*(X2-X1)));
    float variable3 = (X2-X1)*(X1*X1-X3*X3+Y1*Y1-Y3*Y3)-(X3-X1)*(X1*X1-X2*X2+Y1*Y1-Y2*Y2);
    //variable3 = (X2-X1)*(X1*X1-X3*X3+Y1*Y1-Y3*Y3)-(X3-X1)*(X1*X1-X2*X2+Y1*Y1-Y2*Y2);
    //printf("%d %d %d\n",variable,variable2,variable3);
    *positionY = (variable+variable3)/variable2;
    //(distance1-distance2-2*(Y2-Y1)*Y-X1^2+X2^2-Y1^2+Y2^2)/(2*(X2-X1)) = X;
    *positionX = (distance1*distance1-distance2*distance2-2*(Y2-Y1)*(*positionY)-X1*X1+X2*X2-Y1*Y1+Y2*Y2)/(2*(X2-X1));

}

/*void calculPosition(int *positionX,int *positionY, int distance1,int distance2,int distance3){

}*/

void calculDistance(int *distance1,int *distance2,int* distance3,int positionX,int positionY){
    *distance1 = sqrt((positionX-X1)*
                      (positionX-X1)+
                      (positionY-Y1)*
                      (positionY-Y1));
    *distance2 = sqrt((positionX-X2)*
                      (positionX-X2)+
                      (positionY-Y2)*
                      (positionY-Y2));
    *distance3 = sqrt((positionX-X3)*
                      (positionX-X3)+
                      (positionY-Y3)*
                      (positionY-Y3));
    printf("%d %d %d\n",*distance1,*distance2,*distance3);
}


void calculDistancefloat(float *distance1,float *distance2,float* distance3,float positionX,float positionY){
    *distance1 = sqrt((positionX-X1)*
                      (positionX-X1)+
                      (positionY-Y1)*
                      (positionY-Y1));
    *distance2 = sqrt((positionX-X2)*
                      (positionX-X2)+
                      (positionY-Y2)*
                      (positionY-Y2));
    *distance3 = sqrt((positionX-X3)*
                      (positionX-X3)+
                      (positionY-Y3)*
                      (positionY-Y3));
    printf("Distance %f %f %f\n",*distance1,*distance2,*distance3);
}
