

#ifndef Bonus_3_7__

#define Bonus_3_7__


#include "Bonus_UI.h"

class Bonus_3_7:public Bonus_UI 
{
public:
	Bonus_3_7(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1776;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


