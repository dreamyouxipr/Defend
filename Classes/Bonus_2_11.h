

#ifndef Bonus_2_11__

#define Bonus_2_11__


#include "Bonus_UI.h"

class Bonus_2_11:public Bonus_UI 
{
public:
	Bonus_2_11(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1128;
		hp_now = hp;
		money = 150;

	}
	
	
};





#endif // 


