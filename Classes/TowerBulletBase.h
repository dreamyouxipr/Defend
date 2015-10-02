
#ifndef TowerBulletBase__

#define TowerBulletBase__

#include "object.h"

class TowerBulletBase
{
public:
	float moveSpeed;/*越大越快*/
	int damage;
	int level;
	virtual void initTowerBulletBase(int lev) = 0;


};



#endif // !TowerBase


