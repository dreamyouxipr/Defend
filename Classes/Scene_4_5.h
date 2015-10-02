#ifndef Scene_4_5_
#define Scene_4_5_

#include "object.h"

#include "Scene_UI.h"

#include "Scene_4_6.h"
class Scene_4_5: public Scene_UI
{
public:
	static Scene* createScene();


	virtual void initQueue_way();
	virtual void initAbleTower();
	virtual void initBonus();
	virtual void removeRes()
	{


		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_4/Object02-hd.plist");
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_4/Monsters01-hd.plist");

	}

	virtual void initScene(Node*p)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/BGMusic06.mp3", true);

		base_money = 750;
		key_to_ = "4_5";

		auto bg = Sprite::create("Scene_4/BG0/BG2-hd.pvr.ccz");
		p->addChild(bg);
		bg->setPosition(WIDTH / 2, 640 / 2);


		auto path__ = Sprite::create("Scene_4/BG5/BG-hd.pvr.ccz");
		path__->setPosition(WIDTH / 2, 0-5);
		p->addChild(path__);
		path__->setAnchorPoint(Vec2(0.5, 0));

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_4/Monsters01-hd.plist");

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_4/Object02-hd.plist");

		current_level = 5;
		callback_next = [=]()
		{

			Director::getInstance()->replaceScene(Scene_4_6::createScene());


		};


	callback_restart = [=]()
	{
		Director::getInstance()->replaceScene(Scene_4_5::createScene());
	};


	}
	virtual void initWave_manager()
	{




		wave_manager->push_back(1, Each_One(13, 1), true);
		wave_manager->push_back(1, Each_One(13, 1));
		wave_manager->push_back(1, Each_One(13, 1));
		wave_manager->push_back(1, Each_One(13, 1));

		wave_manager->push_back(1, Each_One(13, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));





		wave_manager->push_back(2, Each_One(12, 45), true);
		wave_manager->push_back(2, Each_One(12, 45));
		wave_manager->push_back(2, Each_One(12, 45));
		wave_manager->push_back(2, Each_One(12, 45));

		wave_manager->push_back(2, Each_One(12, 48));
		wave_manager->push_back(2, Each_One(12, 48));
		wave_manager->push_back(2, Each_One(12, 48));
		wave_manager->push_back(2, Each_One(12, 48));
		wave_manager->push_back(2, Each_One(12, 48));
		wave_manager->push_back(2, Each_One(12, 48));



		wave_manager->push_back(3, Each_One(12, 52), true);
		wave_manager->push_back(3, Each_One(12, 52));
		wave_manager->push_back(3, Each_One(12, 52));
		wave_manager->push_back(3, Each_One(12, 52));

		wave_manager->push_back(3, Each_One(11, 52));
		wave_manager->push_back(3, Each_One(11, 52));
		wave_manager->push_back(3, Each_One(11, 52));
		wave_manager->push_back(3, Each_One(11, 52));
		wave_manager->push_back(3, Each_One(11, 52));
		wave_manager->push_back(3, Each_One(11, 52));




		wave_manager->push_back(4, Each_One(12, 60), true);
		wave_manager->push_back(4, Each_One(12, 60));
		wave_manager->push_back(4, Each_One(12, 60));
		wave_manager->push_back(4, Each_One(12, 60));

		wave_manager->push_back(4, Each_One(11, 60));
		wave_manager->push_back(4, Each_One(11, 60));
		wave_manager->push_back(4, Each_One(11, 60));
		wave_manager->push_back(4, Each_One(11, 60));
		wave_manager->push_back(4, Each_One(11, 60));
		wave_manager->push_back(4, Each_One(11, 60));



		wave_manager->push_back(5, Each_One(13, 70), true);
		wave_manager->push_back(5, Each_One(13, 70));
		wave_manager->push_back(5, Each_One(13, 70));
		wave_manager->push_back(5, Each_One(13, 70));

		wave_manager->push_back(5, Each_One(11, 100));
		wave_manager->push_back(5, Each_One(11, 100));
		wave_manager->push_back(5, Each_One(11, 100));
		wave_manager->push_back(5, Each_One(11, 100));
		wave_manager->push_back(5, Each_One(11, 100));
		wave_manager->push_back(5, Each_One(11, 100));




		wave_manager->push_back(6, Each_One(13, 90), true);
		wave_manager->push_back(6, Each_One(13, 90));
		wave_manager->push_back(6, Each_One(13, 90));
		wave_manager->push_back(6, Each_One(13, 90));

		wave_manager->push_back(6, Each_One(13, 110));
		wave_manager->push_back(6, Each_One(13, 110));
		wave_manager->push_back(6, Each_One(12, 110));
		wave_manager->push_back(6, Each_One(12, 110));
		wave_manager->push_back(6, Each_One(12, 110));
		wave_manager->push_back(6, Each_One(12, 110));





		wave_manager->push_back(7, Each_One(11, 100), true);
		wave_manager->push_back(7, Each_One(11, 100));
		wave_manager->push_back(7, Each_One(11, 100));
		wave_manager->push_back(7, Each_One(11, 100));

		wave_manager->push_back(7, Each_One(11, 120));
		wave_manager->push_back(7, Each_One(4, 120));
		wave_manager->push_back(7, Each_One(4, 120));
		wave_manager->push_back(7, Each_One(4, 120));
		wave_manager->push_back(7, Each_One(4, 120));
		wave_manager->push_back(7, Each_One(4, 120));




		wave_manager->push_back(8, Each_One(11, 100), true);
		wave_manager->push_back(8, Each_One(11, 100));
		wave_manager->push_back(8, Each_One(11, 100));
		wave_manager->push_back(8, Each_One(11, 100));

		wave_manager->push_back(8, Each_One(11, 100));
		wave_manager->push_back(8, Each_One(13, 100));
		wave_manager->push_back(8, Each_One(13, 80));
		wave_manager->push_back(8, Each_One(13, 80));
		wave_manager->push_back(8, Each_One(13, 80));
		wave_manager->push_back(8, Each_One(13, 80));




		wave_manager->push_back(9, Each_One(13, 155), true);
		wave_manager->push_back(9, Each_One(13, 155));
		wave_manager->push_back(9, Each_One(13, 155));
		wave_manager->push_back(9, Each_One(13, 155));

		wave_manager->push_back(9, Each_One(13, 88));
		wave_manager->push_back(9, Each_One(13, 88));
		wave_manager->push_back(9, Each_One(3, 88));
		wave_manager->push_back(9, Each_One(3, 88));
		wave_manager->push_back(9, Each_One(3, 88));
		wave_manager->push_back(9, Each_One(3, 88));





		wave_manager->push_back(10, Each_One(2, 170), true);
		wave_manager->push_back(10, Each_One(2, 170));
		wave_manager->push_back(10, Each_One(2, 170));
		wave_manager->push_back(10, Each_One(2, 170));

		/*	wave_manager->push_back(10, Each_One(11, 170));
		wave_manager->push_back(10, Each_One(7, 99));
		wave_manager->push_back(10, Each_One(7, 99));
		wave_manager->push_back(10, Each_One(7, 99));
		wave_manager->push_back(10, Each_One(7, 99));

		wave_manager->push_back(10, Each_One(7, 99));

		*/



		wave_manager->push_back(11, Each_One(10, 200), true);
		wave_manager->push_back(11, Each_One(10, 200));
		wave_manager->push_back(11, Each_One(10, 200));
		wave_manager->push_back(11, Each_One(10, 200));

		wave_manager->push_back(11, Each_One(10, 180));
		wave_manager->push_back(11, Each_One(10, 180));
		wave_manager->push_back(11, Each_One(10, 180));
		wave_manager->push_back(11, Each_One(10, 180));
		wave_manager->push_back(11, Each_One(10, 180));
		wave_manager->push_back(11, Each_One(10, 180));




		wave_manager->push_back(12, Each_One(12, 150), true);
		wave_manager->push_back(12, Each_One(12, 150));
		wave_manager->push_back(12, Each_One(12, 150));
		wave_manager->push_back(12, Each_One(12, 150));

		wave_manager->push_back(12, Each_One(12, 100));
		wave_manager->push_back(12, Each_One(12, 100));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 150));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));


		wave_manager->push_back(13, Each_One(3, 222), true);
		wave_manager->push_back(13, Each_One(3, 222));
		wave_manager->push_back(13, Each_One(3, 222));
		wave_manager->push_back(13, Each_One(3, 222));

		wave_manager->push_back(13, Each_One(4, 222));
		wave_manager->push_back(13, Each_One(4, 222));
		wave_manager->push_back(13, Each_One(4, 222));
		wave_manager->push_back(13, Each_One(4, 222));
		wave_manager->push_back(13, Each_One(4, 222));
		wave_manager->push_back(13, Each_One(4, 222));






		wave_manager->push_back(14, Each_One(2, 250), true);
		wave_manager->push_back(14, Each_One(2, 250));
		wave_manager->push_back(14, Each_One(2, 250));
		wave_manager->push_back(14, Each_One(2, 250));

		wave_manager->push_back(14, Each_One(2, 250));
		wave_manager->push_back(14, Each_One(2, 250));
		wave_manager->push_back(14, Each_One(2, 250));
		wave_manager->push_back(14, Each_One(2, 250));
		wave_manager->push_back(14, Each_One(2, 120));
		wave_manager->push_back(14, Each_One(2, 120));



		wave_manager->push_back(15, Each_One(12, 250), true);
		wave_manager->push_back(15, Each_One(12, 250));
		wave_manager->push_back(15, Each_One(12, 250));
		wave_manager->push_back(15, Each_One(12, 250));

		wave_manager->push_back(15, Each_One(11, 250));
		wave_manager->push_back(15, Each_One(11, 250));
		wave_manager->push_back(15, Each_One(11, 250));
		wave_manager->push_back(15, Each_One(11, 250));
		wave_manager->push_back(15, Each_One(11, 120));
		wave_manager->push_back(15, Each_One(11, 120));





		wave_manager->push_back(16, Each_One(13, 280), true);
		wave_manager->push_back(16, Each_One(13, 280));
		wave_manager->push_back(16, Each_One(13, 280));
		wave_manager->push_back(16, Each_One(13, 280));

		wave_manager->push_back(16, Each_One(13, 280));
		wave_manager->push_back(16, Each_One(13, 280));
		wave_manager->push_back(16, Each_One(7, 150));
		wave_manager->push_back(16, Each_One(7, 150));
		wave_manager->push_back(16, Each_One(7, 150));
		wave_manager->push_back(16, Each_One(7, 150));






		wave_manager->push_back(17, Each_One(3, 170), true);
		wave_manager->push_back(17, Each_One(3, 170));
		wave_manager->push_back(17, Each_One(3, 170));
		wave_manager->push_back(17, Each_One(3, 170));

		wave_manager->push_back(17, Each_One(3, 170));
		wave_manager->push_back(17, Each_One(3, 170));
		wave_manager->push_back(17, Each_One(3, 300));
		wave_manager->push_back(17, Each_One(3, 300));
		wave_manager->push_back(17, Each_One(3, 300));
		wave_manager->push_back(17, Each_One(3, 300));




		wave_manager->push_back(18, Each_One(13, 300), true);
		wave_manager->push_back(18, Each_One(13, 300));
		wave_manager->push_back(18, Each_One(13, 300));
		wave_manager->push_back(18, Each_One(13, 300));

		wave_manager->push_back(18, Each_One(12, 300));
		wave_manager->push_back(18, Each_One(12, 300));
		wave_manager->push_back(18, Each_One(12, 300));
		wave_manager->push_back(18, Each_One(12, 300));
		wave_manager->push_back(18, Each_One(12, 300));
		wave_manager->push_back(18, Each_One(12, 300));





		wave_manager->push_back(19, Each_One(13, 333), true);
		wave_manager->push_back(19, Each_One(13, 333));
		wave_manager->push_back(19, Each_One(13, 333));
		wave_manager->push_back(19, Each_One(13, 333));

		wave_manager->push_back(19, Each_One(13, 333));
		wave_manager->push_back(19, Each_One(13, 333));
		wave_manager->push_back(19, Each_One(13, 333));
		wave_manager->push_back(19, Each_One(13, 333));
		wave_manager->push_back(19, Each_One(4, 220));
		wave_manager->push_back(19, Each_One(4, 220));




		wave_manager->push_back(20, Each_One(1, 4000));






	}



	CREATE_FUNC(Scene_4_5);
};





#endif 
