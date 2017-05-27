#include "ActionList.h"

int getSensorValue(Data* data){
	char buffer[150];
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "u", 1);
	read_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) buffer, 150);
	char* correction = readCorrection(buffer);
	int result = atoi(correction);
	free(correction);
	return result;
}

int getDistanceValues(Data* data){
	char buffer[150];
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "p", 1);
	read_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) buffer, 150);
	char* correction = readCorrection(buffer);
	int result = atoi(correction);
	free(correction);
	return result;
}

void ActionMove::perform(){
	
}

void ActionTurn::perform(){
	
}

void ActionPince::perform(){
	if(open){
		write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "o", 1);
	}
	else{
		write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "c", 1);
	}
}

void ActionImage::perform(){
	
}