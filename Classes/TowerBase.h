#ifndef TowerBase__

#define TowerBase__

#include "object.h"
#include"SimpleAudioEngine.h"

#include "View_Click_Tower.h"


using namespace CocosDenshion;

class TowerBase
{
public:
	int level;/*等级 123*/
	int attackRange;/*攻击半径*/
	float attackSpeed;/*攻击速度  越小越快*/
	virtual void initTowerBase() = 0;/**/
	virtual void setLevel(int lev) = 0;



};


#endif // !TowerBase


