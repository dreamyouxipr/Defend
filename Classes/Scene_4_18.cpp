#include "Scene_4_18.h"



#include "Bonus_4_1.h"
#include "Bonus_4_2.h"
#include "Bonus_4_3.h"
#include "Bonus_4_4.h"
#include "Bonus_4_5.h"
#include "Bonus_4_6.h"
#include "Bonus_4_7.h"



Scene* Scene_4_18::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_4_18::create();
	scene->addChild(layer);
	return scene;
}




void Scene_4_18::initQueue_way()
{

	queue_way.push(Vec2(2, 5));
	queue_way.push(Vec2(2, 4));
	queue_way.push(Vec2(2, 3));
	queue_way.push(Vec2(2, 2));
	queue_way.push(Vec2(2, 1));

	queue_way.push(Vec2(3, 1));

	queue_way.push(Vec2(3, 2));
	queue_way.push(Vec2(3, 3));
	queue_way.push(Vec2(3, 4));
	queue_way.push(Vec2(3, 5));
	
	queue_way.push(Vec2(4, 5));

	queue_way.push(Vec2(4, 4));
	queue_way.push(Vec2(4, 3));
	queue_way.push(Vec2(4, 2));
	queue_way.push(Vec2(4, 1));


	queue_way.push(Vec2(5, 1));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(7, 1));


	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(7, 3));
	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(7, 5));

	queue_way.push(Vec2(8, 5));

	queue_way.push(Vec2(8, 4));
	queue_way.push(Vec2(8, 3));
	queue_way.push(Vec2(8, 2));
	queue_way.push(Vec2(8, 1));

	queue_way.push(Vec2(9, 1));

	queue_way.push(Vec2(9, 2));
	queue_way.push(Vec2(9, 3));
	queue_way.push(Vec2(9, 4));
	queue_way.push(Vec2(9, 5));



	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(3, 0));


	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));
	data->push_back(Vec2(11, 1));



}




void Scene_4_18::initAbleTower()
{
	view_click_gloal->tower_able.push_back(2);
	view_click_gloal->tower_able.push_back(3);

	view_click_gloal->tower_able.push_back(5);

	view_click_gloal->tower_able.push_back(9);
	view_click_gloal->tower_able.push_back(10);
	view_click_gloal->tower_able.push_back(11);
	view_click_gloal->tower_able.push_back(14);
	view_click_gloal->tower_able.push_back(15);
	view_click_gloal->tower_able.push_back(16);


}


void Scene_4_18::initBonus()
{
	
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(0, 4)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(5, 4)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(10, 4)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(0, 2)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(5, 2)));
	monster_queue.push_back(new  Bonus_4_7(this, PublicFunc::convertToPoint(10, 2)));

}
