#include "Tower_Snow.h"
#include "Scene_UI.h"



void  Tower_Snow::sync_Attack(Vec2 pos, int width)
{

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*·¢ÉäÅÚµ¯*/

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Snow.mp3");


		sprite->runAction(RotateBy::create(0.2, 30));
		sprite_bullet_effect->runAction(getAttackAction());

		Scene_UI*sce = (Scene_UI*)sprite->getParent();
		for (int i = 0; i<sce->monster_queue.size(); i++)
		{
			if (attackRange>PublicFunc::cacl_distance(sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
			{

				int damage;
				switch (this->level)
				{
				case 1: damage = 19; break;
				case 2: damage = 25; break;
				case 3: damage = 47; break;
				}

			
				sce->monster_queue[i]->beenAttacked(damage);
				sce->monster_queue[i]->set_effect_pause(level);

			}
		}



	}

}



void Tower_Snow::sync_None()
{
	setTarget(0);

}





void  Tower_Snow::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 320 / 2; break;
	case 2: attackRange = 360 / 2; break;
	case 3: attackRange = 400 / 2; break;
	}


	switch (level)
	{
	case 1: attackSpeed = 150; break;
	case 2: attackSpeed = 120; break;
	case 3: attackSpeed = 100; break;
	}


	switch (level)
	{
	case 1: cos_upgrade = 220; break;
	case 2: cos_upgrade = 320; break;
	}


}


void  Tower_Snow::setLevel(int lev)
{

	sprite->stopAllActions();

	view_click = 0;

	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Snow11.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Snow-11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Snow-11.png"));

	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Snow21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Snow-12.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Snow-12.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Snow31.png"));

			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Snow-13.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Snow-13.png"));

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




Animate*Tower_Snow::getAttackAction()
{
	string ss;


	switch (level)
	{
	case 1:
	{

			  ss = "PSnow1";



	}break;
	case 2:
	{

			  ss = "PSnow2";

	}break;
	case 3:
	{
			  ss = "PSnow3";
	}break;
	}




	sprite_bullet_effect->stopAllActions();

	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "3.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "4.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);

	return Animate::create(ani);




}





Tower_Snow::Tower_Snow(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	cos_upgrade = 220;

	initTowerBase();

	sprite_bullet_effect = Sprite::create();
	sprite_bullet_effect;;



	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Snow-11.png"), Sprite::createWithSpriteFrameName("Snow-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(12, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_bullet_effect->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);


	scene->addChild(sprite_bullet_effect);

	sprite = Sprite::createWithSpriteFrameName("Snow11.png");
	sprite;;
	sprite->setPosition(pos);
	scene->addChild(sprite);
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





void Tower_Snow::setClick(bool t)
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


void  Tower_Snow::Destory()
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
	sprite_bullet_effect->removeFromParentAndCleanup(true);
	sprite_upgrade->removeFromParentAndCleanup(true);


	sprite->runAction(Sequence::create(an, CallFunc::create([=]
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));



}
