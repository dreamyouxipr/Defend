#ifndef Tower_Sun__

#define Tower_Sun__
/*8*/

#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Sun :public Tower_UI
{

public:
	Tower_Sun(Node*scene, Vec2 pos, int lev);

	unsigned int Music_ID;
	virtual void Delete();
	virtual void Destory();
	virtual void initTowerBase();
	virtual void setLevel(int lev);
	virtual Animate*getAttackAction();
	virtual void setClick(bool t);
	virtual void sync_Attack(Vec2 pos, int width);
	virtual void sync_None();
	virtual void clearBullet(){}
private:

	Sprite*sprite_bullet_effect;


};




#endif // 


