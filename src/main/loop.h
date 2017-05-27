#ifndef LOOP
#define LOOP

	#include <pthread.h>

	#include "../data/Data.h"
	#include "../serial/Serial.h"
	#include "../Action/ActionRobot.h"

	typedef struct Timer Timer;
	struct Timer{
		int miliseconds;
		bool end;
		int rest;
	};

	Timer* initTimer(int miliseconds);

	void launchLoop(Data* data, Timer* timer, ActionRobot** actions, int nbActions);

	void* launchTimer(void* timer);

#endif


