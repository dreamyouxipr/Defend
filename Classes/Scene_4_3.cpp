#include "Scene_4_3.h"


#include "Bonus_4_1.h"
#include "Bonus_4_2.h"
#include "Bonus_4_3.h"
#include "Bonus_4_4.h"
#include "Bonus_4_5.h"
#include "Bonus_4_6.h"
#include "Bonus_4_7.h"




Scene* Scene_4_3::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_4_3::create();
	scene->addChild(layer);
	return scene;
}



void Scene_4_3::initQueue_way()
{

	queue_way.push(Vec2(1, 5));
	
	queue_way.push(Vec2(1, 4));
	queue_way.push(Vec2(1, 3));

	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(4, 3));
	queue_way.push(Vec2(5, 3));

	queue_way.push(Vec2(5, 4));


	queue_way.push(Vec2(6, 4));

	queue_way.push(Vec2(6, 3));
	queue_way.push(Vec2(6, 2));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(6, 0));


	queue_way.push(Vec2(7, 0));
	queue_way.push(Vec2(8, 0));
	queue_way.push(Vec2(9, 0));


	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(3, 0));

}


void Scene_4_3::initAbleTower()
{
	view_click_gloal->tower_able.push_back(14);
	view_click_gloal->tower_able.push_back(10);
	view_click_gloal->tower_able.push_back(9);
	view_click_gloal->tower_able.push_back(13);

}

void Scene_4_3::initBonus()
{



	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(3, 6)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(10, 6)));

	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(0, 5)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(4, 5)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(6, 5)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(7, 5)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(9, 5)));

	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(2, 4)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(4, 4)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(7, 4)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(10, 4)));


	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(0, 3)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(7, 3)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(8, 3)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(10, 3)));

	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(0, 2)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(4, 2)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(8, 2)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(11, 2)));

	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(1,1)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(3, 1)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(7, 1)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(9, 1)));


	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(4, 0)));



}