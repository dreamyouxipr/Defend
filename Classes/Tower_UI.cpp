#include "Tower_UI.h"

#include "Monster_land_pink.h"
#include "PublicFunc.h"
#include "Scene_UI.h"
void   Tower_UI::sync()//vector<Monster_UI*> &queue)
{

	//log("%d", (int)target);

	/*BUG:
	
	HP 为0后不能马上消失 
	TMP FIX
	
	*/
	if (target == 0)
	{

		sync_None();

		return;
	}

	if (PublicFunc::isInattackRange(this,target))
	{
		////*进入攻击范围
		if (target->hp_now <= 0)
		{
		

			target->Destory();
			//sync_None();
		}
		else
		{
			sync_Attack(target->sprite->getPosition(), target->sprite->getContentSize().width);

			if (target->hp_now <= 0)
			{
				target->Destory();
			}

		}

	}
	else
	{
		sync_None();
	}

}



void Tower_UI::clearBullet()
{
	/*for (int i = 0; i < bullet_queue.size(); i++)
	{
		bullet_queue[i]->Destory(target);

	}
	bullet_queue.clear();*/
}


