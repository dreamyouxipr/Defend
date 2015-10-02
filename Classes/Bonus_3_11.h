

#ifndef Bonus_3_11__

#define Bonus_3_11__


#include "Bonus_UI.h"

class Bonus_3_11:public Bonus_UI 
{
public:
	Bonus_3_11(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1776;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


