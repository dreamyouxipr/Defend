

#ifndef Tower_Star__

#define Tower_Star__


/*3*/

#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Star :public Tower_UI
{

public:
	Tower_Star(Node*scene, Vec2 pos, int lev);


	virtual void Destory();
	virtual void Delete()
	{
		setClick(false);
		for (int i = 0; i < bullet_queue.size(); i++)
		{
			bullet_queue[i]->Destory(target);
		}

		setTarget(0);

		bullet_queue.clear();
		sprite_upgrade->removeFromParentAndCleanup(true);
		sprite_base->removeFromParentAndCleanup(true);
		effect->removeFromParentAndCleanup(true);
		sprite->removeFromParentAndCleanup(true);

		delete this;
	}
	virtual void initTowerBase();
	virtual void setLevel(int lev);
	virtual Animate*getAttackAction();
	virtual void setClick(bool t);
	virtual void sync_Attack(Vec2 pos, int width);
	virtual void sync_None();

	virtual void clearBullet();
private:


};




#endif 


