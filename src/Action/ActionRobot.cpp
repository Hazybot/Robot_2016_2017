#include "ActionRobot.h"
	
ActionRobot::ActionRobot(Data* data){
	this->finish = false;
	this->data = data;
}

bool ActionRobot::isFinish(){
	return this->finish;
}