#include "Tower_BlueStar_Bullet.h"
#include "PublicFunc.h"

Tower_BlueStar_Bullet::Tower_BlueStar_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{

	isDone = false;


	string str = "";



	switch (lev)
	{
	case 1:
	{
			  str = "PBStar11.png";


	}break;
	case 2:
	{
			  str = "PBStar21.png";
	}break;
	case 3:
	{
			  str = "PBStar31.png";
	}break;
	}


	initTowerBulletBase(lev);


	sprite = Sprite::createWithSpriteFrameName(str);
	p->addChild(sprite);


	sprite->setPosition(pos_tower);

	sprite;;

	sprite->runAction(RepeatForever::create(RotateBy::create(0.6,360)));

	sprite->runAction(MoveTo::create(
		PublicFunc::cacl_distance(pos,  pos_tower) / moveSpeed
		, pos
		));

	sprite->runAction(Sequence::create(

		DelayTime::create(PublicFunc::cacl_distance(pos, pos_tower) / moveSpeed)
		, CallFunc::create([=]
	{

		sprite->setVisible(false);
		isDone = true;

	}), nullptr
		));


}




void Tower_BlueStar_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 1000;
	switch (lev)
	{
	case 1: damage = 15; break;
	case 2: damage = 22; break;
	case 3: damage = 36; break;
	}
}



void Tower_BlueStar_Bullet::Destory(void *p)
{
	if (p)
	{

		Monster_UI*x = (Monster_UI*)p;
		sprite->setPosition(x->sprite->getPosition());
	}

	sprite->runAction(Sequence::create(DelayTime::create(0.16), CallFunc::create([=]()
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));


}
