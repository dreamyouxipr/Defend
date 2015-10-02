#include "Scene_1_1.h"
#include "Scene_1_2.h"

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






Scene* Scene_1_1::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_1_1::create();
	scene->addChild(layer);
	return scene;
}



void Scene_1_1::initQueue_way()
{



	queue_way.push(Vec2(1, 5));
	queue_way.push(Vec2(1, 4));
	queue_way.push(Vec2(1, 3));
	queue_way.push(Vec2(1, 2));

	queue_way.push(Vec2(2, 2));
	queue_way.push(Vec2(3, 2));
	queue_way.push(Vec2(4, 2));


	queue_way.push(Vec2(4, 3));


	queue_way.push(Vec2(5, 3));
	queue_way.push(Vec2(6, 3));
	queue_way.push(Vec2(7, 3));

	queue_way.push(Vec2(7, 2));
	queue_way.push(Vec2(8, 2));
	queue_way.push(Vec2(9, 2));
	queue_way.push(Vec2(10, 2));

	queue_way.push(Vec2(10, 3));
	queue_way.push(Vec2(10, 4));
	queue_way.push(Vec2(10, 5));
	


	data->push_back(Vec2(0,0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(1, 1));
	data->push_back(Vec2(0, 1));

	data->push_back(Vec2(11, 0));
	data->push_back(Vec2(10, 0));
	data->push_back(Vec2(9, 0));
	data->push_back(Vec2(10, 1));
	data->push_back(Vec2(11, 1));




}


void Scene_1_1::initAbleTower()
{

	view_click_gloal->tower_able.push_back(1);
	view_click_gloal->tower_able.push_back(2);
	



}

void Scene_1_1::initBonus()
{
	
	
	monster_queue.push_back(new  Bonus_1_1(this, PublicFunc::convertToPoint(2, 3)));


	
	monster_queue.push_back(new  Bonus_1_4(this, PublicFunc::convertToPoint(5, 2)));


	monster_queue.push_back(new  Bonus_1_3(this, PublicFunc::convertToPoint(4, 4)));
	monster_queue.push_back(new  Bonus_1_3(this, PublicFunc::convertToPoint(7, 4)));

	monster_queue.push_back(new  Bonus_1_7(this, PublicFunc::convertToPoint(5, 5)));



	monster_queue.push_back(new  Bonus_1_5(this, PublicFunc::convertToPoint(3, 5)));
	monster_queue.push_back(new  Bonus_1_5(this, PublicFunc::convertToPoint(7, 5)));




}





 void  Scene_1_1:: initScene(Node*p)
 {


	 if (rand() % 2 == 0)
	 {
		 SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/BGMusic01.mp3", true);
	 }
	 else
	 {
		 SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/BGMusic11.mp3", true);
	 }



	base_money = 170;

	key_to_ = "1_1";

	auto bg = Sprite::create("Scene_1/BG0/BG1-hd.pvr.png");
	p->addChild(bg);
	bg->setPosition(WIDTH / 2, 640 / 2);


	auto path__ = Sprite::create("Scene_1/BG1/BG-hd.pvr.png");
	path__->setPosition(WIDTH / 2, -4);
	p->addChild(path__);
	path__->setAnchorPoint(Vec2(0.5, 0));

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_1/Object01-hd.plist");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_1/Monsters01-hd.plist");

	current_level = 1;
	callback_next = [=]()
	{

		Director::getInstance()->replaceScene(Scene_1_2::createScene());


	};

	callback_restart = [=]()
	{
		Director::getInstance()->replaceScene(Scene_1_1::createScene());
	};




}

