

#ifndef Bonus_1_12__

#define Bonus_1_12__


#include "Bonus_UI.h"

class Bonus_1_12 :public Bonus_UI 
{
public:
	Bonus_1_12(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 300;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


