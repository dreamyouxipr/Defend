

#ifndef Bonus_2_1__

#define Bonus_2_1__


#include "Bonus_UI.h"

class Bonus_2_1 :public Bonus_UI 
{
public:
	Bonus_2_1(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 300;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


