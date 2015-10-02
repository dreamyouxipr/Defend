

#ifndef Tower_FireBottle__

#define Tower_FireBottle__

/*6*/
#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_FireBottle :public Tower_UI
{

public:
	Tower_FireBottle(Node*scene, Vec2 pos, int lev);


	virtual void Destory();
	virtual void Delete()
	{

		setClick(false);

		setTarget(0);

		sprite_base->removeFromParentAndCleanup(true);
		effect->removeFromParentAndCleanup(true);
		sprite_upgrade->removeFromParentAndCleanup(true);

		sprite_bullet_effect->removeFromParentAndCleanup(true);

		sprite->removeFromParentAndCleanup(true);

		delete this;


	}
	virtual void initTowerBase();
	virtual void setLevel(int lev);
	virtual Animate*getAttackAction();
	virtual void setClick(bool t);
	virtual void sync_Attack(Vec2 pos, int width);
	virtual void sync_None();

private:

	Sprite*sprite_bullet_effect;


};




#endif // !TowerBase


