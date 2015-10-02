#include "Tower_Fan.h"

#include "Scene_UI.h"
#include "Tower_Fan_Bullet.h"



void Tower_Fan::sync_buttle()
{

	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{
		if ((*it)->sprite->getPositionX()<0 || (*it)->sprite->getPositionX()>960)
		{
			auto x = *it;
			bullet_queue.erase(it);
			(x)->Destory(target);
		}
		else
		{
			++it;
		}
	}

	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{
		if ((*it)->sprite->getPositionY()<0 || (*it)->sprite->getPositionY()>640)
		{
			auto x = *it;
			bullet_queue.erase(it);
			(x)->Destory(target);
		}
		else
		{
			++it;
		}
	}





	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{
		/*��⸽������*/
		Scene_UI*sce = (Scene_UI*)sprite->getParent();
		for (int i = 0; i<sce->monster_queue.size(); i++)
		{

			if (70>PublicFunc::cacl_distance((*it)->sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
			{
				if ((*it)->isExist(sce->monster_queue[i]))/*ֻ������һ��*/
				{
					continue;
				}

				if (target == 0)
				{
					sce->monster_queue[i]->beenAttacked((*it)->damage);
					sce->monster_queue[i]->runFanBoomAction();
					continue;;
				}
				if (target->is_Bonus == true)
				{
					sce->monster_queue[i]->beenAttacked((*it)->damage);
					sce->monster_queue[i]->runFanBoomAction();
					auto x = *it;
					bullet_queue.erase(it);
					(x)->Destory(0);
					return;
				}
				sce->monster_queue[i]->beenAttacked((*it)->damage);
				sce->monster_queue[i]->runFanBoomAction();

			}
		}

		++it;

	}


}








void  Tower_Fan::sync_Attack(Vec2 pos, int width)
{

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*�����ڵ�*/
		//	if (target->hp_now<=0)return;
		sprite->runAction(getAttackAction());

		float rot = PublicFunc::getRotation(pos, sprite->getPosition());

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Fan.mp3");



		bullet_queue.push_back(new  Tower_Fan_Bullet(this->level, sprite->getParent(), rot, sprite->getPosition(), pos));

	}
	sync_buttle();

}

void Tower_Fan::sync_None()
{

	sync_buttle();
	setTarget(0);

}





void  Tower_Fan::initTowerBase()
{

	switch (level)
	{
	case 1: attackRange = 310 / 2; break;
	case 2: attackRange = 380 / 2; break;
	case 3: attackRange = 450 / 2; break;
	default:
		break;
	}


	switch (level)
	{
	case 1: cos_upgrade = 220; break;
	case 2: cos_upgrade = 260; break;
	}


	attackSpeed = 50 - level * 5;
}


void  Tower_Fan::setLevel(int lev)
{

	sprite->stopAllActions();

	view_click = 0;


	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Fan11.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Fan-11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Fan-11.png"));



	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Fan21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Fan-12.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Fan-12.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Fan31.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Fan-13.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Fan-13.png"));

	}break;
	}


	if (lev == 1)
	{
		auto ani = Animation::create();
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air11.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air12.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air13.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air14.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air15.png"));


		ani->setDelayPerUnit(0.1);
		ani->setRestoreOriginalFrame(true);
		ani->setLoops(1);

		/* BUG  TMP FIX*/

		if (effect == 0)
		{

			effect = Sprite::create();
			effect->setPosition(sprite->getPosition());
			sprite->getParent()->addChild(effect);
			effect->runAction(Animate::create(ani));
		}
		else
		{
			effect->removeFromParentAndCleanup(true);

			effect = Sprite::create();
			effect->setPosition(sprite->getPosition());
			sprite->getParent()->addChild(effect);
			effect->runAction(Animate::create(ani));


		}

	}
	else
	{
		//if (this->level < lev)
		{

			auto ani = Animation::create();
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air11.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air12.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air13.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air14.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air15.png"));

			ani->setDelayPerUnit(0.03);
			ani->setRestoreOriginalFrame(true);
			ani->setLoops(1);


			/* BUG  TMP FIX*/

			if (effect == 0)
			{

				effect = Sprite::create();
				effect->setPosition(sprite->getPosition());
				sprite->getParent()->addChild(effect);
				effect->runAction(Animate::create(ani));
			}
			else
			{
				effect->removeFromParentAndCleanup(true);

				effect = Sprite::create();
				effect->setPosition(sprite->getPosition());
				sprite->getParent()->addChild(effect);
				effect->runAction(Animate::create(ani));


			}

		}
	}



	this->level = lev;
	initTowerBase();




}





Tower_Fan::Tower_Fan(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;

	this->level = lev;
	effect = 0;

	cos_upgrade = 220;

	initTowerBase();

	sprite = Sprite::createWithSpriteFrameName("Fan11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Fan-11.png"), Sprite::createWithSpriteFrameName("Shit-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(5, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);

	scene->addChild(sprite);
	sprite->setPosition(pos);

	sprite_upgrade = Sprite::createWithSpriteFrameName("showupgrade02.png");

	scene->addChild(sprite_upgrade);
	sprite_upgrade->setPosition(sprite->getPositionX(), sprite->getPositionY() + sprite->getContentSize().height);
	auto ani2 = Animation::create();
	ani2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("showupgrade02.png"));
	ani2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("showupgrade01.png"));
	ani2->setDelayPerUnit(0.1);
	ani2->setRestoreOriginalFrame(false);
	ani2->setLoops(-1);
	sprite_upgrade->runAction(Animate::create(ani2));
	sprite_upgrade->setVisible(false);
	setLevel(lev);


}





Animate*Tower_Fan::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "Fan1";


	}break;
	case 2:
	{
			  str = "Fan2";
	}break;
	case 3:
	{
			  str = "Fan3";
	}break;
	}


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "3.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);

	auto an = Animate::create(ani);
	return an;


}


void Tower_Fan::setClick(bool t)
{
	if (t)
	{
		view_click = new View_Click_Tower(5, this);
	}
	else
	{
		if (view_click != 0)
		{
			view_click->Destory();
		}
		view_click = 0;
	}

}



void  Tower_Fan::Destory()
{

	Scene_UI*sc = (Scene_UI*)sprite->getParent();

	for (vector<Tower_UI*>::iterator it = sc->tower_queue.begin(); it != sc->tower_queue.end(); ++it)
	{

		if ((*it) == this)
		{
			sc->tower_queue.erase(it);
			break;
		}
	}


	setClick(false);

	setTarget(0);
	for (int i = 0; i < bullet_queue.size(); i++)
	{
		bullet_queue[i]->Destory(0);
	}


	bullet_queue.clear();


	sc->data->pop(PublicFunc::convertToX(sprite->getPosition().x),
		PublicFunc::convertToY(sprite->getPosition().y));


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air04.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air05.png"));

	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);
	auto an = Animate::create(ani);

	sprite_base->removeFromParentAndCleanup(true);
	effect->removeFromParentAndCleanup(true);

	sprite_upgrade->removeFromParentAndCleanup(true);

	sprite->runAction(Sequence::create(an, CallFunc::create([=]
	{
		sprite->removeFromParentAndCleanup(true);
		delete this;

	}), nullptr));




}
