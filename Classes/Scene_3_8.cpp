#include "Scene_3_8.h"


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


Scene* Scene_3_8::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_3_8::create();
	scene->addChild(layer);
	return scene;
}



void Scene_3_8::initQueue_way()
{

	queue_way.push(Vec2(10, 2));
	queue_way.push(Vec2(10, 3));
	queue_way.push(Vec2(10, 4));
	queue_way.push(Vec2(10, 5));
	queue_way.push(Vec2(9, 5));
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

	queue_way.push(Vec2(3, 2));
	queue_way.push(Vec2(3, 1));


	queue_way.push(Vec2(4, 1));
	queue_way.push(Vec2(5, 1));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(8, 1));

	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));


	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));



}


void Scene_3_8::initAbleTower()
{
	
	
	view_click_gloal->tower_able.push_back(6);
	view_click_gloal->tower_able.push_back(7);
	view_click_gloal->tower_able.push_back(8);
	view_click_gloal->tower_able.push_back(9);
	view_click_gloal->tower_able.push_back(10);
	view_click_gloal->tower_able.push_back(11);
	view_click_gloal->tower_able.push_back(12);
	view_click_gloal->tower_able.push_back(13);




}

void Scene_3_8::initBonus()
{
	
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(1, 6)));
	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(3, 6)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(4, 6)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(6, 6)));
	monster_queue.push_back(new  Bonus_3_9(this, PublicFunc::convertToPoint(8, 6)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(10, 6)));

	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(1, 5)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(2, 5)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(4, 5)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(6, 5)));

	monster_queue.push_back(new  Bonus_3_8(this, PublicFunc::convertToPoint(11, 4)));

	monster_queue.push_back(new  Bonus_3_4(this, PublicFunc::convertToPoint(0, 3)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(4, 3)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(6, 3)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(8, 3)));

	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(4, 2)));
	monster_queue.push_back(new  Bonus_3_1(this, PublicFunc::convertToPoint(6, 2)));
	monster_queue.push_back(new  Bonus_3_5(this, PublicFunc::convertToPoint(7, 2)));
	monster_queue.push_back(new  Bonus_3_10(this, PublicFunc::convertToPoint(9, 2)));

	monster_queue.push_back(new  Bonus_3_6(this, PublicFunc::convertToPoint(1, 1)));
	monster_queue.push_back(new  Bonus_3_9(this, PublicFunc::convertToPoint(6, 0)));


}

