#ifndef ACTION_ROBOT
#define ACTION_ROBOT

#include "../data/Data.h"

class ActionRobot {
	
	private:
		bool finish;
		
	protected:
		Data* data;
	
	public:
		ActionRobot(Data* data);
		virtual void perform() = 0;
		bool isFinish();
};

#endif
