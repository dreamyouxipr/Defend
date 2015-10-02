#ifndef Scene_1_8_
#define Scene_1_8_

#include "object.h"

#include "Scene_UI.h"
#include "Scene_1_9.h"

class Scene_1_8 : public Scene_UI
{
public:
	static Scene* createScene();


	virtual void removeRes()
	{


		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_1/Object01-hd.plist");
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_1/Monsters01-hd.plist");

	}

	virtual void initScene(Node*p)
	{

		if (rand() % 2 == 0)
		{
			SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/BGMusic01.mp3", true);
		}
		else
		{
			SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/BGMusic11.mp3", true);
		}

		base_money = 550;

		key_to_ = "1_8";

		auto bg = Sprite::create("Scene_1/BG0/BG1-hd.pvr.png");
		p->addChild(bg);
		bg->setPosition(WIDTH / 2, 640 / 2);


		auto path__ = Sprite::create("Scene_1/BG8/BG-hd.pvr.png");
		path__->setPosition(WIDTH / 2-45, -4);
		p->addChild(path__);
		path__->setAnchorPoint(Vec2(0.5, 0));


		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_1/Object01-hd.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_1/Monsters01-hd.plist");


		current_level = 8;
		callback_next = [=]()
		{

			Director::getInstance()->replaceScene(Scene_1_9::createScene());


		};


		callback_restart = [=]()
		{
			Director::getInstance()->replaceScene(Scene_1_8::createScene());
		};


	}


	virtual void initQueue_way();
	virtual void initAbleTower();
	virtual void initBonus();
	virtual void initWave_manager()
	{




		wave_manager->push_back(1, Each_One(13, 1), true);
		wave_manager->push_back(1, Each_One(13, 1));
		wave_manager->push_back(1, Each_One(13, 1));
		wave_manager->push_back(1, Each_One(13, 1));

		wave_manager->push_back(1, Each_One(13, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));





		wave_manager->push_back(2, Each_One(11, 45), true);
		wave_manager->push_back(2, Each_One(11, 45));
		wave_manager->push_back(2, Each_One(11, 45));
		wave_manager->push_back(2, Each_One(11, 45));

		wave_manager->push_back(2, Each_One(11, 48));
		wave_manager->push_back(2, Each_One(11, 48));
		wave_manager->push_back(2, Each_One(11, 48));
		wave_manager->push_back(2, Each_One(11, 48));
		wave_manager->push_back(2, Each_One(11, 48));
		wave_manager->push_back(2, Each_One(11, 48));



		wave_manager->push_back(3, Each_One(13, 52), true);
		wave_manager->push_back(3, Each_One(13, 52));
		wave_manager->push_back(3, Each_One(13, 52));
		wave_manager->push_back(3, Each_One(13, 52));

		wave_manager->push_back(3, Each_One(13, 52));
		wave_manager->push_back(3, Each_One(13, 52));
		wave_manager->push_back(3, Each_One(3, 52));
		wave_manager->push_back(3, Each_One(3, 52));
		wave_manager->push_back(3, Each_One(3, 52));
		wave_manager->push_back(3, Each_One(3, 52));




		wave_manager->push_back(4, Each_One(12, 60), true);
		wave_manager->push_back(4, Each_One(12, 60));
		wave_manager->push_back(4, Each_One(12, 60));
		wave_manager->push_back(4, Each_One(12, 60));

		wave_manager->push_back(4, Each_One(12, 60));
		wave_manager->push_back(4, Each_One(12, 60));
		wave_manager->push_back(4, Each_One(13, 60));
		wave_manager->push_back(4, Each_One(13, 60));
		wave_manager->push_back(4, Each_One(13, 60));
		wave_manager->push_back(4, Each_One(13, 60));



		wave_manager->push_back(5, Each_One(3, 70), true);
		wave_manager->push_back(5, Each_One(3, 70));
		wave_manager->push_back(5, Each_One(3, 70));
		wave_manager->push_back(5, Each_One(3, 70));

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
		wave_manager->push_back(7, Each_One(7, 120));
		wave_manager->push_back(7, Each_One(7, 120));
		wave_manager->push_back(7, Each_One(7, 120));
		wave_manager->push_back(7, Each_One(7, 120));




		wave_manager->push_back(8, Each_One(11, 100), true);
		wave_manager->push_back(8, Each_One(11, 100));
		wave_manager->push_back(8, Each_One(11, 100));
		wave_manager->push_back(8, Each_One(11, 100));

		wave_manager->push_back(8, Each_One(11, 100));
		wave_manager->push_back(8, Each_One(3, 100));
		wave_manager->push_back(8, Each_One(3, 80));
		wave_manager->push_back(8, Each_One(3, 80));
		wave_manager->push_back(8, Each_One(3, 80));
		wave_manager->push_back(8, Each_One(3, 80));




		wave_manager->push_back(9, Each_One(13, 155), true);
		wave_manager->push_back(9, Each_One(13, 155));
		wave_manager->push_back(9, Each_One(13, 155));
		wave_manager->push_back(9, Each_One(13, 155));

		wave_manager->push_back(9, Each_One(13, 88));
		wave_manager->push_back(9, Each_One(9, 88));
	/*	wave_manager->push_back(9, Each_One(3, 88));
		wave_manager->push_back(9, Each_One(3, 88));
		wave_manager->push_back(9, Each_One(3, 88));
		wave_manager->push_back(9, Each_One(3, 88));

*/



		wave_manager->push_back(10, Each_One(11, 170), true);
		wave_manager->push_back(10, Each_One(11, 170));
		wave_manager->push_back(10, Each_One(11, 170));
		wave_manager->push_back(10, Each_One(11, 170));

		wave_manager->push_back(10, Each_One(11, 170));
		wave_manager->push_back(10, Each_One(7, 99));
		wave_manager->push_back(10, Each_One(7, 99));
		wave_manager->push_back(10, Each_One(7, 99));
		wave_manager->push_back(10, Each_One(7, 99));

		wave_manager->push_back(10, Each_One(7, 99));




		wave_manager->push_back(11, Each_One(12, 200), true);
		wave_manager->push_back(11, Each_One(12, 200));
		wave_manager->push_back(11, Each_One(12, 200));
		wave_manager->push_back(11, Each_One(12, 200));

		wave_manager->push_back(11, Each_One(12, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));




		wave_manager->push_back(12, Each_One(13, 150), true);
		wave_manager->push_back(12, Each_One(13, 150));
		wave_manager->push_back(12, Each_One(13, 150));
		wave_manager->push_back(12, Each_One(13, 150));

		wave_manager->push_back(12, Each_One(13, 100));
		wave_manager->push_back(12, Each_One(13, 100));
		wave_manager->push_back(12, Each_One(4, 100));
		wave_manager->push_back(12, Each_One(4, 150));
		wave_manager->push_back(12, Each_One(4, 100));
		wave_manager->push_back(12, Each_One(4, 100));
		wave_manager->push_back(12, Each_One(4, 100));


		wave_manager->push_back(13, Each_One(12, 222), true);
		wave_manager->push_back(13, Each_One(12, 222));
		wave_manager->push_back(13, Each_One(12, 222));
		wave_manager->push_back(13, Each_One(12, 222));

		wave_manager->push_back(13, Each_One(12, 222));
		wave_manager->push_back(13, Each_One(12, 222));
		wave_manager->push_back(13, Each_One(3, 222));
		wave_manager->push_back(13, Each_One(3, 222));
		wave_manager->push_back(13, Each_One(3, 222));
		wave_manager->push_back(13, Each_One(3, 222));






		wave_manager->push_back(14, Each_One(13, 250), true);
		wave_manager->push_back(14, Each_One(13, 250));
		wave_manager->push_back(14, Each_One(13, 250));
		wave_manager->push_back(14, Each_One(13, 250));

		wave_manager->push_back(14, Each_One(13, 250));
		wave_manager->push_back(14, Each_One(13, 250));
		wave_manager->push_back(14, Each_One(4, 250));
		wave_manager->push_back(14, Each_One(4, 250));
		wave_manager->push_back(14, Each_One(4, 120));
		wave_manager->push_back(14, Each_One(4, 120));



		wave_manager->push_back(15, Each_One(11, 250), true);
		wave_manager->push_back(15, Each_One(11, 250));
		wave_manager->push_back(15, Each_One(11, 250));
		wave_manager->push_back(15, Each_One(11, 250));

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
		wave_manager->push_back(16, Each_One(4, 150));
		wave_manager->push_back(16, Each_One(4, 150));
		wave_manager->push_back(16, Each_One(4, 150));
		wave_manager->push_back(16, Each_One(4, 150));






		wave_manager->push_back(17, Each_One(11, 170), true);
		wave_manager->push_back(17, Each_One(11, 170));
		wave_manager->push_back(17, Each_One(11, 170));
		wave_manager->push_back(17, Each_One(11, 170));

		wave_manager->push_back(17, Each_One(12, 170));
		wave_manager->push_back(17, Each_One(12, 170));
		wave_manager->push_back(17, Each_One(12, 300));
		wave_manager->push_back(17, Each_One(12, 300));
		wave_manager->push_back(17, Each_One(12, 300));
		wave_manager->push_back(17, Each_One(12, 300));




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





		wave_manager->push_back(20, Each_One(8, 3303), true);
		wave_manager->push_back(20, Each_One(5, 3033));
	





		wave_manager->push_back(21, Each_One(11, 333), true);
		wave_manager->push_back(21, Each_One(11, 333));
		wave_manager->push_back(21, Each_One(11, 333));
		wave_manager->push_back(21, Each_One(11, 333));

		wave_manager->push_back(21, Each_One(11, 333));
		wave_manager->push_back(21, Each_One(11, 333));
		wave_manager->push_back(21, Each_One(11, 333));
		wave_manager->push_back(21, Each_One(11, 333));
		wave_manager->push_back(21, Each_One(11, 220));
		wave_manager->push_back(21, Each_One(11, 220));



		wave_manager->push_back(22, Each_One(11, 333), true);
		wave_manager->push_back(22, Each_One(11, 333));
		wave_manager->push_back(22, Each_One(11, 333));
		wave_manager->push_back(22, Each_One(11, 333));

		wave_manager->push_back(22, Each_One(11, 333));
		wave_manager->push_back(22, Each_One(3, 333));
		wave_manager->push_back(22, Each_One(3, 333));
		wave_manager->push_back(22, Each_One(3, 333));
	





		wave_manager->push_back(23, Each_One(13, 333), true);
		wave_manager->push_back(23, Each_One(13, 333));
		wave_manager->push_back(23, Each_One(13, 333));
		wave_manager->push_back(23, Each_One(13, 333));

		wave_manager->push_back(23, Each_One(13, 333));
		wave_manager->push_back(23, Each_One(13, 333));
		wave_manager->push_back(23, Each_One(12, 333));
		wave_manager->push_back(23, Each_One(12, 333));
		wave_manager->push_back(23, Each_One(12, 220));
		wave_manager->push_back(23, Each_One(12, 220));


		wave_manager->push_back(24, Each_One(11, 333), true);
		wave_manager->push_back(24, Each_One(11, 333));
		wave_manager->push_back(24, Each_One(11, 333));
		wave_manager->push_back(24, Each_One(1113, 333));

		wave_manager->push_back(24, Each_One(11, 333));
		wave_manager->push_back(24, Each_One(3, 333));
		wave_manager->push_back(24, Each_One(3, 333));
		wave_manager->push_back(24, Each_One(3, 333));
		wave_manager->push_back(24, Each_One(3, 220));
		wave_manager->push_back(24, Each_One(3, 220));




		wave_manager->push_back(25, Each_One(2, 333), true);
		wave_manager->push_back(25, Each_One(12, 333));
		wave_manager->push_back(25, Each_One(12, 333));
		wave_manager->push_back(25, Each_One(12, 333));

		wave_manager->push_back(25, Each_One(12, 333));
		wave_manager->push_back(25, Each_One(12, 333));
		wave_manager->push_back(25, Each_One(12, 333));
		wave_manager->push_back(25, Each_One(12, 333));
		wave_manager->push_back(25, Each_One(12, 220));
		wave_manager->push_back(25, Each_One(12, 220));


	}

	CREATE_FUNC(Scene_1_8);
};





#endif 
