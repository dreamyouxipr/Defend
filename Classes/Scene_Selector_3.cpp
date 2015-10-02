#include "Scene_Selector_3.h"


#include "Scene_3_1.h"
#include "Scene_3_2.h"
#include "Scene_3_3.h"
#include "Scene_3_4.h"
#include "Scene_3_5.h"
#include "Scene_3_6.h"
#include "Scene_3_7.h"
#include "Scene_3_8.h"
#include "Scene_3_9.h"
#include "Scene_3_10.h"
#include "Scene_3_11.h"
#include "Scene_3_12.h"




#include "Scene_Help.h"
#define  INDEX_MAX 11

bool Scene_Selector_3::init()
{

	index_now = 0;
	//SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_4/stages_theme6-hd.plist");

	Layer::init();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_3/stages_theme3-hd.plist");

	auto bg = Sprite::createWithSpriteFrameName("ss_bg.png");
	bg->setPosition(960 / 2, 640 / 2);
	this->addChild(bg);


	auto bg1 = Sprite::createWithSpriteFrameName("ss_cloud.png");
	bg1->setPosition(960 / 2, 640 / 2);
	this->addChild(bg1);


	sprite_tower_able = Sprite::create();

	this->addChild(sprite_tower_able);
	sprite_tower_able->setPosition(960 / 2, 640 / 2 - 150);
	sprite_tower_able;;


	auto menu_play = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_play_normal_CN.png"),
		Sprite::createWithSpriteFrameName("ss_play_pressed_CN.png"),
		[=](Ref*)
	{

		if (sprite_lock->isVisible() == true)return;

		Audio::play_Button();
		callback_play();
	}
	);
	menu_play->setPosition(960 / 2, 640 / 2 - 250);


	auto menu_back = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_back_normal.png"),
		Sprite::createWithSpriteFrameName("ss_back_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_3/stages_theme3-hd.plist");

		Director::getInstance()->popScene();
	}
	);
	menu_back->setPosition(960 / 2 - 420, 640 - 28);




	auto menu_help = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_help_normal.png"),
		Sprite::createWithSpriteFrameName("ss_help_pressed.png"),
		[=](Ref*)
	{

		Audio::play_Button();
		Director::getInstance()->pushScene(Scene_Help::createScene());

	}
	);
	menu_help->setPosition(960 / 2 + 420, 640 - 28);








	menu_lef = MenuItemSprite::create(Sprite::createWithSpriteFrameName("recommend_left_normal.png"),
		Sprite::createWithSpriteFrameName("recommend_left_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();
		if (index_now <= 0)return;
		setIndex(--index_now);

	}
	);
	menu_lef->setPosition(960 / 2 - 400, 640 / 2);




	menu_rig = MenuItemSprite::create(Sprite::createWithSpriteFrameName("recommend_right_normal.png"),
		Sprite::createWithSpriteFrameName("recommend_right_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();
		if (index_now >= INDEX_MAX)return;
		setIndex(++index_now);


	}
	);
	menu_rig->setPosition(960 / 2 + 400, 640 / 2);


	menu_lef->setScale(2.0);
	menu_rig->setScale(2.0);



	sprite = Sprite::create();
	sprite->setPosition(960 / 2, 640 / 2 + 80);

	auto menu_play1 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_map01.png"),
		Sprite::createWithSpriteFrameName("ss_map01.png"),
		[=](Ref*)
	{
		if (sprite_lock->isVisible() == true)return;

		Audio::play_Button();

		callback_play();
	}
	);
	menu_play1->setPosition(sprite->getPosition());




	auto dic = Dictionary::createWithContentsOfFile("string_CN.plist");
	auto label1 = Label::create(((String*)dic->objectForKey("select"))->getCString(), FONT, 35);
	label1->setPosition(960 / 2, 640 - 30);
	this->addChild(label1);



	auto menu = Menu::create(menu_play, menu_back, menu_help, menu_lef, menu_rig, menu_play1, nullptr);
	this->addChild(menu);
	menu->setPosition(0, 0);

	this->addChild(sprite);


	sprite_allclear = Sprite::createWithSpriteFrameName("gainhonor_4.png");
	this->addChild(sprite_allclear);
	sprite_allclear->setPosition(960 / 2, 640 / 2);
	sprite_allclear;;




	sprite_lev = Sprite::createWithSpriteFrameName("gainhonor_3.png");
	this->addChild(sprite_lev);
	sprite_lev->setPosition(960 / 2 + 150, 640 / 2);
	sprite_lev;;


	sprite_lock = Sprite::createWithSpriteFrameName("ss_locked_icon.png");
	this->addChild(sprite_lock);
	sprite_lock->setPosition(960 / 2 + 150, 640 / 2);

	sprite_lock_1 = Sprite::createWithSpriteFrameName("ss_locked_CN.png");
	this->addChild(sprite_lock_1);
	sprite_lock_1->setPosition(menu_play->getPosition());


	setIndex(index_now);

	return true;
}





void Scene_Selector_3::setIndex(int index)
{

	sync();
	sprite_lock_1->setVisible(sprite_lock->isVisible());

	if (index < 9)
	{
		sprintf(str, "ss_map0%d.png", index + 1);
		sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
		sprintf(str, "ss_towers_0%d.png", index + 1);
		sprite_tower_able->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
	}
	else
	{
		sprintf(str, "ss_map%d.png", index + 1);
		sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
		sprintf(str, "ss_towers_%d.png", index + 1);
		sprite_tower_able->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
	}


	if (index_now <= 0)
	{
		menu_lef->setVisible(false);
	}
	else
	{
		menu_lef->setVisible(true);

	}
	if (index_now >= INDEX_MAX)
	{
		menu_rig->setVisible(false);
	}
	else
	{
		menu_rig->setVisible(true);

	}

}




Scene* Scene_Selector_3::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_Selector_3::create();
	scene->addChild(layer);
	return scene;
}


void Scene_Selector_3::callback_play()
{

	//	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_3/stages_theme3-hd.plist");
	 
	switch (index_now)
	{
	case 0:  Director::getInstance()->pushScene(Scene_3_1::createScene()); break;
	case 1:  Director::getInstance()->pushScene(Scene_3_2::createScene()); break;
	case 2:  Director::getInstance()->pushScene(Scene_3_3::createScene()); break;
	case 3:  Director::getInstance()->pushScene(Scene_3_4::createScene()); break;
	case 4:  Director::getInstance()->pushScene(Scene_3_5::createScene()); break;
	case 5:  Director::getInstance()->pushScene(Scene_3_6::createScene()); break;
	case 6:  Director::getInstance()->pushScene(Scene_3_7::createScene()); break;
	case 7:  Director::getInstance()->pushScene(Scene_3_8::createScene()); break;
	case 8:  Director::getInstance()->pushScene(Scene_3_9::createScene()); break;
	case 9:  Director::getInstance()->pushScene(Scene_3_10::createScene()); break;
	case 10:  Director::getInstance()->pushScene(Scene_3_11::createScene()); break;
	case 11:  Director::getInstance()->pushScene(Scene_3_12::createScene()); break;

	}



}






void  Scene_Selector_3::sync()
{

	sprite_lock->setVisible(false);

	sprintf(str, "all_3_%d", index_now + 1);

	sprite_allclear->setVisible(PublicFunc::getUserDefault_AllClear_ByKey(str));

	sprite_lev;;

	sprintf(str, "3_%d", index_now + 1);


	switch (PublicFunc::getUserDefault_Lev_ByKey(str))
	{
	case 3:{
			   sprite_lev->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gainhonor_3.png"));
			   sprite_lev->setVisible(true);
	}break;
	case 2:{
			   sprite_lev->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gainhonor_2.png"));
			   sprite_lev->setVisible(true);
	}break;
	case 1:{
			   sprite_lev->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gainhonor_1.png"));
			   sprite_lev->setVisible(true);
	}break;

	case  0:
	{
			   sprite_lock->setVisible(true);
			   sprite_lev->setVisible(false);


	}break;

	case  -1:
	{
				sprite_lock->setVisible(false);
				sprite_lev->setVisible(false);
	}break;




	}

}