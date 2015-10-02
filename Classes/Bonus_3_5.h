

#ifndef Bonus_3_5__

#define Bonus_3_5__


#include "Bonus_UI.h"

class Bonus_3_5:public Bonus_UI 
{
public:
	Bonus_3_5(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 960;
		hp_now = hp;
		money = 75;

	}
	
	
};





#endif // 


