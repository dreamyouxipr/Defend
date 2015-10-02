

#ifndef Bonus_1_5__

#define Bonus_1_5__


#include "Bonus_UI.h"

class Bonus_1_5:public Bonus_UI 
{
public:
	Bonus_1_5(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1128;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


