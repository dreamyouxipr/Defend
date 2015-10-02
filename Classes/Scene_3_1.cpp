#include "Scene_3_1.h"


#include "Bonus_3_1.h"
#include "Bonus_3_2.h"
#include "Bonus_3_3.h"
#include "Bonus_3_4.h"
#include "Bonus_3_5.h"
#include "Bonus_3_6.h"
#include "Bonus_3_7.h"
#include "Bonus_3_8.h"
#include "Bonus_3_9.h"
#include "Bonus_3_11.h"
#include "Bonus_3_10.h"
#include "Bonus_3_12.h"


Scene* Scene_3_1::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_3_1::create();
	scene->addChild(layer);
	return scene;
}



void Scene_3_1::initQueue_way()
{

	queue_way.push(Vec2(0, 4));
	queue_way.push(Vec2(1, 4));
	queue_way.push(Vec2(2, 4));
	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(2, 2));
	queue_way.push(Vec2(2, 1));

	queue_way.push(Vec2(3, 1));
	queue_way.push(Vec2(4, 1));

	queue_way.push(Vec2(4, 2));
	queue_way.push(Vec2(4, 3));

	queue_way.push(Vec2(5, 3));
	queue_way.push(Vec2(6, 3));
	queue_way.push(Vec2(7, 3));


	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(8, 1));
	queue_way.push(Vec2(9, 1));
	queue_way.push(Vec2(10, 1));

	queue_way.push(Vec2(10, 2));

	queue_way.push(Vec2(10, 3));

	queue_way.push(Vec2(10, 4));

	queue_way.push(Vec2(10, 5));

	

	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));

	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));




}


void Scene_3_1::initAbleTower()
{
	view_click_gloal->tower_able.push_back(6);
	view_click_gloal->tower_able.push_back(7);
	view_click_gloal->tower_able.push_back(8);
	view_click_gloal->tower_able.push_back(9);



}

void Scene_3_1::initBonus()
{
	
	
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(1, 6)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(4, 6)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(5, 6)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(7, 6)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(10, 6)));

	
	monster_queue.push_back(new  Bonus_3_7(this, PublicFunc::convertToPoint(2, 5)));
	monster_queue.push_back(new  Bonus_3_7(this, PublicFunc::convertToPoint(8, 5)));

	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(3, 4)));
	monster_queue.push_back(new  Bonus_3_7(this, PublicFunc::convertToPoint(4, 4)));
	monster_queue.push_back(new  Bonus_3_7(this, PublicFunc::convertToPoint(6, 4)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(8, 4)));

	monster_queue.push_back(new  Bonus_3_9(this, PublicFunc::convertToPoint(0, 2)));
	monster_queue.push_back(new  Bonus_3_1(this, PublicFunc::convertToPoint(3, 2)));
	monster_queue.push_back(new  Bonus_3_1(this, PublicFunc::convertToPoint(8, 2)));
	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(11, 2)));


	monster_queue.push_back(new  Bonus_3_6(this, PublicFunc::convertToPoint(5, 1)));


	monster_queue.push_back(new  Bonus_3_9(this, PublicFunc::convertToPoint(4, 0)));
	monster_queue.push_back(new  Bonus_3_9(this, PublicFunc::convertToPoint(6, 0)));



}

