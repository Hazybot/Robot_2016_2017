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

int getDistanceValue(Data* data){
	char buffer[150];
	write_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) "p", 1);
	read_s(data->arduino[EXTERN_ARDUINO], (uint8_t*) buffer, 150);
	char* correction = readCorrection(buffer);
	int result = atoi(correction);
	free(correction);
	return result;
}

void ActionMove::perform(){
	if(firstTime){
		this.initPulse = getDistanceValue(this->data);
		if(direction == 1){
			write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
		}
		else if(direction == 0){
			write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "b", 1);
		}
		else{
			write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);	
		}
		firstTime = false;
	}
	else{
		int obstacle = getSensorValue(this->data);
		int currentPulse = getDistanceValue(this->data);
		distanceAFaire = this.distance - (this.initPulse - currentPulse);
		
		if(obstacle < 20){
			write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "b", 1);	
		}
		else{
			if(distanceAFaire > 0){
				if(direction == 1){
					write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "f", 1);
				}
				else if(direction == 0){
					write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "b", 1);
				}
				else{
					write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);	
				}	
			}
			else{
				write_s(data->arduino[INTERN_ARDUINO], (uint8_t*) "s", 1);
				this.finished = true;
			}
		}
	}
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
