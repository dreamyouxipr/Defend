#include "Theme_Selector.h"
#include "Scene_Selector_1.h"
#include "Scene_Selector_2.h"
#include "Scene_Selector_3.h"
#include "Scene_Selector_4.h"

#include "Scene_Help.h"

#define  INDEX_MAX 3

bool Theme_Selector::init()
{

	index_now = 0;



	Layer::init();


	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("stages_bg-hd.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("themescene2-hd.plist");



	auto bg = Sprite::createWithSpriteFrameName("ss_bg.png");
	bg->setPosition(960 / 2, 640 / 2);
	this->addChild(bg);


	auto menu_back = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_back_normal.png"),
		Sprite::createWithSpriteFrameName("ss_back_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("stages_bg-hd.plist");
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("themescene2-hd.plist");

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
	sprite->setPosition(960 / 2, 640 / 2);


	auto menu_play = MenuItemSprite::create(Sprite::createWithSpriteFrameName("theme_pack01.png"),
		Sprite::createWithSpriteFrameName("theme_pack01.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		callback_play();
	}
	);
	menu_play->setPosition(sprite->getPosition());




	label = Label::create("1/4", FONT, 50);
	label->setPosition(960 / 2, 40);

	auto dic = Dictionary::createWithContentsOfFile("string_CN.plist");
	auto label1 = Label::create(((String*)dic->objectForKey("select"))->getCString(), FONT, 35);
	label1->setPosition(960 / 2,640- 30);
	this->addChild(label1);

 





	auto menu = Menu::create(menu_play, menu_back, menu_help, menu_lef, menu_rig, nullptr);
	this->addChild(menu);
	menu->setPosition(0, 0);
	this->addChild(sprite);
	this->addChild(label);



	setIndex(index_now);




	return true;

}





void Theme_Selector::setIndex(int index)
{
	sprintf(str, "%d / 4", index + 1);
	label->setString(str);



	if (index == 3)index = 4;

	sprintf(str, "theme_pack0%d.png", index + 1);
	sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));

	

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




Scene* Theme_Selector::createScene()
{
	auto scene = Scene::create();
	auto layer = Theme_Selector::create();
	scene->addChild(layer);
	return scene;
}


void Theme_Selector::callback_play()
{
	switch (index_now)
	{
	case 0:  Director::getInstance()->pushScene(Scene_Selector_1::createScene()); break;
	case 1:  Director::getInstance()->pushScene(Scene_Selector_2::createScene()); break;
	case 2:  Director::getInstance()->pushScene(Scene_Selector_3::createScene()); break;
	case 3:  Director::getInstance()->pushScene(Scene_Selector_4::createScene()); break;

	}

}




