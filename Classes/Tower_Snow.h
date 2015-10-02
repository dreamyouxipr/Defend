#ifndef Tower_Snow__

#define Tower_Snow__

/*12*/


#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Snow :public Tower_UI
{

public:
	Tower_Snow(Node*scene, Vec2 pos, int lev);


	virtual void Destory();
	virtual void Delete()
	{

		setClick(false);
		setTarget(0);
		sprite_base->removeFromParentAndCleanup(true);
		effect->removeFromParentAndCleanup(true);
		sprite_bullet_effect->removeFromParentAndCleanup(true);
		sprite_upgrade->removeFromParentAndCleanup(true);
		sprite->removeFromParentAndCleanup(true);

		delete this;

	}
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


