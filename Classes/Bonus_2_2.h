

#ifndef Bonus_2_2__

#define Bonus_2_2__


#include "Bonus_UI.h"

class Bonus_2_2 :public Bonus_UI 
{
public:
	Bonus_2_2(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 300;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


