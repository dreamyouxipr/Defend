

#ifndef Bonus_2_7__

#define Bonus_2_7__


#include "Bonus_UI.h"

class Bonus_2_7:public Bonus_UI 
{
public:
	Bonus_2_7(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1128;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


