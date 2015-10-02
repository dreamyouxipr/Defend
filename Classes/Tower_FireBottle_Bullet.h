
#ifndef Tower_FireBottle_Bullet__
#define Tower_FireBottle_Bullet__


#include "TowerBullet_UI.h"


class Tower_FireBottle_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_FireBottle_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);


	virtual void Destory(void *p);


};




#endif // 


