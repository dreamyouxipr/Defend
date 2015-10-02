
#ifndef Tower_Anchor__
#define Tower_Anchor__


#include "Tower_UI.h"

#include "PublicFunc.h"


/*16*/
class Tower_Anchor :public Tower_UI
{

public:



	Tower_Anchor(Node*scene, Vec2 pos, int lev);

	void sync_buttle();
	virtual void Destory();
	virtual void Delete()
	{

		


			setClick(false);

	

			for (int i = 0; i < bullet_queue.size(); i++)
			{
				bullet_queue[i]->Destory(target);
			}

			for (int i = 0; i < bullet_queue1.size(); i++)
			{
				bullet_queue1[i]->Destory(target);
			}


			setTarget(0);

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

	vector<TowerBullet_UI*>bullet_queue1;
	virtual void clearBullet();
private:
	

};




#endif 


