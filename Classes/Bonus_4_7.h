

#ifndef Bonus_4_7__

#define Bonus_4_7__


#include "Bonus_UI.h"

class Bonus_4_7:public Bonus_UI 
{
public:
	Bonus_4_7(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 2200;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


