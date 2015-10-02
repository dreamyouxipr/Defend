

#ifndef Bonus_1_10__

#define Bonus_1_10__


#include "Bonus_UI.h"

class Bonus_1_10 :public Bonus_UI 
{
public:
	Bonus_1_10(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 300;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


