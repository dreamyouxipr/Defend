

#ifndef Bonus_3_8__

#define Bonus_3_8__


#include "Bonus_UI.h"

class Bonus_3_8 :public Bonus_UI 
{
public:
	Bonus_3_8(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 480;
		hp_now = hp;
		money = 50;

	}

	
};





#endif // 


