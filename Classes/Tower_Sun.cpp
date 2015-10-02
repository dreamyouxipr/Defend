#include "Tower_Sun.h"
#include "Scene_UI.h"



void  Tower_Sun::sync_Attack(Vec2 pos, int width)
{

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*发射炮弹*/

		sprite->runAction(RotateBy::create(0.2, 30));
		sprite_bullet_effect->runAction(getAttackAction());

		SimpleAudioEngine::getInstance()->resumeEffect(Music_ID);


		Scene_UI*sce = (Scene_UI*)sprite->getParent();
		for (int i = 0; i < sce->monster_queue.size(); i++)
		{

			if (PublicFunc::isInattackRange(this, sce->monster_queue[i]))
			{

				/*添加爆炸效果   爆炸完成后移除*/

				Sprite*boom = Sprite::create();

				boom->setPosition(sce->monster_queue[i]->sprite->getContentSize().width / 2, 20);

				sce->monster_queue[i]->sprite->addChild(boom);

				auto ani = Animation::create();
				ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun01.png"));
				ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSun02.png"));

				ani->setDelayPerUnit(0.05);
				ani->setRestoreOriginalFrame(false);
				ani->setLoops(3);
				boom->runAction(Sequence::create(Animate::create(ani), CallFunc::create([=]()
				{
					boom->removeFromParentAndCleanup(true);

				}), nullptr));


				int damage;
				switch (this->level)
				{
				case 1: damage = 17; break;
				case 2: damage = 32; break;
				case 3: damage = 46; break;
				}

				target->beenAttacked(damage);




				sce->monster_queue[i]->beenAttacked(damage);
			}
		}



	}

}



void Tower_Sun::sync_None()
{
	setTarget(0);
	SimpleAudioEngine::getInstance()->pauseEffect(Music_ID);

}





void  Tower_Sun::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 320 / 2; break;
	case 2: attackRange = 360 / 2; break;
	case 3: attackRange = 400 / 2; break;
	default:
		break;
	}

	switch (level)
	{
	case 1: cos_upgrade = 260; break;
	case 2: cos_upgrade = 320; break;
	}


	attackSpeed = 50 - level * 5;
}


void  Tower_Sun::setLevel(int lev)
{

	sprite->stopAllActions();

	view_click = 0;

	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Sun11.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Sun-11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Sun-11.png"));

	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Sun21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Sun-12.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Sun-12.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Sun31.png"));

			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Sun-13.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Sun-13.png"));

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




Animate*Tower_Sun::getAttackAction()
{
	string ss;


	switch (level)
	{
	case 1:
	{

			  ss = "PSun1";



	}break;
	case 2:
	{

			  ss = "PSun2";

	}break;
	case 3:
	{
			  ss = "PSun3";
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





Tower_Sun::Tower_Sun(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	initTowerBase();

	cos_upgrade = 260;

	sprite_bullet_effect = Sprite::create();
	sprite_bullet_effect;;


	Music_ID = SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Sun.mp3", true);

	SimpleAudioEngine::getInstance()->pauseEffect(Music_ID);


	sprite = Sprite::createWithSpriteFrameName("Sun11.png");
	sprite;;
	sprite->setPosition(pos);
	scene->addChild(sprite);


	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Sun-11.png"), Sprite::createWithSpriteFrameName("Sun-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(8, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_bullet_effect->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);


	scene->addChild(sprite_bullet_effect);
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





void Tower_Sun::setClick(bool t)
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

void  Tower_Sun::Delete()
{
	setClick(false);
	sprite_base->removeFromParentAndCleanup(true);
	effect->removeFromParentAndCleanup(true);
	sprite_bullet_effect->removeFromParentAndCleanup(true);
	sprite_upgrade->removeFromParentAndCleanup(true);

	sprite->removeFromParentAndCleanup(true);

	delete this;


}
void  Tower_Sun::Destory()
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
