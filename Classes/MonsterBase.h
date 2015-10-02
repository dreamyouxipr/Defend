#ifndef MonsterBase__

#define MonsterBase__

#include "object.h"



class MonsterBase
{
public:
	int hp;/*血量*/
	int hp_now;/**/
	float moveSpeed;/* 越大越满慢，移动速度*/
	float moveSpeed_readOnly;
	int money;
	int moveDir=8;
	int damage;

	virtual void initBase() {};
	void setHP(int h);

	~MonsterBase()
	{
		//log("~~~~MonsterBase");
	}
};




#endif // !MonsterBase__


