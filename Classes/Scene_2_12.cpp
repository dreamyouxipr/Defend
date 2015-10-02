#include "Scene_2_12.h"


#include "Bonus_2_1.h"
#include "Bonus_2_2.h"
#include "Bonus_2_3.h"
#include "Bonus_2_4.h"
#include "Bonus_2_5.h"
#include "Bonus_2_6.h"
#include "Bonus_2_7.h"
#include "Bonus_2_11.h"
#include "Bonus_2_10.h"
#include "Bonus_2_12.h"

Scene* Scene_2_12::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_2_12::create();
	scene->addChild(layer);
	return scene;
}



void Scene_2_12::initQueue_way()
{

	
	queue_way.push(Vec2(1, 4));
	queue_way.push(Vec2(2, 4));
	queue_way.push(Vec2(3, 4));
	queue_way.push(Vec2(3, 5));
	queue_way.push(Vec2(4, 5));
	queue_way.push(Vec2(5, 5));
	queue_way.push(Vec2(6, 5));
	queue_way.push(Vec2(6, 4));
	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(7, 5));
	queue_way.push(Vec2(8, 5));
	queue_way.push(Vec2(9, 5));
	queue_way.push(Vec2(10, 5));
	queue_way.push(Vec2(10, 4));
	queue_way.push(Vec2(10, 3));
	queue_way.push(Vec2(10, 2));
	queue_way.push(Vec2(10, 1));
	

	queue_way.push(Vec2(9, 1));
	queue_way.push(Vec2(8, 1));
	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(7, 3));
	queue_way.push(Vec2(6, 3));
	queue_way.push(Vec2(6, 2));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(5, 1));
	queue_way.push(Vec2(4, 1));
	queue_way.push(Vec2(3, 1));
	queue_way.push(Vec2(3, 2));

	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(1, 3));
	queue_way.push(Vec2(1, 2));
	queue_way.push(Vec2(1, 1));



	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(1, 1));
	data->push_back(Vec2(0, 1));

	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));


	data->push_back(Vec2(3, 0));
	data->push_back(Vec2(8, 0));



}


void Scene_2_12::initAbleTower()
{
	view_click_gloal->tower_able.push_back(1);
	view_click_gloal->tower_able.push_back(2);
	view_click_gloal->tower_able.push_back(5);
	view_click_gloal->tower_able.push_back(3);
	view_click_gloal->tower_able.push_back(4);
	view_click_gloal->tower_able.push_back(6);
	view_click_gloal->tower_able.push_back(7);
	view_click_gloal->tower_able.push_back(8);



}

void Scene_2_12::initBonus()
{
	
	monster_queue.push_back(new  Bonus_2_2(this, PublicFunc::convertToPoint(1, 6)));
	monster_queue.push_back(new  Bonus_2_4(this, PublicFunc::convertToPoint(4, 6)));
	monster_queue.push_back(new  Bonus_2_5(this, PublicFunc::convertToPoint(8, 6)));
	monster_queue.push_back(new  Bonus_2_3(this, PublicFunc::convertToPoint(11, 6)));

	monster_queue.push_back(new  Bonus_2_1(this, PublicFunc::convertToPoint(0, 5)));
	monster_queue.push_back(new  Bonus_2_3(this, PublicFunc::convertToPoint(2, 5)));

	monster_queue.push_back(new  Bonus_2_1(this, PublicFunc::convertToPoint(4, 4)));
	monster_queue.push_back(new  Bonus_2_1(this, PublicFunc::convertToPoint(11, 4)));
	monster_queue.push_back(new  Bonus_2_6(this, PublicFunc::convertToPoint(8, 3)));

	monster_queue.push_back(new  Bonus_2_1(this, PublicFunc::convertToPoint(0, 2)));
	monster_queue.push_back(new  Bonus_2_3(this, PublicFunc::convertToPoint(2, 2)));
	monster_queue.push_back(new  Bonus_2_7(this, PublicFunc::convertToPoint(4, 2)));
	monster_queue.push_back(new  Bonus_2_2(this, PublicFunc::convertToPoint(9, 2)));
	monster_queue.push_back(new  Bonus_2_3(this, PublicFunc::convertToPoint(11, 2)));

	monster_queue.push_back(new  Bonus_2_4(this, PublicFunc::convertToPoint(5, 0)));

}

