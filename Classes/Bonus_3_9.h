

#ifndef Bonus_3_9__

#define Bonus_3_9__


#include "Bonus_UI.h"

class Bonus_3_9:public Bonus_UI 
{
public:
	Bonus_3_9(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1000;
		hp_now = hp;
		money = 75;

	}
	
	
};





#endif // 


