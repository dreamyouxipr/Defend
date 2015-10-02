#include "Tower_Bottle.h"

#include "Scene_UI.h"

#include "Tower_Bottle_Bullet.h"


void  Tower_Bottle::sync_Attack(Vec2 pos, int width)
{
	/*¸úËæÐý×ªÔË¶¯*/


	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{/*¼ì²âÊÇ·ñÅö×²*/

		if ((*it)->isDone == true)
		{
			target->beenAttacked((*it)->damage);
			target->runBottleBoomAction();


			(*it)->Destory(0);

			bullet_queue.erase(it);
			it = bullet_queue.begin();
		}
		else
		{
			++it;
		}
	}


	float rot = PublicFunc::getRotation(pos, sprite->getPosition());

	sprite->setRotation(rot);

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*·¢ÉäÅÚµ¯*/
		//	if (target->hp_now<=0)return;

		sprite->runAction(getAttackAction());
		bullet_queue.push_back(new  Tower_Bottle_Bullet(this->level, sprite->getParent(), rot, sprite->getPosition(), pos));

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Bottle.mp3");


	}

}

void Tower_Bottle::sync_None()
{

	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{
		if ((*it)->isDone == true)
		{
			(*it)->Destory(target);
			bullet_queue.erase(it);

		

		}
		else
		{
			++it;
		}

	}



	setTarget(0);

}





void  Tower_Bottle::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 300 / 2; break;
	case 2: attackRange = 340 / 2; break;
	case 3: attackRange = 400 / 2; break;


	default:
		break;
	}
	switch (level)
	{
	case 1: cos_upgrade = 180; break;
	case 2: cos_upgrade = 260; break;
	}


	attackSpeed = 30 - level * 6;
}


void  Tower_Bottle::setLevel(int lev)
{
	sprite->stopAllActions();

	view_click = 0;


	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Bottle11.png"));


	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Bottle21.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Bottle31.png"));
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


		ani->setDelayPerUnit(0.07);
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





Tower_Bottle::Tower_Bottle(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	cos_upgrade = 180;

	initTowerBase();

	sprite = Sprite::createWithSpriteFrameName("Bottle11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Bottle-11.png"), Sprite::createWithSpriteFrameName("Bottle-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(1, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);


	//Sprite::createWithSpriteFrameName("Bottle-11.png");



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





Animate*Tower_Bottle::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "Bottle1";


	}break;
	case 2:
	{
			  str = "Bottle2";
	}break;
	case 3:
	{
			  str = "Bottle3";
	}break;
	}





	auto ani = Animation::create();
	//ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "3.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);

	auto an = Animate::create(ani);
	return an;


}


void Tower_Bottle::setClick(bool t)
{
	if (t)
	{
		view_click = new View_Click_Tower(1, this);
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


void Tower_Bottle::Delete()
{
	Scene_UI*sc = (Scene_UI*)sprite->getParent();


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



void  Tower_Bottle::Destory()
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
		bullet_queue[i]->Destory(target);

	}
	bullet_queue.clear();


	auto x = (Scene_UI*)sprite->getParent();

	x->data->pop(PublicFunc::convertToX(sprite->getPosition().x),
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
