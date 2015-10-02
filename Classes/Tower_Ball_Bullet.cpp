#include "Tower_Ball_Bullet.h"
#include "PublicFunc.h"

Tower_Ball_Bullet::Tower_Ball_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
{
	isDone = false;

	initTowerBulletBase(lev);

	sprite = Sprite::create();
	p->addChild(sprite);
	sprite->setPosition(pos);


	sprite;;

	sprite->runAction(Sequence::create(

		DelayTime::create(PublicFunc::cacl_distance(pos, pos_tower) / moveSpeed)
		, CallFunc::create([=]
	{

		sprite->setVisible(false);
		isDone = true;

	}), nullptr
		));

}





void Tower_Ball_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 1000;
	switch (lev)
	{
	case 1: damage = 32; break;
	case 2: damage = 64; break;
	case 3: damage = 90; break;
	}	
	
}


void Tower_Ball_Bullet::Destory(void *p)

{
	if (p)
	{
		Monster_UI*x = (Monster_UI*)p;
		sprite->setPosition(x->sprite->getPosition());
	}

	sprite->runAction(Sequence::create(DelayTime::create(0.1), CallFunc::create([=]()
	{
		sprite->stopAllActions();
		sprite->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));



}


