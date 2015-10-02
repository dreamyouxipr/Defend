#include "Scene_4_16.h"



#include "Bonus_4_1.h"
#include "Bonus_4_2.h"
#include "Bonus_4_3.h"
#include "Bonus_4_4.h"
#include "Bonus_4_5.h"
#include "Bonus_4_6.h"
#include "Bonus_4_7.h"



Scene* Scene_4_16::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_4_16::create();
	scene->addChild(layer);
	return scene;
}




void Scene_4_16::initQueue_way()
{

	queue_way.push(Vec2(0, 5));
	queue_way.push(Vec2(1, 5));
	queue_way.push(Vec2(2, 5));
	queue_way.push(Vec2(3, 5));
	queue_way.push(Vec2(4, 5));
	queue_way.push(Vec2(5, 5));
	queue_way.push(Vec2(6, 5));
	queue_way.push(Vec2(7, 5));
	queue_way.push(Vec2(8, 5));


	queue_way.push(Vec2(8, 4));
	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(6, 4));
	queue_way.push(Vec2(5, 4));
	queue_way.push(Vec2(4, 4));
	queue_way.push(Vec2(3, 4));
	queue_way.push(Vec2(2, 4));
	queue_way.push(Vec2(1, 4));

	queue_way.push(Vec2(1, 3));
	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(4, 3));

	queue_way.push(Vec2(4, 2));
	queue_way.push(Vec2(3, 2));
	queue_way.push(Vec2(2, 2));
	queue_way.push(Vec2(1, 2));
	queue_way.push(Vec2(1, 1));
	queue_way.push(Vec2(1, 0));

	queue_way.push(Vec2(2, 0));
	queue_way.push(Vec2(3, 0));
	queue_way.push(Vec2(4, 0));
	queue_way.push(Vec2(5, 0));
	queue_way.push(Vec2(6, 0));
	queue_way.push(Vec2(7, 0));
	queue_way.push(Vec2(8, 0));
	queue_way.push(Vec2(9, 0));
	queue_way.push(Vec2(10, 0));

	queue_way.push(Vec2(10, 1));

	queue_way.push(Vec2(9, 1));
	queue_way.push(Vec2(8, 1));
	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(5, 1));

	queue_way.push(Vec2(5, 2));

	queue_way.push(Vec2(6, 2));
	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(8, 2));
	queue_way.push(Vec2(9, 2));
	queue_way.push(Vec2(10, 2));
	queue_way.push(Vec2(11, 2));

}


void Scene_4_16::initAbleTower()
{
	view_click_gloal->tower_able.push_back(3);
	view_click_gloal->tower_able.push_back(16);
	view_click_gloal->tower_able.push_back(7);
	view_click_gloal->tower_able.push_back(9);
}


void Scene_4_16::initBonus()
{
	
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(0, 6)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(2, 6)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(3, 6)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(5, 6)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(7, 6)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(8, 6)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(10, 6)));

	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(0, 4)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(9, 4)));

	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 3)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(5, 3)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(7, 3)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(10, 3)));

	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(0, 2)));

	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 1)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(2, 1)));

	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(0, 0)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(11, 0)));


}

