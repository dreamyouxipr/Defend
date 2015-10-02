

#ifndef Bonus_4_1__

#define Bonus_4_1__


#include "Bonus_UI.h"

class Bonus_4_1 :public Bonus_UI 
{
public:
	Bonus_4_1(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 308;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


