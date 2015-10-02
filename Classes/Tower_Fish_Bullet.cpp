#include "Tower_Fish_Bullet.h"
#include "PublicFunc.h"

Tower_Fish_Bullet::Tower_Fish_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{

	isDone = false;


	string str = "";



	switch (lev)
	{
	case 1:
	{
			  str = "PFish1";


	}break;
	case 2:
	{
			  str = "PFish2";
	}break;
	case 3:
	{
			  str = "PFish3";
	}break;
	}


	initTowerBulletBase(lev);


	sprite = Sprite::createWithSpriteFrameName("PFish11.png");
	p->addChild(sprite);

	sprite->setRotation(rotation);
	sprite->setPosition(pos_tower);

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

	}), nullptr
		));


}





void Tower_Fish_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 1000;
	switch (lev)
	{
	case 1: damage = 22; break;
	case 2: damage = 27; break;
	case 3: damage = 31; break;
	}
}


