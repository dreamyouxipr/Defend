#include "Tower_Arrow.h"

#include "Scene_UI.h"

#include "Tower_Arrow_Bullet.h"




void Tower_Arrow::sync_buttle()
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
		/*¼ì²â¸½½ü¹ÖÎï*/
		Scene_UI*sce = (Scene_UI*)sprite->getParent();
		for (int i = 0; i<sce->monster_queue.size(); i++)
		{
			if (60>PublicFunc::cacl_distance((*it)->sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
			{				
				sce->monster_queue[i]->beenAttacked((*it)->damage);
				sce->monster_queue[i]->runArrowBoomAction();
				/*¹¥»÷Ò»´Î Çå³þ*/
				(*it)->Destory(0);
				bullet_queue.erase(it);

				return;

			}
		}

		++it;
	}


}








void  Tower_Arrow::sync_Attack(Vec2 pos, int width)
{
	
	float rot = PublicFunc::getRotation(pos, sprite->getPosition());
	sprite->setRotation(rot);

	sync_buttle();

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*·¢ÉäÅÚµ¯*/
		//	if (target->hp_now<=0)return;

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Arrow.mp3");




		sprite->runAction(getAttackAction());
		if (level == 1)
		{
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot-15, sprite->getPosition(), pos));
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot+15, sprite->getPosition(), pos));

		}
		else if(level==2)
		{

			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot-25, sprite->getPosition(), pos));
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot, sprite->getPosition(), pos));
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot+25, sprite->getPosition(), pos));
		}
		else
		{
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot - 30, sprite->getPosition(), pos));

			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot - 15, sprite->getPosition(), pos));
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot, sprite->getPosition(), pos));
			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot + 15, sprite->getPosition(), pos));

			bullet_queue.push_back(new  Tower_Arrow_Bullet(this->level, sprite->getParent(), rot + 30, sprite->getPosition(), pos));

		}


	}

}

void Tower_Arrow::sync_None()
{

	sync_buttle();
	setTarget(0);

}





void  Tower_Arrow::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 340 / 2; break;
	case 2: attackRange = 425 / 2; break;
	case 3: attackRange = 480 / 2; break;

	}
	switch (level)
	{
	case 1: cos_upgrade = 260; break;
	case 2: cos_upgrade = 380; break;
	}

	attackSpeed = 50 - level * 5;

}


void  Tower_Arrow::setLevel(int lev)
{
	sprite->stopAllActions();

	view_click = 0;


	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Arrow11.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Arrow-11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Arrow-11.png"));


	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Arrow21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Arrow-12.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Arrow-12.png"));


	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Arrow31.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Arrow-13.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Arrow-13.png"));

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





Tower_Arrow::Tower_Arrow(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;
	effect = 0;
	this->level = lev;

	cos_upgrade = 260;

	initTowerBase();
	
	sprite = Sprite::createWithSpriteFrameName("Arrow11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Arrow-11.png"), Sprite::createWithSpriteFrameName("Arrow-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(11, this);
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





Animate*Tower_Arrow::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "Arrow1";


	}break;
	case 2:
	{
			  str = "Arrow2";
	}break;
	case 3:
	{
			  str = "Arrow3";
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


void Tower_Arrow::setClick(bool t)
{
	if (t)
	{
		view_click = new View_Click_Tower(11, this);
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


void  Tower_Arrow::Destory()
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



