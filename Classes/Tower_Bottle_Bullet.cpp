#include "Tower_Bottle_Bullet.h"
#include "PublicFunc.h"

Tower_Bottle_Bullet::Tower_Bottle_Bullet(int lev, Node*p, float rotation,Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{

	isDone = false;


	string str = "";



	switch (lev)
	{
	case 1:
	{
			  str = "PBottle1";


	}break;
	case 2:
	{
			  str = "PBottle2";
	}break;
	case 3:
	{
			  str = "PBottle3";
	}break;
	}


	initTowerBulletBase(lev);


	sprite = Sprite::createWithSpriteFrameName("PBottle11.png");
	p->addChild(sprite);

	sprite->setRotation(rotation);
	sprite->setPosition(pos_tower);



	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "3.png"));


	ani->setDelayPerUnit(3.0 / 30.0);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

	auto an = Animate::create(ani);
	sprite->runAction(an);

	sprite;;


	sprite->runAction(MoveTo::create(
		PublicFunc::cacl_distance(pos,  pos_tower) / moveSpeed
		, pos
		));

	sprite->runAction(Sequence::create(

		DelayTime::create(PublicFunc::cacl_distance(pos, pos_tower) / moveSpeed)
		, CallFunc::create([=]
	{

		isDone = true;
		sprite->setVisible(false);

	}), nullptr
		));


}





void Tower_Bottle_Bullet:: initTowerBulletBase(int lev)
{

	moveSpeed = 1200;
	switch (lev)
	{
	case 1: damage = 10; break;
	case 2: damage = 12; break;
	case 3: damage = 13; break;
	}


}


