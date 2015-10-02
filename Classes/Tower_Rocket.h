

#ifndef Tower_Rocket__

#define Tower_Rocket__

/*9*/


#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Rocket :public Tower_UI
{

public:
	Tower_Rocket(Node*scene, Vec2 pos, int lev);

	void sync_buttle();
	virtual void clearBullet(){}
	virtual void Destory();
	virtual void Delete()
	{
		setClick(false);

		setTarget(0);
		for (int i = 0; i < bullet_queue.size(); i++)
		{
			bullet_queue[i]->Destory(0);
		}
		bullet_queue.clear();

		sprite_base->removeFromParentAndCleanup(true);
		effect->removeFromParentAndCleanup(true);
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

private:


};




#endif // 


