#ifndef LOOP
#define LOOP

	#include <stdbool.h>
	#include <pthread.h>

	#include "../data/Data.h"
	#include "../serial/SerialTraitment.h"
	
	typedef enum CheatState {FIRST_FORWARD, FIRST_BACKWARD, FIRST_RIGHT, CATCH_FORWARD, CLOSE_PINCE, CATCH_BACKWARD, DROP_RIGHT, DROP_FORWARD, DROP_OPEN, DROP_BACKWARD, CATCH_LEFT} CheatState;
	
	#define FIRST_FORWARD_TIME 2000
	#define FIRST_BACKWARD_TIME FIRST_FORWARD_TIME + 700
	#define FIRST_RIGHT_TIME FIRST_BACKWARD_TIME + 2000
	#define CATCH_FORWARD_TIME FIRST_RIGHT_TIME + 2000
	#define CLOSE_PINCE_TIME CATCH_FORWARD_TIME + 2000
	#define CATCH_BACKWARD_TIME CLOSE_PINCE_TIME + 2000
	#define DROP_RIGHT_TIME CATCH_BACKWARD_TIME + 2000
	#define DROP_FORWARD_TIME DROP_RIGHT_TIME + 2000
	#define DROP_OPEN_TIME DROP_FORWARD_TIME + 2000
	#define DROP_BACKWARD_TIME DROP_OPEN_TIME + 2000
	#define CATCH_LEFT_TIME DROP_BACKWARD_TIME + 2000

	typedef struct Timer Timer;
	struct Timer{
		int miliseconds;
		bool end;
		int rest;
	};

	Timer* initTimer(int seconds);

	void launchLoop(Data* data, Timer* timer);

	void* launchTimer(void* timer);

#endif


