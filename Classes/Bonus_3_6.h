

#ifndef Bonus_3_6__

#define Bonus_3_6__


#include "Bonus_UI.h"

class Bonus_3_6:public Bonus_UI 
{
public:
	Bonus_3_6(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1776;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


