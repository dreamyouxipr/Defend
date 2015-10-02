#include "Scene_Welcome.h"
#include "Theme_Selector.h"
#include "Scene_Help.h"
#include "Scene_Set.h"
#include "PublicFunc.h"
bool Scene_Welcome::init()
{


	PublicFunc::setMusicEnable(!UserDefault::getInstance()->getBoolForKey("isMusic"));
	PublicFunc::setEffectEnable(!UserDefault::getInstance()->getBoolForKey("isEffect"));

	
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/Main/BGMusic.mp3", true);


	Layer::init();






	auto bg = Sprite::createWithSpriteFrameName("mainbg.png");
	bg->setPosition(960 / 2, 640 / 2);
	this->addChild(bg);



	auto c2 = Sprite::createWithSpriteFrameName("cloud2.png");
	this->addChild(c2);
	c2->setPosition(-100, 640 / 2 + 160);

	c2->runAction(RepeatForever::create(
		Sequence::create(MoveBy::create(40, Vec2(1800, 0)), MoveBy::create(0, Vec2(-1800, 0)), nullptr)));
	c2->setOpacity(90);


	auto c21 = Sprite::createWithSpriteFrameName("cloud1.png");
	this->addChild(c21);
	c21->setPosition(-120, 640 / 2 + 50);

	c21->runAction(RepeatForever::create(
		Sequence::create(MoveBy::create(40, Vec2(1800, 0)), MoveBy::create(0, Vec2(-1800, 0)), nullptr)));
	c21->setOpacity(90);





	/*叶子动画*/

	auto lef1 = Sprite::createWithSpriteFrameName("leaf-1.png");
	lef1->setPosition(960 / 2 - 80, 640 / 2 + 90);
	lef1->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(lef1);
	lef1->runAction(RepeatForever::create(Sequence::create(DelayTime::create(2.0), RotateBy::create(0.1, 15),
		RotateBy::create(0.1, -15), nullptr)));





	auto lef3 = Sprite::createWithSpriteFrameName("leaf-3.png");
	lef3->setPosition(960 / 2 + 80, 640 / 2 + 90);
	lef3->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(lef3);


	lef3->runAction(Sequence::create(DelayTime::create(3.0), CallFunc::create([=]()
	{
		lef3->runAction(RepeatForever::create(Sequence::create(DelayTime::create(3.0), RotateBy::create(0.1, 15),
			RotateBy::create(0.1, -15), nullptr)));



	}), nullptr));




	auto lef2 = Sprite::createWithSpriteFrameName("leaf-2.png");
	lef2->setPosition(960 / 2, 640 / 2 + 90);
	lef2->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(lef2);


	lef2->runAction(Sequence::create(DelayTime::create(1.0), CallFunc::create([=]()
	{
		lef2->runAction(RepeatForever::create(Sequence::create(DelayTime::create(3.0), RotateBy::create(0.1, 15),
			RotateBy::create(0.1, -15), nullptr)));



	}), nullptr));



	auto carrot = Sprite::createWithSpriteFrameName("carrot.png");
	carrot->setPosition(960 / 2, 640 / 2 + 50);
	this->addChild(carrot);

	auto title = Sprite::createWithSpriteFrameName("mainbg_CN.png");
	title->setPosition(960 / 2, 640 / 2);
	this->addChild(title);






	auto menu_ad = MenuItemSprite::create(Sprite::createWithSpriteFrameName("btn_adventure_normal_CN.png"),
		Sprite::createWithSpriteFrameName("btn_adventure_pressed_CN.png"),

		[=](Ref*)
	{Audio::play_Button();

	Director::getInstance()->pushScene(Theme_Selector::createScene());

	});
	menu_ad->setPosition(960 / 2, 640 / 2 - 250);





	auto menu_set = MenuItemSprite::create(Sprite::createWithSpriteFrameName("btn_setting_normal.png"),
		Sprite::createWithSpriteFrameName("btn_setting_pressed.png"),

		[=](Ref*)
	{Audio::play_Button();

	Director::getInstance()->pushScene(Scene_Set::createScene());


	});
	menu_set->setPosition(960 / 2 - 300, 640 / 2 - 100);




	auto menu_help = MenuItemSprite::create(Sprite::createWithSpriteFrameName("btn_help_normal.png"),
		Sprite::createWithSpriteFrameName("btn_help_pressed.png"),

		[=](Ref*)
	{Audio::play_Button();

	Director::getInstance()->pushScene(Scene_Help::createScene());


	});
	menu_help->setPosition(960 / 2 + 300, 640 / 2 - 100);


	auto menu_close = MenuItemSprite::create(Sprite::createWithSpriteFrameName("btn_bg.png"),
		Sprite::createWithSpriteFrameName("btn_bg.png"),

		[=](Ref*)
	{
	
		exit(0);



	});
	menu_close->setPosition(960 - 100, 640 - 80);





	auto menu = Menu::create(menu_ad, menu_set, menu_help, menu_close, nullptr);
	this->addChild(menu);
	menu->setPosition(0, 0);




	auto fly = Sprite::createWithSpriteFrameName("bird.png");
	this->addChild(fly);
	fly->setPosition(960 / 2 - 280, 640 / 2 + 200);

	fly->runAction(RepeatForever::create(
		Sequence::create(MoveBy::create(2.5, Vec2(0, -50)), MoveBy::create(2.5, Vec2(0, 50)), nullptr)));










	return true;
}




Scene* Scene_Welcome::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_Welcome::create();
	scene->addChild(layer);
	return scene;
}







Scene* logo::createScene()
{
	auto scene = Scene::create();
	auto layer = logo::create();
	scene->addChild(layer);
	return scene;
}


bool logo::init()
{
	Layer::init();


	Sprite*bg = Sprite::create("logo.png");

	bg->setPosition(960/2, 640 / 2);
	this->addChild(bg);

	this->runAction(Sequence::create(DelayTime::create(0.5), CallFunc::create([=]()
	{
	
		//加载资源
		{	/*生命周期 整个程序*/

			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/BGMusic01.mp3");
			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/BGMusic02.mp3");
			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/BGMusic03.mp3");
			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/BGMusic06.mp3");
			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/BGMusic11.mp3");
			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/BGMusic12.mp3");

			SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/Main/BGMusic.mp3");










			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("mainscene1-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("recommend-hd.plist");

			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameOver/gamemenu-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameOver/gameover0-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameOver/gameover-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("item/Items02-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("item/Items00-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Items01-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TBottle-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TShit-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TStar-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TBall-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TFan-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TFireBottle-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TBlueStar-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TSun-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TRocket-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TPin-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TArrow-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TSnow-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TPlane-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TFish-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TCuttle-hd.plist");
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tower/TAnchor-hd.plist");



		}



	
	
	}), DelayTime::create(5), CallFunc::create([=]{
		
		Director::getInstance()->replaceScene(CCTransitionFade::create(0.5, Scene_Welcome::createScene()));

	}), nullptr));


	return true;
}











