#include "Tower_Anchor.h"

#include "Scene_UI.h"
#include "Tower_Anchor_Bullet.h"
#include "Tower_Anchor_Bullet_2.h"



void Tower_Anchor::sync_buttle()
{
	for (vector<TowerBullet_UI*>::iterator it = bullet_queue1.begin(); it != bullet_queue1.end();)
	{
		if ((*it)->sprite->getPositionX()<0 || (*it)->sprite->getPositionX()>960)
		{
			auto x = *it;
			bullet_queue1.erase(it);
			(x)->Destory(target);
		}
		else
		{
			++it;
		}
	}

	for (vector<TowerBullet_UI*>::iterator it = bullet_queue1.begin(); it != bullet_queue1.end();)
	{
		if ((*it)->sprite->getPositionY()<0 || (*it)->sprite->getPositionY()>640)
		{
			auto x = *it;
			bullet_queue1.erase(it);
			(x)->Destory(target);
		}
		else
		{
			++it;
		}
	}


	for (vector<TowerBullet_UI*>::iterator it = bullet_queue1.begin(); it != bullet_queue1.end();)
	{
		/*¼ì²â¸½½ü¹ÖÎï*/
		Scene_UI*sce = (Scene_UI*)sprite->getParent();
		for (int i = 0; i<sce->monster_queue.size(); i++)
		{

			if (target == sce->monster_queue[i])continue;

			if (60>PublicFunc::cacl_distance((*it)->sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
			{
				sce->monster_queue[i]->beenAttacked((*it)->damage);
				sce->monster_queue[i]->runAnchorBoomAction_2();
				/*¹¥»÷Ò»´Î Çå³þ*/
				(*it)->Destory(0);
				bullet_queue1.erase(it);

				return;

			}
		}

		++it;
	}


}







void  Tower_Anchor::sync_Attack(Vec2 pos, int width)
{
	/*¸úËæÐý×ªÔË¶¯*/

	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{/*¼ì²âÊÇ·ñÅö×²*/

		if ((*it)->isDone == true)
		{
			auto x = *it;
			bullet_queue.erase(it);
			it = bullet_queue.begin();
			target->runAnchorBoomAction();

	
			/*¼ì²â¸½½ü¹ÖÎï*/	
			Scene_UI*sce = (Scene_UI*)sprite->getParent();

			for (int i = 0;i<sce->monster_queue.size();i++)
			{
				if (100>PublicFunc::cacl_distance(target->sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
				{
					sce->monster_queue[i]->beenAttacked((x)->damage);
				
				}
			}

			SimpleAudioEngine::getInstance()->playEffect("Music/Tower/Anchor.mp3");


			if (level == 1)
			{
				bullet_queue1.push_back(new  Tower_Anchor_Bullet_2(this->level, sprite->getParent(), sprite->getRotation(), sprite->getPosition(), target->sprite->getPosition()));
			
			}
			else if (level==2)
			{

				bullet_queue1.push_back(new  Tower_Anchor_Bullet_2(this->level, sprite->getParent(), sprite->getRotation()+30, sprite->getPosition(), target->sprite->getPosition()));
				bullet_queue1.push_back(new  Tower_Anchor_Bullet_2(this->level, sprite->getParent(), sprite->getRotation()-30, sprite->getPosition(), target->sprite->getPosition()));

			}
			else
			{

				bullet_queue1.push_back(new  Tower_Anchor_Bullet_2(this->level, sprite->getParent(), sprite->getRotation()+30, sprite->getPosition(), target->sprite->getPosition()));
				bullet_queue1.push_back(new  Tower_Anchor_Bullet_2(this->level, sprite->getParent(), sprite->getRotation(), sprite->getPosition(), target->sprite->getPosition()));
				bullet_queue1.push_back(new  Tower_Anchor_Bullet_2(this->level, sprite->getParent(), sprite->getRotation()-30, sprite->getPosition(), target->sprite->getPosition()));

			}

			(x)->Destory(target);

		}
		else
		{
			++it;
		}
	}

	float rot = PublicFunc::getRotation(pos, sprite->getPosition());

	sprite->setRotation(rot);

	sync_buttle();

	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*·¢ÉäÅÚµ¯*/
		//	if (target->hp_now<=0)return;
		sprite->runAction(getAttackAction());
		bullet_queue.push_back(new  Tower_Anchor_Bullet(this->level, sprite->getParent(), rot, sprite->getPosition(), pos));

	}

}

void Tower_Anchor::sync_None()
{
	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{
		if ((*it)->isDone == true)
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

	setTarget(0);
	sync_buttle();

}





void  Tower_Anchor::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 340 / 2; break;
	case 2: attackRange = 420 / 2; break;
	case 3: attackRange = 480 / 2; break;
	}


	switch (level)
	{
	case 1: cos_upgrade = 320 ; break;
	case 2: cos_upgrade=380; break;
	}






	attackSpeed = 50 - level * 5;
	
}


void  Tower_Anchor::setLevel(int lev)
{

	sprite->stopAllActions();

	view_click = 0;


	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Anchor11.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Anchor-11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Anchor-11.png"));



	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Anchor21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Anchor-12.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Anchor-12.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("Anchor31.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("Anchor-13.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("Anchor-13.png"));

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





Tower_Anchor::Tower_Anchor(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;

	this->level = lev;
	effect = 0;


	cos_upgrade = 320;




	initTowerBase();

	sprite = Sprite::createWithSpriteFrameName("Anchor11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Anchor-11.png"), Sprite::createWithSpriteFrameName("Anchor-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(16, this);
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





Animate*Tower_Anchor::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "Anchor1";


	}break;
	case 2:
	{
			  str = "Anchor2";
	}break;
	case 3:
	{
			  str = "Anchor3";
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


void Tower_Anchor::setClick(bool t)
{
	if (t)
	{
		view_click = new View_Click_Tower(16, this);
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

void Tower_Anchor::clearBullet()
{

	/*for (int i = 0; i < bullet_queue.size(); i++)
	{
	bullet_queue[i]->Destory();

	}
	bullet_queue.clear();
	*/

	/*

	tip:
	maybe BUG*/
}


void  Tower_Anchor::Destory()
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

	sc->data->pop(PublicFunc::convertToX(sprite->getPosition().x),
		PublicFunc::convertToY(sprite->getPosition().y));

	for (int i = 0; i < bullet_queue.size(); i++)
	{
		bullet_queue[i]->Destory(target);
	}

	for (int i = 0; i < bullet_queue1.size(); i++)
	{
		bullet_queue1[i]->Destory(target);
	}


	setTarget(0);

	bullet_queue.clear();



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
