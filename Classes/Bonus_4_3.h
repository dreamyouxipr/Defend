

#ifndef Bonus_4_3__

#define Bonus_4_3__


#include "Bonus_UI.h"

class Bonus_4_3 :public Bonus_UI 
{
public:
	Bonus_4_3(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 610;
		hp_now = hp;
		money = 50;

	}
	
	
};





#endif // 


