#include "loop.h"

Timer* initTimer(int miliseconds){
	Timer* timer = (Timer*) malloc(sizeof(Timer));
	timer->miliseconds = miliseconds-3000;
	timer->rest = 0;
	timer->end = false;
	return timer;
}

void launchLoop(Data* data, Timer* timer, ActionRobot** actions, int nbActions){
	pthread_t timerThread;
	char buffer[150];
	int actualAction = 0;
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "t", 1);
	read_s(data->arduino[EXTERN_ARDUINO], (uint8_t *) buffer, 1);
	pthread_create(&timerThread, NULL, launchTimer, timer);
	while(!timer->end){
		if(actualAction < nbActions){

			if(actions[actualAction]->isFinished()){
				actualAction++;
			}
			else{
				actions[actualAction]->perform();
			}
		}
		usleep(20000);
	}
	write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);
	sleep(5);
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "a", 1);
}

void* launchTimer(void* timer_void){
	Timer* timer = (Timer*) timer_void;
	int i;
	for(i = 0; i < timer->miliseconds; i+=50){
		usleep(50000);
		timer->rest = i;
		if(timer->rest % 1000 == 0){
			printf("miliseconds : %d\n", timer->rest);
		}
	}
	timer->end = true;
	pthread_exit(NULL);
}
