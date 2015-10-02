

#ifndef Bonus_4_2__

#define Bonus_4_2__


#include "Bonus_UI.h"

class Bonus_4_2 :public Bonus_UI 
{
public:
	Bonus_4_2(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 308;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


