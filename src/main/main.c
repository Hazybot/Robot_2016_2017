#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../serial/SerialTraitment.h"

int main(int argc, char** argv){

	Data* data = initialiseData();
	int test = openArduino(data->arduino, NB_ARDUINO) != 0;
	if(test != 0){
		freeData(data);
		return test;
	}

	write(data->arduino[MOTOR_ARDUINO], "6000", 4);

	closeArduino(data->arduino, NB_ARDUINO);
	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
