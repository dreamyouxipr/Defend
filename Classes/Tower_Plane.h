

#ifndef Tower_Plane__

#define Tower_Plane__


/*13*/

#include "Tower_UI.h"

#include "PublicFunc.h"

class Tower_Plane :public Tower_UI
{

public:
	Tower_Plane(Node*scene, Vec2 pos, int lev);



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
	virtual Animate*getAttackAction(){ return 0; };
	virtual void setClick(bool t);
	virtual void sync_Attack(Vec2 pos, int width);
	virtual void sync_None();

private:
	string s;

};




#endif // 


