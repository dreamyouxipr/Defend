

#ifndef Bonus_2_4__

#define Bonus_2_4__


#include "Bonus_UI.h"

class Bonus_2_4 :public Bonus_UI 
{
public:
	Bonus_2_4(Node*p,Vec2 pos,bool is_flip=false);

	virtual void initBase()
	{
		hp = 732;
		hp_now = hp;
		money = 75;

	}
	
	
};





#endif // 


