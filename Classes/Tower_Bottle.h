

#ifndef Tower_Bottle__

#define Tower_Bottle__


/*1*/

#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Bottle :public Tower_UI
{

public:
	Tower_Bottle(Node*scene, Vec2 pos, int lev);

	virtual void clearBullet(){}
	virtual void Destory();
	virtual void Delete();
	virtual void initTowerBase();
	virtual void setLevel(int lev);
	virtual Animate*getAttackAction();
	virtual void setClick(bool t);
	virtual void sync_Attack(Vec2 pos, int width);
	virtual void sync_None();

private:
	

};




#endif // 


