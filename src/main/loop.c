#include "loop.h"

Timer* initTimer(int seconds){
	Timer* timer = malloc(sizeof(Timer));
	timer->seconds = seconds-3;
	timer->rest = 0;
	timer->end = false;
	return timer;
}

void launchLoop(Data* data, Timer* timer){
	pthread_t timerThread;
	bool stop = false;
	char buffer[150];
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "t", 1);
	read_s(data->arduino[EXTERN_ARDUINO], (uint8_t *) buffer, 1);
	printf("Tirette");	
	pthread_create(&timerThread, NULL, launchTimer, timer);
	write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
	while(!timer->end){
		if(!stop){
			write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "u", 1);
                        read_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) buffer, 150);
			char* lol = strtok(buffer, "!");
			int sensor = atoi(lol);
			if(sensor < 25)
			{
				stop = true;
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);
			}
                        if(timer->rest >= 3){
				stop = true;
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);
			}
		}
	}
	sleep(5);
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "a", 1);
}

void* launchTimer(void* timer_void){
	Timer* timer = (Timer*) timer_void;
	int i;
	for(i = 0; i < timer->seconds; i++){
		sleep(1);
		timer->rest++;
		printf("Seconds : %d\n", timer->rest);
	}
	timer->end = true;
	pthread_exit(NULL);
}
