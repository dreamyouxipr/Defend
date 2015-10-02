

#ifndef Bonus_4_6__

#define Bonus_4_6__


#include "Bonus_UI.h"

class Bonus_4_6:public Bonus_UI 
{
public:
	Bonus_4_6(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1100;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


