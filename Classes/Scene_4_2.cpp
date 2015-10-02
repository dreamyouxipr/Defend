#include "Scene_4_2.h"


#include "Bonus_4_1.h"
#include "Bonus_4_2.h"
#include "Bonus_4_3.h"
#include "Bonus_4_4.h"
#include "Bonus_4_5.h"
#include "Bonus_4_6.h"
#include "Bonus_4_7.h"




Scene* Scene_4_2::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_4_2::create();
	scene->addChild(layer);
	return scene;
}



void Scene_4_2::initQueue_way()
{

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
	queue_way.push(Vec2(1, 2));
	queue_way.push(Vec2(1, 1));

	queue_way.push(Vec2(2, 1));
	queue_way.push(Vec2(3, 1));

	queue_way.push(Vec2(3, 2));
	queue_way.push(Vec2(3, 3));


	queue_way.push(Vec2(4, 3));
	queue_way.push(Vec2(5, 3));


	queue_way.push(Vec2(5, 2));
	queue_way.push(Vec2(5, 1));


	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(7, 1));


	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(7, 3));

	queue_way.push(Vec2(8, 3));
	queue_way.push(Vec2(9, 3));
	queue_way.push(Vec2(10, 3));



	data->push_back(Vec2(11, 1));

	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));
	data->push_back(Vec2(8, 0));
}


void Scene_4_2::initAbleTower()
{
	view_click_gloal->tower_able.push_back(14);
	view_click_gloal->tower_able.push_back(2);
	view_click_gloal->tower_able.push_back(9);
	view_click_gloal->tower_able.push_back(11);

}

void Scene_4_2::initBonus()
{
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(2, 6)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(6, 6)));

	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 5)));

	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(2, 4)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(4, 4)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(6, 4)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(8, 4)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(9, 4)));


	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(0, 3)));


	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 2)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(2, 2)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(6, 2)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(8, 2)));

	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 0)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(1, 0)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(4, 0)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(6, 0)));





















}

