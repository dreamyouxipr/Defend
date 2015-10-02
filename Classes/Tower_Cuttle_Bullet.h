
#ifndef Tower_Cuttle_Bullet__
#define Tower_Cuttle_Bullet__


#include "TowerBullet_UI.h"


class Tower_Cuttle_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Cuttle_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);


	virtual void Destory(void *p);

	vector<void*> queue_attacked;


	~Tower_Cuttle_Bullet()
	{
		queue_attacked.clear();


	}
 

};




#endif //


