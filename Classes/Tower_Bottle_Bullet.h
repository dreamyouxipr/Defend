
#ifndef Tower_Bottle_Bullet__
#define Tower_Bottle_Bullet__


#include "TowerBullet_UI.h"


class Tower_Bottle_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Bottle_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);



	~Tower_Bottle_Bullet()
	{
		//log("~~~~Tower_Bottle_Bullet");

	}

	virtual void Destory(void *p)
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;



	}



};




#endif // !TowerBase


