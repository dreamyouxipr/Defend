#include "Tower_Rocket_Bullet.h"
#include "PublicFunc.h"

Tower_Rocket_Bullet::Tower_Rocket_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{

	isDone = false;

	string str = "";

	float pos_x = 0, pos_y = 0;


	pos_y = 1200 * cos(rotation*3.14159 / 180.0);
	pos_x = 1200 * sin(rotation*3.14159 / 180.0);


	switch (lev)
	{
	case 1:
	{
			  str = "PRocket11.png";


	}break;
	case 2:
	{
			  str = "PRocket21.png";
	}break;
	case 3:
	{
			  str = "PRocket31.png";
	}break;
	}


	initTowerBulletBase(lev);

	sprite = Sprite::createWithSpriteFrameName(str);
	p->addChild(sprite);

	sprite->setPosition(pos_tower);


	sprite->runAction(MoveBy::create(1.8, Vec2(pos_x, pos_y)));
	sprite->setRotation(rotation);

	sprite;;




	switch (lev)
	{
	case 1:
	{
			  str = "PRocket1";
	}break;
	case 2:
	{
			  str = "PRocket2";
	}break;
	case 3:
	{
			  str = "PRocket3";
	}break;
	}


	auto ani = Animation::create();


	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "3.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "4.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "5.png"));

	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(-1);

	sprite->runAction(Animate::create(ani));



}



void Tower_Rocket_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 0;
	switch (lev)
	{
	case 1: damage = 48; break;
	case 2: damage = 73; break;
	case 3: damage = 93; break;
	}
}


void Tower_Rocket_Bullet::Destory(void *p)
{
	sprite->stopAllActions();
	sprite->removeFromParentAndCleanup(true);
	delete this;

}


bool Tower_Rocket_Bullet::isExist(void *p)
{
	for (int i = 0; i < queue_attacked.size(); i++)
	{
		if (queue_attacked[i] == p)return true;
	}

	queue_attacked.push_back(p);
	

	return false;

}

