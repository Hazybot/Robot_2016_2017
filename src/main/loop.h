#ifndef LOOP
#define LOOP

	#include <stdbool.h>
	#include <pthread.h>

	#include "../data/Data.h"
	#include "../serial/SerialTraitment.h"

	typedef struct Timer Timer;
	struct Timer{
		int seconds;
		bool end;
		int rest;
	};

	Timer* initTimer(int seconds);

	void launchLoop(Data* data, Timer* timer);

	void* launchTimer(void* timer);

#endif


