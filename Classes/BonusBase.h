#ifndef BonusBase__

#define BonusBase__

#include "object.h"



class BonusBase
{
public:
	int hp;
	int hp_now;

	int money;

	bool is_selected;

	virtual void initBase() = 0;/* */

};




#endif // 


