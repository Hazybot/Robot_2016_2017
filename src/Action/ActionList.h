#ifndef ACTION_LIST
#define ACTION_LIST

#include "ActionRobot.h"

class ActionMove : public ActionRobot {
	
	private:
		double distance;
	
	public:
		//distance in centimeter, positif for forward, negatif for backward
		ActionMove(Data* data, double distance): ActionRobot(data){
			this->distance = distance;
		}
		void perform();
};

class ActionTurn : public ActionRobot {
	
	private:
		double degree;
	
	public:
		//degree in degree, positif for right, negatif for left
		ActionTurn(Data* data, double degree): ActionRobot(data){
			this->degree = degree;
		}
		void perform();
};

class ActionPince : public ActionRobot {
	
	private:
		bool open;
	
	public:
		//open if true, close if false
		ActionPince(Data* data, bool open): ActionRobot(data){
			this->open = open;
		}
		void perform();
};

#endif
