

#ifndef Tower_UI__

#define Tower_UI__



#include "TowerBase.h"

#include "TowerBullet_UI.h"
#include "Monster_UI.h"


#include "View_Click_Tower.h"


class Tower_UI :public TowerBase
{



public:
	Tower_UI() :target(0){}

	Monster_UI*target;/*攻击目标*/


	Sprite*effect;
	Sprite*sprite;/*texture*/
	MenuItemSprite*sprite_base;

	virtual void Destory() = 0;
	virtual void Delete() = 0;/*立即清除*/
	virtual void sync();//vector<Monster_UI*> &queue);

	virtual void clearBullet();

	void setTarget(Monster_UI*t)
	{
		target = t;
		clearBullet();
		//	count = 0;


	}
	void removeTarget()
	{
		target = 0;
	}


	virtual void setClick(bool t) = 0;/*用户非该地区 点击时消除调用*/
	bool isClicked() const
	{
		return view_click;
	}
	View_Click_Tower*view_click;
	vector<TowerBullet_UI*>bullet_queue;
protected:
	virtual void sync_Attack(Vec2 pos, int width){ log("ll"); };
	virtual void sync_None(){ log("none"); };

	int count;


	virtual	Animate*getAttackAction() = 0;




public:
	int cos_upgrade;/*升级花费*/

	Sprite*sprite_upgrade;

};





#endif // 


