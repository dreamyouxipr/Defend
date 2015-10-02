
#ifndef Tower_Star_Bullet__
#define Tower_Star_Bullet__


#include "TowerBullet_UI.h"


class Tower_Star_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Star_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);


	virtual void Destory(void *p);




};




#endif // !TowerBase


