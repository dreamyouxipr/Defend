

#ifndef Tower_Pin__

#define Tower_Pin__



/*10*/
#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Pin :public Tower_UI
{

public:
	Tower_Pin(Node*scene, Vec2 pos, int lev);


	virtual void Destory();
	virtual void Delete()
	{
		setClick(false);

		setTarget(0);

		for (int i = 0; i < bullet_queue.size(); i++)
		{
			bullet_queue[i]->Destory(target);

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


