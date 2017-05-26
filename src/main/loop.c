#include "loop.h"

Timer* initTimer(int miliseconds){
	Timer* timer = malloc(sizeof(Timer));
	timer->miliseconds = miliseconds-3000;
	timer->rest = 0;
	timer->end = false;
	return timer;
}

void launchLoop(Data* data, Timer* timer){
	pthread_t timerThread;
	bool stop = false;
	char buffer[150];
	CheatState state = FIRST_FORWARD;
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
            else if(timer->rest >= 3){
				stop = true;
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);
			}
			else{
				switch(state){
					case FIRST_FORWARD:
						if(timer->rest < FIRST_FORWARD_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
						}
						else{
							state = FIRST_BACKWARD;
						}
						break;
					case FIRST_BACKWARD:
						if(timer->rest < FIRST_BACKWARD_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "b", 1);
						}
						else{
							state = FIRST_RIGHT;
						}
						break;
					case FIRST_RIGHT:
						if(timer->rest < FIRST_RIGHT_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "r", 1);
						}
						else{
							state = CATCH_FORWARD;
						}
						break;
					case CATCH_FORWARD:
						if(timer->rest < CATCH_FORWARD_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
						}
						else{
							state = CLOSE_PINCE;
						}
						break;
					case CLOSE_PINCE:
						if(timer->rest < CLOSE_PINCE_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "c", 1);
						}
						else{
							state = CATCH_BACKWARD;
						}
						break;
					case CATCH_BACKWARD:
						if(timer->rest < CATCH_BACKWARD_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "b", 1);
						}
						else{
							state = DROP_RIGHT;
						}
						break;
					case DROP_RIGHT:
						if(timer->rest < DROP_RIGHT_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "r", 1);
						}
						else{
							state = DROP_FORWARD;
						}
						break;
					case DROP_FORWARD:
						if(timer->rest < DROP_FORWARD_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
						}
						else{
							state = DROP_OPEN;
						}
						break;
					case DROP_OPEN:
						if(timer->rest < DROP_OPEN_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "o", 1);
						}
						else{
							state = DROP_BACKWARD;
						}
						break;
					case DROP_BACKWARD:
						if(timer->rest < DROP_BACKWARD_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "b", 1);
						}
						else{
							state = CATCH_LEFT;
						}
						break;
					case CATCH_LEFT:
						if(timer->rest < CATCH_LEFT_TIME){
							write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "l", 1);
						}
						else{
							state = CATCH_FORWARD;
						}
						break;
				}
			}
		}
		usleep(20000);
	}
	sleep(5);
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "a", 1);
}

void* launchTimer(void* timer_void){
	Timer* timer = (Timer*) timer_void;
	int i;
	for(i = 0; i < timer->miliseconds; i+=50){
		usleep(50000);
		timer->rest = i;
		printf("miliseconds : %d\n", timer->rest);
	}
	timer->end = true;
	pthread_exit(NULL);
}
