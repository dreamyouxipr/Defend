

#ifndef Bonus_4_5__

#define Bonus_4_5__


#include "Bonus_UI.h"

class Bonus_4_5:public Bonus_UI 
{
public:
	Bonus_4_5(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 2200;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


