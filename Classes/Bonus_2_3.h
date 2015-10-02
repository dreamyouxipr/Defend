

#ifndef Bonus_2_3__

#define Bonus_2_3__


#include "Bonus_UI.h"

class Bonus_2_3 :public Bonus_UI 
{
public:
	Bonus_2_3(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 300;
		hp_now = hp;
		money = 50;

	}
	
	
};





#endif // 


