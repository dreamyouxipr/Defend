#include "Tower_Pin_Bullet.h"
#include "PublicFunc.h"

Tower_Pin_Bullet::Tower_Pin_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{

	isDone = false;


	string str = "";



	switch (lev)
	{
	case 1:
	{
			  str = "PPin1";


	}break;
	case 2:
	{
			  str = "PPin2";
	}break;
	case 3:
	{
			  str = "PPin3";
	}break;
	}


	initTowerBulletBase(lev);


	sprite = Sprite::createWithSpriteFrameName("PPin11.png");
	p->addChild(sprite);

	sprite->setRotation(rotation);
	sprite->setPosition(pos_tower);





	sprite;;

	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "2.png"));
	//ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "3.png"));


	ani->setDelayPerUnit(3.0 / 30.0);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

	auto an = Animate::create(ani);
	sprite->runAction(an);

	sprite->runAction(MoveTo::create(
		PublicFunc::cacl_distance(pos,  pos_tower) / moveSpeed
		, pos
		));

	sprite->runAction(Sequence::create(

		DelayTime::create(PublicFunc::cacl_distance(pos, pos_tower) / moveSpeed)
		, CallFunc::create([=]
	{

		isDone = true;

	}), nullptr
		));

	//log("%f   %f", pos.x, pos.y);

	log("%f", rotation);

}





void Tower_Pin_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 1000;
	switch (lev)
	{
	case 1: damage = 23; break;
	case 2: damage = 33; break;
	case 3: damage = 40; break;
	}
}


