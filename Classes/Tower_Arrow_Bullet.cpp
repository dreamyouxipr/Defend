#include "Tower_Arrow_Bullet.h"
#include "PublicFunc.h"

Tower_Arrow_Bullet::Tower_Arrow_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
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
			  str = "PArrow11.png";


	}break;
	case 2:
	{
			  str = "PArrow21.png";
	}break;
	case 3:
	{
			  str = "PArrow31.png";
	}break;
	}


	initTowerBulletBase(lev);

	sprite = Sprite::createWithSpriteFrameName(str);
	p->addChild(sprite);

	sprite->setPosition(pos_tower);


	sprite->runAction(MoveBy::create(1.0, Vec2(pos_x, pos_y)));
	sprite->setRotation(rotation);

	sprite;;


}



void Tower_Arrow_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 0;
	switch (lev)
	{
	case 1: damage = 22; break;
	case 2: damage = 29; break;
	case 3: damage = 48; break;
	}
}


void Tower_Arrow_Bullet::Destory(void *p)
{
	sprite->stopAllActions();
	sprite->removeFromParentAndCleanup(true);
	delete this;

}


