

#ifndef Bonus_1_11__

#define Bonus_1_11__


#include "Bonus_UI.h"

class Bonus_1_11:public Bonus_UI 
{
public:
	Bonus_1_11(Node*p,Vec2 pos);

	virtual void initBase()
	{
		hp = 1128;
		hp_now = hp;
		money = 150;

	}
	
};





#endif // 


