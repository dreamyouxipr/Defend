#ifndef Scene_1_2_
#define Scene_1_2_

#include "object.h"

#include "Scene_UI.h"
#include "Scene_1_3.h"

class Scene_1_2 : public Scene_UI
{
public:
	static Scene* createScene();




	virtual void initQueue_way();
	virtual void initAbleTower();
	virtual void initBonus();


	virtual void removeRes()
	{

		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_1/Monsters01-hd.plist");

		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_1/Object01-hd.plist");

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

		base_money = 450;

		key_to_ = "1_2";

		auto bg = Sprite::create("Scene_1/BG0/BG1-hd.pvr.png");
		p->addChild(bg);
		bg->setPosition(WIDTH / 2, 640 / 2);


		auto path__ = Sprite::create("Scene_1/BG2/BG-hd.pvr.png");
		path__->setPosition(WIDTH / 2, -4);
		p->addChild(path__);
		path__->setAnchorPoint(Vec2(0.5, 0));

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_1/Monsters01-hd.plist");

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_1/Object01-hd.plist");


		current_level = 2;
		callback_next = [=]()
		{

			Director::getInstance()->replaceScene(Scene_1_3::createScene());

		};

		callback_restart = [=]()
		{
			Director::getInstance()->replaceScene(Scene_1_2::createScene());
		};




	}



	virtual void initWave_manager()
	{



		wave_manager->push_back(1, Each_One(11, 1), true);
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));

		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));
		wave_manager->push_back(1, Each_One(11, 1));


		wave_manager->push_back(2, Each_One(13, 32), true);
		wave_manager->push_back(2, Each_One(13, 32));
		wave_manager->push_back(2, Each_One(13, 32));
		wave_manager->push_back(2, Each_One(13, 32));

		wave_manager->push_back(2, Each_One(11, 32));
		wave_manager->push_back(2, Each_One(11, 32));
		wave_manager->push_back(2, Each_One(13, 32));
		wave_manager->push_back(2, Each_One(13, 32));
		wave_manager->push_back(2, Each_One(13, 32));
		wave_manager->push_back(2, Each_One(13, 32));



		wave_manager->push_back(3, Each_One(13, 35), true);
		wave_manager->push_back(3, Each_One(13, 35));
		wave_manager->push_back(3, Each_One(13, 35));
		wave_manager->push_back(3, Each_One(13, 35));

		wave_manager->push_back(3, Each_One(13, 35));
		wave_manager->push_back(3, Each_One(13, 35));
		wave_manager->push_back(3, Each_One(11, 35));
		wave_manager->push_back(3, Each_One(11, 35));
		wave_manager->push_back(3, Each_One(11, 35));
		wave_manager->push_back(3, Each_One(11, 35));









		wave_manager->push_back(4, Each_One(12, 52), true);
		wave_manager->push_back(4, Each_One(12, 52));
		wave_manager->push_back(4, Each_One(12, 52));
		wave_manager->push_back(4, Each_One(12, 52));

		wave_manager->push_back(4, Each_One(12, 52));
		wave_manager->push_back(4, Each_One(13, 52));
		wave_manager->push_back(4, Each_One(13, 52));
		wave_manager->push_back(4, Each_One(13, 52));
		wave_manager->push_back(4, Each_One(13, 52));
		wave_manager->push_back(4, Each_One(13, 52));



		wave_manager->push_back(5, Each_One(13, 81), true);
		wave_manager->push_back(5, Each_One(13, 81));
		wave_manager->push_back(5, Each_One(13, 81));
		wave_manager->push_back(5, Each_One(13, 81));

		wave_manager->push_back(5, Each_One(11, 110));
		wave_manager->push_back(5, Each_One(11, 110));
		wave_manager->push_back(5, Each_One(11, 100));
		wave_manager->push_back(5, Each_One(11, 110));
		wave_manager->push_back(5, Each_One(11, 110));
		wave_manager->push_back(5, Each_One(11, 110));




		wave_manager->push_back(6, Each_One(12, 131), true);
		wave_manager->push_back(6, Each_One(12, 131));
		wave_manager->push_back(6, Each_One(3, 168));
		wave_manager->push_back(6, Each_One(3, 168));

		wave_manager->push_back(6, Each_One(3, 168));
		wave_manager->push_back(6, Each_One(3, 168));
		wave_manager->push_back(6, Each_One(3, 168));
		wave_manager->push_back(6, Each_One(3, 168));
		wave_manager->push_back(6, Each_One(3, 168));
		wave_manager->push_back(6, Each_One(3, 168));





		wave_manager->push_back(7, Each_One(13, 157), true);
		wave_manager->push_back(7, Each_One(13, 157));
		wave_manager->push_back(7, Each_One(13, 157));
		wave_manager->push_back(7, Each_One(13, 157));

		wave_manager->push_back(7, Each_One(3, 168));
		wave_manager->push_back(7, Each_One(3, 168));
		wave_manager->push_back(7, Each_One(3, 168));
		wave_manager->push_back(7, Each_One(3, 168));
		wave_manager->push_back(7, Each_One(3, 168));
		wave_manager->push_back(7, Each_One(3, 168));




		wave_manager->push_back(8, Each_One(11, 148), true);
		wave_manager->push_back(8, Each_One(11, 148));
		wave_manager->push_back(8, Each_One(11, 148));
		wave_manager->push_back(8, Each_One(11, 148));

		wave_manager->push_back(8, Each_One(11, 77));
		wave_manager->push_back(8, Each_One(11, 77));
		wave_manager->push_back(8, Each_One(11, 77));
		wave_manager->push_back(8, Each_One(4, 77));
		wave_manager->push_back(8, Each_One(4, 77));
		wave_manager->push_back(8, Each_One(4, 77));




		wave_manager->push_back(9, Each_One(12, 155), true);
		wave_manager->push_back(9, Each_One(12, 155));
		wave_manager->push_back(9, Each_One(12, 155));
		wave_manager->push_back(9, Each_One(12, 155));

		wave_manager->push_back(9, Each_One(7, 88));
		wave_manager->push_back(9, Each_One(7, 88));
		wave_manager->push_back(9, Each_One(7, 88));
		wave_manager->push_back(9, Each_One(7, 88));
		wave_manager->push_back(9, Each_One(7, 88));
		wave_manager->push_back(9, Each_One(7, 88));




		wave_manager->push_back(10, Each_One(3, 170), true);
		wave_manager->push_back(10, Each_One(3, 170));
		wave_manager->push_back(10, Each_One(3, 170));
		wave_manager->push_back(10, Each_One(3, 170));

		wave_manager->push_back(10, Each_One(3, 170));
		wave_manager->push_back(10, Each_One(4, 99));
		wave_manager->push_back(10, Each_One(4, 99));
		wave_manager->push_back(10, Each_One(4, 99));
		wave_manager->push_back(10, Each_One(4, 99));
		wave_manager->push_back(10, Each_One(4, 99));




		wave_manager->push_back(11, Each_One(4, 98), true);
		wave_manager->push_back(11, Each_One(4, 98));
		wave_manager->push_back(11, Each_One(4, 98));
		wave_manager->push_back(11, Each_One(4, 98));

		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));
		wave_manager->push_back(11, Each_One(3, 180));




		wave_manager->push_back(12, Each_One(13, 178), true);
		wave_manager->push_back(12, Each_One(13, 178));
		wave_manager->push_back(12, Each_One(13, 178));
		wave_manager->push_back(12, Each_One(13, 178));

		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));
		wave_manager->push_back(12, Each_One(7, 100));





		wave_manager->push_back(13, Each_One(12, 180), true);
		wave_manager->push_back(13, Each_One(12, 180));
		wave_manager->push_back(13, Each_One(12, 180));
		wave_manager->push_back(13, Each_One(12, 180));

		wave_manager->push_back(13, Each_One(3, 180));
		wave_manager->push_back(13, Each_One(3, 180));
		wave_manager->push_back(13, Each_One(3, 180));
		wave_manager->push_back(13, Each_One(3, 180));
		wave_manager->push_back(13, Each_One(3, 180));
		wave_manager->push_back(13, Each_One(3, 180));






		wave_manager->push_back(14, Each_One(3, 222), true);
		wave_manager->push_back(14, Each_One(3, 222));
		wave_manager->push_back(14, Each_One(3, 222));
		wave_manager->push_back(14, Each_One(3, 222));

		wave_manager->push_back(14, Each_One(3, 222));
		wave_manager->push_back(14, Each_One(3, 222));
		wave_manager->push_back(14, Each_One(3, 222));
		wave_manager->push_back(14, Each_One(3, 222));
		wave_manager->push_back(14, Each_One(7, 111));
		wave_manager->push_back(14, Each_One(7, 111));





		wave_manager->push_back(15, Each_One(11, 222), true);
		wave_manager->push_back(15, Each_One(11, 222));
		wave_manager->push_back(15, Each_One(11, 222));
		wave_manager->push_back(15, Each_One(11, 222));

		wave_manager->push_back(15, Each_One(9, 2000));
		


























	}
	CREATE_FUNC(Scene_1_2);
};





#endif 
