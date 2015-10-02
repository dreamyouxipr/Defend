
#ifndef Tower_Ball_Bullet__
#define Tower_Ball_Bullet__


#include "TowerBullet_UI.h"


class Tower_Ball_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Ball_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);



	~Tower_Ball_Bullet()
	{
		//log("~~~~Tower_Bottle_Bullet");

	}

	virtual void Destory(void *p);


};




#endif // 


