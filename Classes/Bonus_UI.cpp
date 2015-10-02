#include "Bonus_UI.h"


#include "PublicFunc.h"
#include "Scene_UI.h"




void Bonus_UI::Destory(bool is)
{

	Scene_UI*scen = (Scene_UI*)sprite->getParent();


	SimpleAudioEngine::getInstance()->playEffect("Music/bonus.mp3");

	men->setVisible(false);
	menu->setVisible(false);

	for (int i = 0; i < queue_takeplace_pos.size(); i++)
	{
		scen->data->pop(queue_takeplace_pos[i]);
	}
	queue_takeplace_pos.clear();


	/*清楚所有 该怪物 为目标的炮塔 目标*/
	for (int i = 0; i < scen->tower_queue.size(); i++)
	{
		if (scen->tower_queue[i]->target == this)
		{
			scen->tower_queue[i]->setTarget(0);
		}
	}


	for (vector<Monster_UI*>::iterator it = scen->monster_queue.begin(); it != scen->monster_queue.end();)
	{
		if ((*it) == this)
		{
			scen->monster_queue.erase(it);
		}
		else
			++it;
	}

	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air04.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air05.png"));


	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(1);

	sprite->removeAllChildrenWithCleanup(true);

	sprite->stopAllActions();


	char ss[100];
	if (money >= 10)
	{
		sprintf(ss, "money%d.png", money);
	}
	else
	{
		sprintf(ss, "money0%d.png", money);
	}


	scen->view_up_menu->addMoney(money);
	bonus = Sprite::createWithSpriteFrameName(ss);


	bonus->setPosition(sprite->getPosition());

	sprite->getParent()->addChild(bonus, 6);

	bonus->runAction(MoveBy::create(0.2, Vec2(0, 50)));

	auto an = Animate::create(ani);


	/*q c*/
	bonus;;
	




	/*是否全部清除*/
	int i = 0;
	for (; i < scen->monster_queue.size(); i++)
	{
		if (scen->monster_queue[i]->is_Bonus == true)
		{
			i = 0;
			break;
		}
	}


	if (i != 0  || scen->monster_queue.size()==0)
	{
		PublicFunc::setUserDefault_AllClear(scen->key_to_);
		scen->BonusAllclear();

	}

	 

	sprite->runAction(Sequence::create(an, CallFunc::create([=]
	{
		sprite->removeFromParentAndCleanup(true);
		bonus->removeFromParentAndCleanup(true);
		men->removeAllChildrenWithCleanup(true);
		men->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));





}
