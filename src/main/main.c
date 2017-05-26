#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../serial/SerialTraitment.h"
#include "loop.h"

int main(int argc, char** argv){

	Data* data = initialiseData();
	int test = openArduino(data->arduino, NB_ARDUINO) != 0;
	if(test != 0){
		freeData(data);
		return test;
	}

	Timer* timer = initTimer(90);
	launchLoop(data, timer);

	closeArduino(data->arduino, NB_ARDUINO);
	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
