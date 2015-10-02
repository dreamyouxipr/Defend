#include "Tower_Star_Bullet.h"
#include "PublicFunc.h"

Tower_Star_Bullet::Tower_Star_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{

	isDone = false;


	string str = "";



	switch (lev)
	{
	case 1:
	{
			  str = "PStar11.png";


	}break;
	case 2:
	{
			  str = "PStar21.png";
	}break;
	case 3:
	{
			  str = "PStar31.png";
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




void Tower_Star_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 1000;
	switch (lev)
	{
	case 1: damage = 21; break;
	case 2: damage = 36; break;
	case 3: damage = 48; break;
	}
}


void Tower_Star_Bullet:: Destory(void *p)
{

	if (p)
	{
		Monster_UI*x = (Monster_UI*)p;
		sprite->setPosition(x->sprite->getPosition());
	}
	/*
	 BUG:
	  删除炮塔后 ，攻击爆炸效果可能不会被移除  (概率很小)*/

	sprite->runAction(Sequence::create(DelayTime::create(0.15), CallFunc::create([=]()
	{
		sprite->removeFromParentAndCleanup(true);
		delete this;

	}), nullptr));


}
