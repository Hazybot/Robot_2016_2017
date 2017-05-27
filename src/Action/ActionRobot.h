#ifndef ACTION_ROBOT
#define ACTION_ROBOT

#include "../data/Data.h"

class ActionRobot {
		
	protected:
		Data* data;
		bool finished;
	
	public:
		ActionRobot(Data* data);
		virtual void perform() = 0;
		bool isFinished();
};

#endif
