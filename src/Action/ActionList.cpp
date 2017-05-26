#include "ActionList.h"

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