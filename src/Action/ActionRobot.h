#ifndef ACTION_ROBOT
#define ACTION_ROBOT

#include "../data/Data.h"

class ActionRobot {
		
	protected:
		Data* data;
	
	public:
		ActionRobot(Data* data);
		virtual void perform() = 0;
		virtual bool isFinished() = 0;
};

#endif
