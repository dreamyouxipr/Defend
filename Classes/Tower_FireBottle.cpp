#include "Tower_FireBottle.h"
#include "Scene_UI.h"


void  Tower_FireBottle::sync_Attack(Vec2 pos, int width)
{
	/*跟随旋转运动*/

	sprite_bullet_effect->setVisible(true);


	Scene_UI*sce = (Scene_UI*)sprite->getParent();

	float rot=PublicFunc::getRotation(pos,sprite->getPosition());

	sprite->setRotation(rot);
	sprite_bullet_effect->setRotation(rot);


	sprite_bullet_effect->setScaleY(
		PublicFunc::cacl_distance(pos, sprite->getPosition())
		/ sprite_bullet_effect->getContentSize().height);


	++count;
	if (count > attackSpeed)
	{
		count = 0;
		sprite->runAction(getAttackAction());

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/FireBottle.mp3");



		if (target)
		{
			/*检测附近怪物*/
			for (int i = 0; i<sce->monster_queue.size(); i++)
			{

				if (100>PublicFunc::cacl_distance(target->sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
				{


					int damage;
					switch (this->level)
					{
					case 1: damage = 24; break;
					case 2: damage = 47; break;
					case 3: damage = 54; break;
					}

					if (target->is_Bonus == true && sce->monster_queue[i]->is_Bonus == false)
					{
						continue;
					}

					if (target->is_Bonus == false && sce->monster_queue[i]->is_Bonus == true)
					{
						continue;
					}
					sce->monster_queue[i]->beenAttacked(damage);
					sce->monster_queue[i]->runFireBottleBoomAction();

				}
			}

		}
	}



}




void Tower_FireBottle::sync_None()
{
	sprite_bullet_effect->setVisible(false);
	setTarget(0);
}





void  Tower_FireBottle::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 300 / 2; break;
	case 2: attackRange = 340 / 2; break;
	case 3: attackRange = 452 / 2; break;


	default:
		break;
	}

	switch (level)
	{
	case 1: cos_upgrade = 260; break;
	case 2: cos_upgrade = 320; break;
	}


	attackSpeed = 30 - level * 5;
}


void  Tower_FireBottle::setLevel(int lev)
{
	sprite->stopAllActions();

	view_click = 0;
	string ss = "";

	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("FBottle11.png"));
			  ss = "PFBottle1";

	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("FBottle21.png"));
			  ss = "PFBottle2";
	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("FBottle31.png"));
			  ss = "PFBottle3";
	
	}break;
	}


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "2.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);


	sprite_bullet_effect->stopAllActions();


	sprite_bullet_effect->runAction(Animate::create(ani));









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





Tower_FireBottle::Tower_FireBottle(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	cos_upgrade = 260;

	initTowerBase();
	sprite_bullet_effect = Sprite::create();
	sprite_bullet_effect;;


	sprite = Sprite::createWithSpriteFrameName("FBottle11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("FBottle-11.png"), Sprite::createWithSpriteFrameName("FBottle-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(6, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);

	sprite_bullet_effect->setPosition(pos);

	scene->addChild(sprite_bullet_effect);
	sprite_bullet_effect->setAnchorPoint(Vec2(0.5, 0));
	sprite_bullet_effect->setVisible(false);

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





Animate*Tower_FireBottle::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "FBottle1";


	}break;
	case 2:
	{
			  str = "FBottle2";
	}break;
	case 3:
	{
			  str = "FBottle3";
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


void Tower_FireBottle::setClick(bool t)
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


void  Tower_FireBottle::Destory()
{

	Scene_UI*sc = (Scene_UI*)sprite->getParent();

	for (vector<Tower_UI*>::iterator it = sc->tower_queue.begin(); it != sc->tower_queue.end();++it)
	{

		if ((*it) == this)
		{
			sc->tower_queue.erase(it);
			break;
		}
	}


	xx:
	setClick(false);

	setTarget(0);

	
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

	sprite_bullet_effect->removeFromParentAndCleanup(true);

	sprite->runAction(Sequence::create(an, CallFunc::create([=]
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));


}

