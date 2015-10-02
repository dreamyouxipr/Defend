#include "Tower_Fan_Bullet.h"
#include "PublicFunc.h"

Tower_Fan_Bullet::Tower_Fan_Bullet(int lev, Node*p, float rotation, Vec2 pos_tower, Vec2 pos)/*scene ,属于某个tower ，目标位置*/
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
			  str = "PFan11.png";


	}break;
	case 2:
	{
			  str = "PFan21.png";
	}break;
	case 3:
	{
			  str = "PFan31.png";
	}break;
	}


	initTowerBulletBase(lev);

	sprite = Sprite::createWithSpriteFrameName(str);
	p->addChild(sprite);

	sprite->setPosition(pos_tower);


	sprite->runAction(RepeatForever::create(RotateBy::create(0.3, 360)));

	sprite->runAction(MoveBy::create(1.8, Vec2(pos_x, pos_y)));


	sprite;;


}



void Tower_Fan_Bullet::initTowerBulletBase(int lev)
{

	moveSpeed = 0;
	switch (lev)
	{
	case 1: damage = 12; break;
	case 2: damage = 24; break;
	case 3: damage = 31; break;
	}
}


void Tower_Fan_Bullet::Destory(void *p)
{
	sprite->stopAllActions();
	sprite->removeFromParentAndCleanup(true);

	delete this;

}


bool Tower_Fan_Bullet:: isExist(void *p)
{
	for (int i = 0; i < queue_attacked.size(); i++)
	{
		if (queue_attacked[i] == p)return true;
	}

	queue_attacked.push_back(p);

	return false;

}

