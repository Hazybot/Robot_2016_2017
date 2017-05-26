#include "ActionRobot.h"
	
ActionRobot::ActionRobot(Data* data){
	this->finished = false;
	this->data = data;
}

bool ActionRobot::isFinished(){
	return this->finished;
}