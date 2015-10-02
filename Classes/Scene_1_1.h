#ifndef Scene_1_1_
#define Scene_1_1_

#include "object.h"

#include "Scene_UI.h"


class Scene_1_1 : public Scene_UI
{
public:
	static Scene* createScene();


	virtual void initQueue_way();
	virtual void initAbleTower();
	virtual void initBonus();

	virtual void initScene(Node*p);

	virtual void initWave_manager()
	{

		wave_manager->push_back(1, Each_One(12, 1), true);
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));
		wave_manager->push_back(1, Each_One(12, 1));



		wave_manager->push_back(2, Each_One(12, 13), true);
		wave_manager->push_back(2, Each_One(12, 13));
		wave_manager->push_back(2, Each_One(12, 13));

		wave_manager->push_back(2, Each_One(13, 20));
		wave_manager->push_back(2, Each_One(13, 20));
		wave_manager->push_back(2, Each_One(13, 20));
		wave_manager->push_back(2, Each_One(13, 20));
		wave_manager->push_back(2, Each_One(13, 20));
		wave_manager->push_back(2, Each_One(13, 20));
		wave_manager->push_back(2, Each_One(13, 20));


		wave_manager->push_back(3, Each_One(12, 16), true);
		wave_manager->push_back(3, Each_One(12, 16));
		wave_manager->push_back(3, Each_One(12, 16));
		wave_manager->push_back(3, Each_One(12, 16));
		wave_manager->push_back(3, Each_One(12, 16));
		wave_manager->push_back(3, Each_One(12, 16));

		wave_manager->push_back(3, Each_One(13, 41));
		wave_manager->push_back(3, Each_One(13, 41));
		wave_manager->push_back(3, Each_One(13, 41));
		wave_manager->push_back(3, Each_One(13, 41));


		wave_manager->push_back(4, Each_One(12, 35), true);
		wave_manager->push_back(4, Each_One(12, 35));
		wave_manager->push_back(4, Each_One(12, 35));
		wave_manager->push_back(4, Each_One(12, 35));
		wave_manager->push_back(4, Each_One(13, 41));
		wave_manager->push_back(4, Each_One(13, 41));
		wave_manager->push_back(4, Each_One(13, 41));
		wave_manager->push_back(4, Each_One(13, 41));
		wave_manager->push_back(4, Each_One(13, 41));
		wave_manager->push_back(4, Each_One(13, 41));


		wave_manager->push_back(5, Each_One(13, 41), true);
		wave_manager->push_back(5, Each_One(13, 41));
		wave_manager->push_back(5, Each_One(13, 41));
		wave_manager->push_back(5, Each_One(13, 41));
		wave_manager->push_back(5, Each_One(13, 41));
		wave_manager->push_back(5, Each_One(13, 41));
		wave_manager->push_back(5, Each_One(13, 41));
		wave_manager->push_back(5, Each_One(13, 41));

		wave_manager->push_back(5, Each_One(12, 48));
		wave_manager->push_back(5, Each_One(12, 48));


		wave_manager->push_back(6, Each_One(13, 48), true);
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));
		wave_manager->push_back(6, Each_One(13, 48));


		wave_manager->push_back(7, Each_One(12, 43), true);
		wave_manager->push_back(7, Each_One(12, 43));
		wave_manager->push_back(7, Each_One(12, 43));
		wave_manager->push_back(7, Each_One(12, 43));
		wave_manager->push_back(7, Each_One(12, 43));
		wave_manager->push_back(7, Each_One(12, 43));
		wave_manager->push_back(7, Each_One(12, 43));
		wave_manager->push_back(7, Each_One(12, 43));

		wave_manager->push_back(7, Each_One(4, 19));
		wave_manager->push_back(7, Each_One(4, 19));

		wave_manager->push_back(8, Each_One(13, 39), true);
		wave_manager->push_back(8, Each_One(13, 39));
		wave_manager->push_back(8, Each_One(13, 39));
		wave_manager->push_back(8, Each_One(13, 39));
		wave_manager->push_back(8, Each_One(13, 39));
		wave_manager->push_back(8, Each_One(13, 39));
		wave_manager->push_back(8, Each_One(7, 19));
		wave_manager->push_back(8, Each_One(7, 19));
		wave_manager->push_back(8, Each_One(7, 19));
		wave_manager->push_back(8, Each_One(7, 19));

		wave_manager->push_back(9, Each_One(12, 38), true);
		wave_manager->push_back(9, Each_One(12, 38));
		wave_manager->push_back(9, Each_One(12, 38));
		wave_manager->push_back(9, Each_One(12, 38));
		 
		wave_manager->push_back(9, Each_One(11, 58));
		wave_manager->push_back(9, Each_One(11, 58));
		wave_manager->push_back(9, Each_One(11, 58));
		wave_manager->push_back(9, Each_One(11, 58));
		wave_manager->push_back(9, Each_One(11, 58));
		wave_manager->push_back(9, Each_One(11, 58));


		wave_manager->push_back(10, Each_One(12, 38), true);
		wave_manager->push_back(10, Each_One(12, 38));
		wave_manager->push_back(10, Each_One(12, 38));
		wave_manager->push_back(10, Each_One(12, 38));

		wave_manager->push_back(10, Each_One(11, 58));
		wave_manager->push_back(10, Each_One(11, 58));
		wave_manager->push_back(10, Each_One(11, 58));
		wave_manager->push_back(10, Each_One(11, 58));
		wave_manager->push_back(10, Each_One(11, 58));
		wave_manager->push_back(10, Each_One(11, 58));


		wave_manager->push_back(11, Each_One(3, 61), true);
		wave_manager->push_back(11, Each_One(3, 61));
		wave_manager->push_back(11, Each_One(3, 61));
		wave_manager->push_back(11, Each_One(3, 61));

		wave_manager->push_back(11, Each_One(3, 61));
		wave_manager->push_back(11, Each_One(3, 61));
		wave_manager->push_back(11, Each_One(3, 61));
		wave_manager->push_back(11, Each_One(3, 61));
		wave_manager->push_back(11, Each_One(7, 25));
		wave_manager->push_back(11, Each_One(7, 25));




		wave_manager->push_back(12, Each_One(13, 48), true);
		wave_manager->push_back(12, Each_One(13, 48));
		wave_manager->push_back(12, Each_One(13, 48));
		wave_manager->push_back(12, Each_One(13, 48));

		wave_manager->push_back(12, Each_One(11, 71));
		wave_manager->push_back(12, Each_One(11, 71));
		wave_manager->push_back(12, Each_One(11, 71));
		wave_manager->push_back(12, Each_One(11, 71));
		wave_manager->push_back(12, Each_One(11, 71));
		wave_manager->push_back(12, Each_One(11, 71));


		wave_manager->push_back(13, Each_One(4, 42), true);
		wave_manager->push_back(13, Each_One(4, 42));
		wave_manager->push_back(13, Each_One(7, 42));
		wave_manager->push_back(13, Each_One(7, 42));

		wave_manager->push_back(13, Each_One(7, 42));
		wave_manager->push_back(13, Each_One(7, 42));
		wave_manager->push_back(13, Each_One(7, 42));
		wave_manager->push_back(13, Each_One(7, 42));
		wave_manager->push_back(13, Each_One(7, 42));
		wave_manager->push_back(13, Each_One(7, 42));




		wave_manager->push_back(14, Each_One(12, 38), true);
		wave_manager->push_back(14, Each_One(12, 38));
		wave_manager->push_back(14, Each_One(12, 38));

		wave_manager->push_back(14, Each_One(7, 71));

		wave_manager->push_back(14, Each_One(7, 71));
		wave_manager->push_back(14, Each_One(7, 71));
		wave_manager->push_back(14, Each_One(7, 71));
		wave_manager->push_back(14, Each_One(7, 71));
		wave_manager->push_back(14, Each_One(7, 71));
		wave_manager->push_back(14, Each_One(7, 71));



		wave_manager->push_back(15, Each_One(11, 98), true);
		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));

		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));
		wave_manager->push_back(15, Each_One(11, 98));



	}


	virtual void removeRes()
	{
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_1/Monsters01-hd.plist");



		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_1/Object01-hd.plist");

	}


	CREATE_FUNC(Scene_1_1);
};





#endif 
