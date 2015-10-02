#include "Tower_Plane.h"

#include "Scene_UI.h"



void  Tower_Plane::sync_Attack(Vec2 pos, int width)
{

	float rot = PublicFunc::getRotation(pos, sprite->getPosition());


	sprite->setRotation(rot);



	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*·¢ÉäÅÚµ¯*/
		//	if (target->hp_now<=0)return;
		Scene_UI*sce = (Scene_UI*)sprite->getParent();

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Plane.mp3");



		vector<Vec2> queue_b;
		for (int i = 1; i < 24; i++)
		{
			queue_b.push_back(Vec2(
				sprite->getPositionX()+40 * i * sin(rot*3.14159 / 180.0)
				, 40 * i * cos(rot*3.14159 / 180.0) + sprite->getPositionY()));		
		}


		for (int ii = 0;ii<sce->monster_queue.size();ii++)
		{
			for (int i = 0; i < queue_b.size(); i++)
			{

				if ((level*20+30)>PublicFunc::cacl_distance(sce->monster_queue[ii]->sprite->getPosition(), queue_b[i]))
				{
					int damage;
					switch (this->level)
					{
					case 1: damage = 46; break;
					case 2: damage = 67; break;
					case 3: damage = 78; break;
					}

					

					sce->monster_queue[ii]->beenAttacked(damage);
					sce->monster_queue[ii]->runPlaneBoomAction();
					goto kk;
				}
			}

		kk:;

		}
		

		{
			
			switch (level)
			{
			case 1: s = "PPlane11.png"; break;
			case 2: s = "PPlane21.png"; break;
			case 3: s = "PPlane31.png"; break;
			}
			Sprite*bullet = Sprite::createWithSpriteFrameName(s);
			sce->addChild(bullet);
			bullet->setPosition(sprite->getPosition());

			bullet->setRotation(rot);
			bullet->setOpacity(0);
			bullet->setAnchorPoint(Vec2(0.5,0));
			bullet->runAction(Sequence::create(FadeIn::create(0.05),DelayTime::create(0.1),FadeOut::create(0.1), CallFunc::create([=]()
			{
				bullet->removeFromParentAndCleanup(true);		
			
			}), nullptr));
		}








	}

}



void Tower_Plane::sync_None()
{


	setTarget(0);

}





void  Tower_Plane::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 420 / 2; break;
	case 2: attackRange = 476 / 2; break;
	case 3: attackRange = 640 / 2; break;

	default:
		break;
	}

	switch (level)
	{
	case 1: cos_upgrade = 320; break;
	case 2: cos_upgrade = 380; break;
	}


	attackSpeed = 70 - level * 5;
}


void  Tower_Plane::setLevel(int lev)
{
	sprite->stopAllActions();

	view_click = 0;


	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Plane11.png"));


	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Plane21.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Plane31.png"));
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





Tower_Plane::Tower_Plane(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	cos_upgrade = 320;

	initTowerBase();

	sprite = Sprite::createWithSpriteFrameName("Plane11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Plane-11.png"), Sprite::createWithSpriteFrameName("Plane-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(13, this);
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





void Tower_Plane::setClick(bool t)
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


void  Tower_Plane::Destory()
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


