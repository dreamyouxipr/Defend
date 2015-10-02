

#ifndef Bonus_3_2__

#define Bonus_3_2__


#include "Bonus_UI.h"

class Bonus_3_2 :public Bonus_UI 
{
public:
	Bonus_3_2(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 480;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


