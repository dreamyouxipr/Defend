#include "Scene_1_6.h"


#include "Bonus_1_1.h"
#include "Bonus_1_2.h"
#include "Bonus_1_3.h"
#include "Bonus_1_4.h"
#include "Bonus_1_5.h"
#include "Bonus_1_6.h"
#include "Bonus_1_7.h"
#include "Bonus_1_11.h"
#include "Bonus_1_10.h"
#include "Bonus_1_12.h"


Scene* Scene_1_6::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_1_6::create();
	scene->addChild(layer);
	return scene;
}



void Scene_1_6::initQueue_way()
{



	queue_way.push(Vec2(10, 2));
	queue_way.push(Vec2(10, 3));
	queue_way.push(Vec2(10, 4));
	queue_way.push(Vec2(10, 5));

	queue_way.push(Vec2(9, 5));
	queue_way.push(Vec2(8, 5));
	queue_way.push(Vec2(7, 5));
	queue_way.push(Vec2(6, 5));
	queue_way.push(Vec2(5, 5));
	queue_way.push(Vec2(4, 5));
	queue_way.push(Vec2(3, 5));
	queue_way.push(Vec2(2, 5));
	queue_way.push(Vec2(1, 5));

	queue_way.push(Vec2(1, 4));
	queue_way.push(Vec2(1, 3));

	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(4, 3));
	queue_way.push(Vec2(5, 3));


	queue_way.push(Vec2(5, 4));
	queue_way.push(Vec2(6, 4));
	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(8, 4));


	queue_way.push(Vec2(8, 3));
	queue_way.push(Vec2(8, 2));
	queue_way.push(Vec2(8, 1));

	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(5, 1));
	queue_way.push(Vec2(4, 1));
	queue_way.push(Vec2(3, 1));
	queue_way.push(Vec2(2, 1));
	queue_way.push(Vec2(1, 1));


	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(3, 0));


	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));
	data->push_back(Vec2(10, 1));
	data->push_back(Vec2(11, 1));



}


void Scene_1_6::initAbleTower()
{
	view_click_gloal->tower_able.push_back(2);
	view_click_gloal->tower_able.push_back(5);

}

void Scene_1_6::initBonus()
{
	monster_queue.push_back(new  Bonus_1_1(this, PublicFunc::convertToPoint(0, 6)));

	monster_queue.push_back(new  Bonus_1_2(this, PublicFunc::convertToPoint(0, 4)));
	monster_queue.push_back(new  Bonus_1_1(this, PublicFunc::convertToPoint(1, 2)));
	monster_queue.push_back(new  Bonus_1_3(this, PublicFunc::convertToPoint(3, 2)));

	monster_queue.push_back(new  Bonus_1_4(this, PublicFunc::convertToPoint(2, 4)));

	monster_queue.push_back(new  Bonus_1_4(this, PublicFunc::convertToPoint(5, 6)));


	monster_queue.push_back(new  Bonus_1_6(this, PublicFunc::convertToPoint(6, 2)));

	monster_queue.push_back(new  Bonus_1_1(this, PublicFunc::convertToPoint(9, 3)));

	monster_queue.push_back(new  Bonus_1_2(this, PublicFunc::convertToPoint(9, 6)));

	
	monster_queue.push_back(new  Bonus_1_3(this, PublicFunc::convertToPoint(11, 3)));



}


