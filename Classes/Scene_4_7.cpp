#include "Scene_4_7.h"



#include "Bonus_4_1.h"
#include "Bonus_4_2.h"
#include "Bonus_4_3.h"
#include "Bonus_4_4.h"
#include "Bonus_4_5.h"
#include "Bonus_4_6.h"
#include "Bonus_4_7.h"



Scene* Scene_4_7::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_4_7::create();
	scene->addChild(layer);
	return scene;
}



void Scene_4_7::initQueue_way()
{

	
	queue_way.push(Vec2(8, 4));
	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(6, 4));
	queue_way.push(Vec2(5, 4));
	queue_way.push(Vec2(4, 4));
	queue_way.push(Vec2(3, 4));


	queue_way.push(Vec2(2, 4));


	queue_way.push(Vec2(2, 5));
	queue_way.push(Vec2(1, 5));


	queue_way.push(Vec2(1, 4));
	queue_way.push(Vec2(1, 3));



	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(4, 3));
	queue_way.push(Vec2(5, 3));
	queue_way.push(Vec2(6, 3));
	queue_way.push(Vec2(7, 3));
	queue_way.push(Vec2(8, 3));
	queue_way.push(Vec2(9, 3));



	queue_way.push(Vec2(9, 4));
	queue_way.push(Vec2(9, 5));

	queue_way.push(Vec2(10, 5));

	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(3, 0));
	data->push_back(Vec2(1, 1));
	data->push_back(Vec2(0, 1));


	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));
	data->push_back(Vec2(10, 1));
	data->push_back(Vec2(11, 1));
	data->push_back(Vec2(8, 0));

}


void Scene_4_7::initAbleTower()
{
	view_click_gloal->tower_able.push_back(16);
	view_click_gloal->tower_able.push_back(14);
	view_click_gloal->tower_able.push_back(7);
	view_click_gloal->tower_able.push_back(10);

}

void Scene_4_7::initBonus()
{
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(1, 6)));
	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(5, 6)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(9, 6)));


	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 5)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(3, 5)));
	monster_queue.push_back(new  Bonus_4_4(this, PublicFunc::convertToPoint(5, 5)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(7, 5)));

	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(0, 3)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(10,3 )));


	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(1, 2)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(1, 2)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(4, 2)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(7, 2)));
	monster_queue.push_back(new  Bonus_4_3(this, PublicFunc::convertToPoint(10, 2)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(11, 2)));

	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(2, 1)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(4, 1)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(5, 1)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(7, 1)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(8, 1)));



	monster_queue.push_back(new  Bonus_4_5(this, PublicFunc::convertToPoint(5, 0)));


}

