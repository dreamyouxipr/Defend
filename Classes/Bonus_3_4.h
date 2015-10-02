

#ifndef Bonus_3_4__

#define Bonus_3_4__


#include "Bonus_UI.h"

class Bonus_3_4 :public Bonus_UI 
{
public:
	Bonus_3_4(Node*p,Vec2 pos,bool is_flip=false);

	virtual void initBase()
	{
		hp = 960;
		hp_now = hp;
		money = 75;

	}
	
	
};





#endif // 


