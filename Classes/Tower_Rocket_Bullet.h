
#ifndef Tower_Rocket_Bullet__
#define Tower_Rocket_Bullet__


#include "TowerBullet_UI.h"


class Tower_Rocket_Bullet :public TowerBullet_UI 
{


public:


	virtual void initTowerBulletBase(int lev);

	Tower_Rocket_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos_target);


	virtual void Destory(void *p);

	vector<void*> queue_attacked;

	virtual bool isExist(void *p);/*已被攻击 标记*/

	~Tower_Rocket_Bullet()
	{
		queue_attacked.clear();


	}
 

};




#endif //


