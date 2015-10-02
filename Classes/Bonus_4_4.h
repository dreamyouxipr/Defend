

#ifndef Bonus_4_4__

#define Bonus_4_4__


#include "Bonus_UI.h"

class Bonus_4_4 :public Bonus_UI 
{
public:
	Bonus_4_4(Node*p,Vec2 pos,bool is_flip=false);

	virtual void initBase()
	{
		hp = 748;
		hp_now = hp;
		money = 75;

	}
	
	
};





#endif // 


