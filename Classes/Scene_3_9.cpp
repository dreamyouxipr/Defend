#include "Scene_3_9.h"

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



Scene* Scene_3_9::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_3_9::create();
	scene->addChild(layer);
	return scene;
}



void Scene_3_9::initQueue_way()
{

	queue_way.push(Vec2(10, 5));
	queue_way.push(Vec2(9, 5));
	queue_way.push(Vec2(8, 5));
	queue_way.push(Vec2(7, 5));
	queue_way.push(Vec2(6, 5));
	queue_way.push(Vec2(5, 5));
	queue_way.push(Vec2(4, 5));
	queue_way.push(Vec2(3, 5));
	queue_way.push(Vec2(2, 5));

	queue_way.push(Vec2(2, 4));
	queue_way.push(Vec2(3, 4));
	queue_way.push(Vec2(4, 4));
	queue_way.push(Vec2(5, 4));
	queue_way.push(Vec2(6, 4));
	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(8, 4));
	queue_way.push(Vec2(9, 4));


	queue_way.push(Vec2(9, 3));
	queue_way.push(Vec2(8, 3));
	queue_way.push(Vec2(7, 3));
	queue_way.push(Vec2(6, 3));
	queue_way.push(Vec2(5, 3));
	queue_way.push(Vec2(4, 3));
	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(1, 3));

	queue_way.push(Vec2(1, 2));
	queue_way.push(Vec2(2, 2));
	queue_way.push(Vec2(3, 2));
	queue_way.push(Vec2(4, 2));
	queue_way.push(Vec2(5, 2));
	queue_way.push(Vec2(6, 2));
	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(8, 2));
	queue_way.push(Vec2(9, 2));
	queue_way.push(Vec2(10, 2));


	queue_way.push(Vec2(10, 1));
	queue_way.push(Vec2(9, 1));
	queue_way.push(Vec2(8, 1));
	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(5, 1));
	queue_way.push(Vec2(4, 1));
	queue_way.push(Vec2(3, 1));
	queue_way.push(Vec2(2, 1));

	queue_way.push(Vec2(2, 0));
	queue_way.push(Vec2(3, 0));
	queue_way.push(Vec2(4, 0));
	queue_way.push(Vec2(5, 0));
	queue_way.push(Vec2(6, 0));

	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));


	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));





}


void Scene_3_9::initAbleTower()
{


	view_click_gloal->tower_able.push_back(2);
	view_click_gloal->tower_able.push_back(10);
	view_click_gloal->tower_able.push_back(13);



}

void Scene_3_9::initBonus()
{

	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(1, 6)));
	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(3, 6)));
	monster_queue.push_back(new  Bonus_3_2(this, PublicFunc::convertToPoint(4, 6)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(5, 6)));
	monster_queue.push_back(new  Bonus_3_2(this, PublicFunc::convertToPoint(6, 6)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(7, 6)));
	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(8, 6)));
	monster_queue.push_back(new  Bonus_3_2(this, PublicFunc::convertToPoint(9, 6)));
	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(10, 6)));


	monster_queue.push_back(new  Bonus_3_9(this, PublicFunc::convertToPoint(0, 5)));

	monster_queue.push_back(new  Bonus_3_1(this, PublicFunc::convertToPoint(1, 4)));


	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(0, 3)));
	monster_queue.push_back(new  Bonus_3_7(this, PublicFunc::convertToPoint(10, 3)));


	monster_queue.push_back(new  Bonus_3_1(this, PublicFunc::convertToPoint(11, 2)));
	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(1, 1)));

}


