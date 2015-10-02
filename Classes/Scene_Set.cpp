#include "PublicFunc.h"
#include "Scene_Set.h"

bool Scene_Set::init()
{

	/****************************/
	Layer::init();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_Set/setting01-hd.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_Set/setting02-hd.plist");



	auto bg = Sprite::createWithSpriteFrameName("setting_bg.png");
	bg->setPosition(960 / 2, 640 / 2);
	this->addChild(bg);



	auto menu_back = MenuItemSprite::create(Sprite::createWithSpriteFrameName("setting_home_normal.png"),
		Sprite::createWithSpriteFrameName("setting_home_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_Set/setting01-hd.plist");
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_Set/setting02-hd.plist");


		this->removeAllChildrenWithCleanup(true);
		Director::getInstance()->popScene();

	});
	menu_back->setPosition(960 / 2 - 400, 640 - 50);



	auto dic = Dictionary::createWithContentsOfFile("string_CN.plist");

	Label*l = Label::create(((String*)dic->objectForKey("about"))->getCString(), FONT, 30);
	this->addChild(l);
	l->setPosition(960 / 2, 640 / 2 - 80);


	Sprite*lab = Sprite::createWithSpriteFrameName("options_selected_CN.png");

	this->addChild(lab);
	lab->setPosition(960 / 2, 640 - 50);




	Sprite*sp = Sprite::createWithSpriteFrameName("setting_bg_CN.png");
	this->addChild(sp);
	sp->setPosition(960 / 2, 640 / 2 + 50);




	menu_eff_on = MenuItemSprite::create(Sprite::createWithSpriteFrameName("soundfx_on_CN.png"),
		Sprite::createWithSpriteFrameName("soundfx_on_CN.png"), [=](Ref*)
	{
		Audio::play_Button();

		setEffectEnable(false);


	}

	);
	menu_eff_on->setPosition(960 / 2 - 100, 640 / 2 + 70);

	menu_mus_on = MenuItemSprite::create(Sprite::createWithSpriteFrameName("bgmusic_on_CN.png"),
		Sprite::createWithSpriteFrameName("bgmusic_on_CN.png"), [=](Ref*)
	{
		Audio::play_Button();
		setMusicEnable(false);


	}
	);
	menu_mus_on->setPosition(960 / 2 + 100, 640 / 2 + 70);









	menu_eff_off = MenuItemSprite::create(Sprite::createWithSpriteFrameName("soundfx_off_CN.png"),
		Sprite::createWithSpriteFrameName("soundfx_off_CN.png"), [=](Ref*)
	{

		Audio::play_Button();
		setEffectEnable(true);

	}

	);
	menu_eff_off->setPosition(960 / 2 - 100, 640 / 2 + 70);

	menu_mus_off = MenuItemSprite::create(Sprite::createWithSpriteFrameName("bgmusic_off_CN.png"),
		Sprite::createWithSpriteFrameName("bgmusic_off_CN.png"), [=](Ref*)
	{
		Audio::play_Button();
		setMusicEnable(true);

	}
	);
	menu_mus_off->setPosition(960 / 2 + 100, 640 / 2 + 70);




	setMusicEnable(!UserDefault::getInstance()->getBoolForKey("isMusic"));
	setEffectEnable(!UserDefault::getInstance()->getBoolForKey("isEffect"));








	auto	men_re = MenuItemSprite::create(Sprite::createWithSpriteFrameName("resetgame_normal_CN.png"),
		Sprite::createWithSpriteFrameName("resetgame_pressed_CN.png"), [=](Ref*)
	{
		layer_reset->setVisible(true);


	}
	);
	men_re->setPosition(960 / 2+140, 640 / 2 - 220);



	auto	men_un = MenuItemLabel::create(Label::create(((String*)dic->objectForKey("un"))->getCString(), FONT, 30), [=](Ref*)
	{
		layer_unlockall->setVisible(true);


	}
	);
	men_un->setPosition(960 / 2-140, 640 / 2 - 220);



	auto menu = Menu::create(menu_back, men_un, menu_eff_on, menu_mus_on,
		menu_mus_off, menu_eff_off, men_re, nullptr);
	this->addChild(menu);
	menu->setPosition(0, 0);



	/*reset*/
	{

		layer_reset = Layer::create();





		auto sp11 = MenuItemSprite::create(Sprite::create("bg.jpg"),
			Sprite::create("bg.jpg"), [=](Ref*)
		{

		});

		sp11->setPosition(960 / 2, 640 / 2);
		sp11->setOpacity(90);


		auto menu1 = Menu::create(sp11, nullptr);
		layer_reset->addChild(menu1);
		menu1->setPosition(0, 0);

		auto lab22 = Label::create(((String*)dic->objectForKey("sure"))->getCString(), FONT, 80);
		layer_reset->addChild(lab22);
		lab22->setPosition(960 / 2, 640 / 2 + 200);


		auto menu_yes = MenuItemLabel::create(Label::create("Yes", FONT, 80)
			, [=](Ref*)
		{

			Audio::play_Button();
			reset();
			layer_reset->setVisible(false);

		}


		);
		menu_yes->setPosition(960 / 2 - 200, 640 / 2);



		auto menu_ = MenuItemLabel::create(Label::create("No", FONT, 80)
			, [=](Ref*)
		{

			Audio::play_Button();
			layer_reset->setVisible(false);

		}


		);
		menu_->setPosition(960 / 2 + 200, 640 / 2);

		auto menu11 = Menu::create(menu_yes, menu_, nullptr);
		layer_reset->addChild(menu11);
		menu11->setPosition(0, 0);

	}






	/*unlockall*/

	{

		layer_unlockall = Layer::create();





		auto sp11 = MenuItemSprite::create(Sprite::create("bg.jpg"),
			Sprite::create("bg.jpg"), [=](Ref*)
		{

		});

		sp11->setPosition(960 / 2, 640 / 2);
		sp11->setOpacity(90);


		auto menu1 = Menu::create(sp11, nullptr);
		layer_unlockall->addChild(menu1);
		menu1->setPosition(0, 0);

		auto lab22 = Label::create(((String*)dic->objectForKey("unlock"))->getCString(), FONT, 80);
		layer_unlockall->addChild(lab22);
		lab22->setPosition(960 / 2, 640 / 2 + 200);


		auto menu_yes = MenuItemLabel::create(Label::create("Yes", FONT, 80)
			, [=](Ref*)
		{

			Audio::play_Button();
			unclockAll();
			layer_unlockall->setVisible(false);

		}


		);
		menu_yes->setPosition(960 / 2 - 200, 640 / 2);



		auto menu_ = MenuItemLabel::create(Label::create("No", FONT, 80)
			, [=](Ref*)
		{

			Audio::play_Button();
			layer_unlockall->setVisible(false);

		}


		);
		menu_->setPosition(960 / 2 + 200, 640 / 2);

		auto menu11 = Menu::create(menu_yes, menu_, nullptr);
		layer_unlockall->addChild(menu11);
		menu11->setPosition(0, 0);


	}
	layer_reset->setVisible(false);
	layer_unlockall->setVisible(false);


	this->addChild(layer_reset);
	this->addChild(layer_unlockall);



	return true;
}




Scene* Scene_Set::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_Set::create();
	scene->addChild(layer);
	return scene;
}



void  Scene_Set::setEffectEnable(bool b)
{
	menu_eff_off->setVisible(!b);
	menu_eff_on->setVisible(b);
	PublicFunc::setEffectEnable(b);

}


void   Scene_Set::setMusicEnable(bool b)
{
	menu_mus_off->setVisible(!b);
	menu_mus_on->setVisible(b);
	PublicFunc::setMusicEnable(b);

}



void Scene_Set::unclockAll()
{
	char s[100];

	for (int i = 0; i < 12; i++)
	{
		sprintf(s, "1_%d", i + 1);
		PublicFunc::setUserDefault_Lev(s, -1);
	}

	for (int i = 0; i < 12; i++)
	{
		sprintf(s, "2_%d", i + 1);
		PublicFunc::setUserDefault_Lev(s, -1);
	}

	for (int i = 0; i < 12; i++)
	{
		sprintf(s, "3_%d", i + 1);
		PublicFunc::setUserDefault_Lev(s, -1);

	}

	for (int i = 0; i < 18; i++)
	{
		sprintf(s, "4_%d", i + 1);
		PublicFunc::setUserDefault_Lev(s, -1);

	}


}



void Scene_Set::reset()
{
	char s[100];

	for (int i = 0; i < 12; i++)
	{
		sprintf(s, "1_%d", i + 1);
		PublicFunc::setUserDefault_AllClear(s, false);
		PublicFunc::setUserDefault_Lev(s, 0);
	}

	for (int i = 0; i < 12; i++)
	{
		sprintf(s, "2_%d", i + 1);
		PublicFunc::setUserDefault_AllClear(s, false);
		PublicFunc::setUserDefault_Lev(s, 0);
	}

	for (int i = 0; i < 12; i++)
	{
		sprintf(s, "3_%d", i + 1);
		PublicFunc::setUserDefault_AllClear(s, false);
		PublicFunc::setUserDefault_Lev(s, 0);

	}

	for (int i = 0; i < 18; i++)
	{
		sprintf(s, "4_%d", i + 1);
		PublicFunc::setUserDefault_AllClear(s, false);
		PublicFunc::setUserDefault_Lev(s, 0);

	}


}