#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../serial/SerialTraitment.h"
#include "../Action/ActionRobot.h"
#include "../Action/ActionList.h"
#include "loop.h"

int main(int argc, char** argv){

	Data* data = initialiseData();
	int test = openArduino(data->arduino, NB_ARDUINO) != 0;
	if(test != 0){
		freeData(data);
		return test;
	}

	Timer* timer = initTimer(90000);
	int nbAction = 0;
	ActionRobot** actions = (ActionRobot**) malloc(150*sizeof(ActionRobot*));
	actions[0] = new ActionMove(data, 20, 1); nbAction++;
	launchLoop(data, timer, actions, nbAction);

	closeArduino(data->arduino, NB_ARDUINO);
	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
