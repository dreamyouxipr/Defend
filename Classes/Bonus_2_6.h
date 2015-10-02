

#ifndef Bonus_2_6__

#define Bonus_2_6__


#include "Bonus_UI.h"

class Bonus_2_6:public Bonus_UI 
{
public:
	Bonus_2_6(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1128;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


