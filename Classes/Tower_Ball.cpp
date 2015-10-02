#include "Tower_Ball.h"

#include "Scene_UI.h"

void  Tower_Ball::sync_Attack(Vec2 pos, int width)
{
	sprite_bullet_effect->setVisible(true);

	
	float rot = PublicFunc::getRotation(pos, sprite->getPosition());


	sprite_bullet_effect->setRotation(rot);

	sprite_bullet_effect->setScaleY(
		PublicFunc::cacl_distance(pos, sprite->getPosition())
		/ sprite_bullet_effect->getContentSize().height);

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*·¢ÉäÅÚµ¯*/
		sprite->runAction(getAttackAction());
		if (target)
		{
			target->runBallBoomAction();
			SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Ball.mp3");
			int damage;
			switch (this->level)
			{
			case 1: damage = 32; break;
			case 2: damage = 64; break;
			case 3: damage = 90; break;
			}

			target->beenAttacked(damage);
		}
	}

}



void Tower_Ball::sync_None()
{	
	sprite_bullet_effect->setVisible(false);

	setTarget(0);

}





void  Tower_Ball::initTowerBase()
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
	case 1: cos_upgrade = 320; break;
	case 2: cos_upgrade = 480; break;
	}



	attackSpeed = 30 - level * 5;
}


void  Tower_Ball::setLevel(int lev)
{
	sprite->stopAllActions();

	view_click = 0;

	string ss = "";



	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Ball11.png"));

			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Ball11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Ball11.png"));

			  ss = "PBall1";



	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Ball21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Ball21.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Ball21.png"));

			  ss = "PBall2";

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Ball31.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Ball31.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Ball31.png"));
			  ss = "PBall3";

	}break;
	}




	sprite_bullet_effect->stopAllActions();

	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "3.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(ss + "4.png"));



	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

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





Tower_Ball::Tower_Ball(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	cos_upgrade = 320;

	initTowerBase();
	sprite_bullet_effect = Sprite::create();
	sprite_bullet_effect;;


	sprite = Sprite::createWithSpriteFrameName("Ball11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Ball11.png"), Sprite::createWithSpriteFrameName("Ball11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(4, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_bullet_effect->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);


	//Sprite::createWithSpriteFrameName("Bottle-11.png");



	scene->addChild(sprite);
	sprite->setPosition(pos);
	scene->addChild(sprite_bullet_effect);
	sprite_bullet_effect->setAnchorPoint(Vec2(0.5, 0));
	sprite_bullet_effect->setVisible(false);
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





Animate*Tower_Ball::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "Ball1";


	}break;
	case 2:
	{
			  str = "Ball2";
	}break;
	case 3:
	{
			  str = "Ball3";
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


void Tower_Ball::setClick(bool t)
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


void  Tower_Ball::Destory()
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
