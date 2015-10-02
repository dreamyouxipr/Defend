
#ifndef TowerBullet_UI__

#define TowerBullet_UI__




#include "TowerBulletBase.h"

//#include "PublicFunc.h"


class TowerBullet_UI :public TowerBulletBase
{
public:
	Sprite*sprite;

	virtual void Destory(void*p) = 0;
	virtual	bool isExist(void *p){ return false; }
	bool isDone;

};







#endif // !TowerBase


