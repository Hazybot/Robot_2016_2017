#ifndef ACTION_LIST
#define ACTION_LIST

#include "ActionRobot.h"
#include "../serial/Serial.h"
#include "../data/Data.h"

int getSensorValue(Data* data);
int getDistanceValue(Data* data);

class ActionMove : public ActionRobot {
	
	private:
		bool firstTime;
		double distance;
		int direction;
		int initPulse;
		bool finished;
	
	public:
		//distance in centimeter, direction positive for forward, negative for backward
		ActionMove(Data* data, double distance, int direction): ActionRobot(data){
			this->distance = distance;
			this->direction = direction;
			this->firstTime = true;
			this->initPulse = 0;
			this->finished = false;
		}
		void perform();
		bool isFinished(){
			return this->finished;
		}
};

class ActionTurn : public ActionRobot {
	
	private:
		bool firstTime;
		double degree;
		int direction;
		int initPulse;
		bool finished;
	
	public:
		//degree in degree, direction positive for forward, negative for backward
		ActionTurn(Data* data, double degree, int direction): ActionRobot(data){
			this->degree = degree;
			this->direction = direction;
			this->firstTime = true;
			this->initPulse = 0;
			this->finished = false;
		}
		void perform();
		bool isFinished(){
			return this->finished;
		}
};

class ActionPince : public ActionRobot {
	
	private:
		bool open;
		bool finished;
	
	public:
		//open if true, close if false
		ActionPince(Data* data, bool open): ActionRobot(data){
			this->open = open;
			this->finished = false;
		}
		void perform();
		bool isFinished(){
			return this->finished;
		}
};

class ActionImage : public ActionRobot {
	
	private:
		bool open;
		bool finished;
	
	public:
		//open if true, close if false
		ActionImage(): ActionRobot(NULL){
			this->open = open;
			this->finished = false;
		}
		void perform();
		bool isFinished(){
			return this->finished;
		}
};

#endif
