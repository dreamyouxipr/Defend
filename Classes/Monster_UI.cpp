#include "Monster_UI.h"


#include "PublicFunc.h"
#include "Scene_UI.h"
#include "View_king.h"
int Monster_UI::beenAttacked(int damage)/*单体被攻击通用*/
{

	if (hp_now <= 0)
	{
		return 0;
	}

	hp_sprite_1->setVisible(true);
	hp_sprite_2->setVisible(true);


	hp_now -= damage;
	if (hp_now <= 0)hp_now = 0;
	hp_sprite_1->setScaleX(hp_now / (hp + 0.0));
	if (hp_now <= 0)
	{
		//	Destory(false);

	}
	return hp_now;


}






void  Monster_UI::updateWay()
{
	if (isDone == false)return;

	if (queue_way.size() <= 0)
	{
		auto x = (Scene_UI*)sprite->getParent();
		if (x->view_king != 0)
		{
			x->view_king->beenAttack(damage);
			Destory(true);
		}
		return;
	}


	float len = abs(sprite->getPosition().x - (queue_way.front().x * 80 + 40)) +
		abs(sprite->getPosition().y - (queue_way.front().y * 80 + 40));




	auto a2 = MoveTo::create(0.0001*moveSpeed*len,
		PublicFunc::convertToPoint(queue_way.front().x, queue_way.front().y)

		);
	a2->setTag(2);

	sprite->runAction(a2);

	auto a3 = Sequence::create(
		DelayTime::create(0.0001*moveSpeed*len)
		, CallFunc::create([=]()
	{
		isDone = true;
		queue_way.pop();

	}), nullptr);


	a3->setTag(3);

	sprite->runAction(a3);

	isDone = false;

}



void  Monster_UI::set_effect_slow(int lev, int tag)
{
	if (effect_slow_lev > lev)return;/*等级高的减速 才算*/
	/*同等级 都会刷新减速时间*/
	/*减速等级高优先*/

	if (effect_slow_lev == 0)
	{

		sprite_effect_slow = Sprite::createWithSpriteFrameName("PShit-12.png");
		sprite->addChild(sprite_effect_slow);

		auto ani1 = Animation::create();
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-12.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-11.png"));

		ani1->setDelayPerUnit(0.1);
		ani1->setRestoreOriginalFrame(false);
		ani1->setLoops(-1);
		sprite_effect_slow->runAction(Animate::create(ani1));
		sprite_effect_slow->setPosition(sprite->getContentSize().width / 2, 20);

		sprite_effect_slow->setVisible(false);
	}


	if (tag)
	{

		sprite_effect_slow->stopAllActions();

		auto ani1 = Animation::create();
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-12.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-11.png"));

		ani1->setDelayPerUnit(0.1);
		ani1->setRestoreOriginalFrame(false);
		ani1->setLoops(-1);
		sprite_effect_slow->runAction(Animate::create(ani1));
		sprite_effect_slow->setPosition(sprite->getContentSize().width / 2, 20);

	}








	effect_slow_lev = lev;
	moveSpeed = moveSpeed_readOnly;
	is_effect_slow = true;
	sprite_effect_slow->setVisible(true);

	switch (lev)
	{
	case 1:
	{
			  moveSpeed /= 0.8;
	}
		break;
	case  2:
	{
			   moveSpeed /= 0.6;
	}
		break;
	case  3:
	{
			   moveSpeed /= 0.3;
	}
		break;
	}

	isDone = true;
	sprite->stopActionByTag(2);
	sprite->stopActionByTag(3);
	sprite->stopActionByTag(4);

	auto a4 = Sequence::create(DelayTime::create(1.0 + 0.5*lev), CallFunc::create([=]()
	{
		is_effect_slow = false;
		moveSpeed = moveSpeed_readOnly;
		isDone = true;
		sprite_effect_slow->setVisible(false);
		sprite->stopActionByTag(2);
		sprite->stopActionByTag(3);
		sprite->stopActionByTag(4);
		effect_slow_lev = 0;
		updateWay();

	}), nullptr);

	a4->setTag(4);
	sprite->runAction(a4);
}




void  Monster_UI::set_effect_slow_Blue(int lev)
{
	if (effect_slow_lev > lev)return;/*等级高的减速 才算*/
	/*同等级 都会刷新减速时间*/
	/*减速等级高优先*/

	//	if (is_effect_slow == true)return;


	set_effect_slow(lev, 0);

	sprite_effect_slow->stopAllActions();

	sprite_effect_slow->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-21.png"));
	sprite_effect_slow->setPosition(sprite->getContentSize().width / 2, 20);





}



void   Monster_UI::set_effect_pause(int lev)/*暂停*/
{

	if (effect_pause_lev == 0)
	{
		sprite_effect_pause = Sprite::createWithSpriteFrameName("PSnow02.png");
		sprite->addChild(sprite_effect_pause);
		effect_pause_times = 6;
		sprite_effect_pause->setPosition(sprite->getContentSize().width / 2, 40);
		sprite_effect_pause->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.12), CallFunc::create([=]()
		{
			if (effect_pause_times >= 0)
			{
				--effect_pause_times;
				sprite->pause();
				sprite_effect_pause->setVisible(true);

			}
			else
			{
				sprite_effect_pause->setVisible(false);
				sprite->resume();
			}

		}), nullptr)));

	}

	if (effect_pause_lev <= lev)
	{
		/*等级比之前的大*/
		effect_pause_lev = lev;
		effect_pause_times = 6;
		sprite_effect_pause->setPosition(sprite->getContentSize().width / 2, 40);
	}



}



void  Monster_UI::set_effect_pause_fish(int lev)/*fish 暂停*/
{

	if (effect_pause_lev_1 == 0)
	{
		sprite_effect_pause_1 = Sprite::create();
		sprite->addChild(sprite_effect_pause_1);
		effect_pause_times_1 = 6;
		sprite_effect_pause_1->setPosition(sprite->getContentSize().width / 2, 50);


		auto ani1 = Animation::create();
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-11.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-12.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-13.png"));

		ani1->setDelayPerUnit(0.1);
		ani1->setRestoreOriginalFrame(false);
		ani1->setLoops(-1);
		sprite_effect_pause_1->runAction(Animate::create(ani1));

		sprite_effect_pause_1->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.12), CallFunc::create([=]()
		{
			if (effect_pause_times_1 >= 0)
			{
				--effect_pause_times_1;
				sprite->pause();
				sprite_effect_pause_1->setVisible(true);

			}
			else
			{
				sprite_effect_pause_1->setVisible(false);
				sprite->resume();
			}

		}), nullptr)));

	}

	if (effect_pause_lev_1 <= lev)
	{
		/*等级比之前的大*/
		effect_pause_lev_1 = lev;
		effect_pause_times_1 = 6;
		sprite_effect_pause_1->setPosition(sprite->getContentSize().width / 2, 40);
	}

}




void  Monster_UI::set_effect_last_damage(int lev)/*pin 持续伤害*/
{

	if (effect_last_damage_lev == 0)
	{
		sprite_last_damage = Sprite::create();
		sprite->addChild(sprite_last_damage);

		auto ani1 = Animation::create();
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin01.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin02.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin03.png"));
		ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin04.png"));

		ani1->setDelayPerUnit(0.03);
		ani1->setRestoreOriginalFrame(false);
		ani1->setLoops(-1);
		sprite_last_damage->runAction(Animate::create(ani1));
		sprite_last_damage->setPosition(sprite->getContentSize().width / 2, 20);

		effect_last_damage_times = 5;
		sprite_last_damage->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.5), CallFunc::create([=]()
		{
			if (effect_last_damage_times >= 0)
			{
				--effect_last_damage_times;
				sprite_last_damage->setVisible(true);
				beenAttacked(effect_last_damage_lev * 1);
				sprite_last_damage->setPosition(sprite->getContentSize().width / 2, 20);

			}
			else
			{
				sprite_last_damage->setVisible(false);

			}

		}), nullptr)));

	}

	if (effect_last_damage_lev <= lev)
	{
		/*等级比之前的大*/
		effect_last_damage_lev = lev;
		effect_last_damage_times = 5;
		sprite_last_damage->setVisible(true);
	}

	sprite_last_damage->setPosition(sprite->getContentSize().width / 2, 20);


}







void Monster_UI::resetWay()
{
	sprite->stopAllActions();
	runMoveAction();
	isDone = true;
}


void Monster_UI::Delete()
{

	sprite->removeAllChildrenWithCleanup(true);
	sprite->removeFromParentAndCleanup(true);

	delete this;

}





void Monster_UI::Destory(bool isKing)
{
	Scene_UI*scen = (Scene_UI*)sprite->getParent();

	playEffect();

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


	if (isKing)
	{
		bonus = Sprite::create();

	}
	else
	{
		scen->view_up_menu->addMoney(money);
		bonus = Sprite::createWithSpriteFrameName(ss);

	}


	bonus->setPosition(sprite->getPosition());

	sprite->getParent()->addChild(bonus, 6);

	bonus->runAction(MoveBy::create(0.2, Vec2(0, 50)));

	auto an = Animate::create(ani);


	/*q c*/


	bonus;;




	sprite->runAction(Sequence::create(an, CallFunc::create([=]
	{
		sprite->removeFromParentAndCleanup(true);
		bonus->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));


}



void Monster_UI::runRocketBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket02.png"));

	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket-11.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket-12.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket-13.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket-14.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket-15.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PRocket-16.png"));

	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.4), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));





}



void Monster_UI::runFanBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFan01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFan02.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}





void Monster_UI::runBottleBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBottle01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBottle02.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}





void Monster_UI::runShitBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit02.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}




void Monster_UI::runStarBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar-11.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar-12.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar-13.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar-14.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar-15.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PStar-16.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));


	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.4), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}



void Monster_UI::runBallBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBall01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBall02.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}



void Monster_UI::runFireBottleBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFBottle01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFBottle02.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}

void Monster_UI::runBlueStarBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-11.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-12.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-13.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-14.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-15.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-16.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));


	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.4), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}








void Monster_UI::runArrowBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PArrow01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PArrow02.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}





void Monster_UI::runPlaneBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPlane01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPlane02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPlane03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPlane04.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPlane05.png"));

	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);
	sprite_boom->runAction(Animate::create(ani));
	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.25), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}







void Monster_UI::runFishBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish02.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));



	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}




void Monster_UI::runFishBoomAction_2()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-21.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-22.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-23.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-24.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-25.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFish-26.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));


	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.4), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}


void Monster_UI::runCuttleBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PCuttle01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PCuttle02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PCuttle03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PCuttle04.png"));

	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);
	sprite_boom->runAction(Animate::create(ani));
	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.2), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}





void Monster_UI::runAnchorBoomAction()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-11.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-12.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-13.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-14.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-15.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-16.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));


	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.4), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}


void Monster_UI::runAnchorBoomAction_2()
{


	auto	sprite_boom = Sprite::create();
	sprite->addChild(sprite_boom);


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-11.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-12.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-13.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-14.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-15.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PAnchor-16.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_boom->runAction(Animate::create(ani));

	sprite_boom->setScale(0.8);

	sprite_boom->setVisible(true);

	sprite_boom->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);

	sprite_boom->runAction(Sequence::create(DelayTime::create(0.4), CallFunc::create([=]()
	{
		sprite_boom->removeFromParentAndCleanup(true);
	}), nullptr));


}

