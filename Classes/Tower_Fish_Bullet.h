
#ifndef Tower_Fish_Bullet__
#define Tower_Fish_Bullet__


#include "TowerBullet_UI.h"


class Tower_Fish_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Fish_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);


	virtual void Destory(void*p)
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;



	}



};




#endif // 


