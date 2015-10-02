
#ifndef Tower_Shit_Bullet__
#define Tower_Shit_Bullet__


#include "TowerBullet_UI.h"


class Tower_Shit_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Shit_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);


	virtual void Destory(void*p)
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;



	}



};




#endif // !TowerBase


