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
	actions[0] = new ActionPince(data, true); nbAction++;
	actions[1] = new ActionTurn(data, 10, 0); nbAction++;
	actions[2] = new ActionMove(data, 20, 1); nbAction++;
	actions[3] = new ActionPince(data, false); nbAction++;
	actions[4] = new ActionTurn(data, 180, 1); nbAction++;
	actions[5] = new ActionPince(data, true); nbAction++;
	actions[6] = new ActionMove(data, 5, 0); nbAction++;
	actions[7] = new ActionPince(data, false); nbAction++;
	actions[8] = new ActionPince(data, true); nbAction++;
	 actions[9] = new ActionPince(data, false); nbAction++;
        actions[10] = new ActionPince(data, true); nbAction++;
	 actions[11] = new ActionPince(data, false); nbAction++;
        actions[12] = new ActionPince(data, true); nbAction++;
	 actions[13] = new ActionPince(data, false); nbAction++;
        actions[14] = new ActionPince(data, true); nbAction++;
	 actions[15] = new ActionPince(data, false); nbAction++;
        actions[16] = new ActionPince(data, true); nbAction++;
	//actions[0] = new ActionMove(data, 20, 1); nbAction++;
	launchLoop(data, timer, actions, nbAction);

	closeArduino(data->arduino, NB_ARDUINO);
	freeData(data);

	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

	return 0;
}
