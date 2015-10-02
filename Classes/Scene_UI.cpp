#include "Scene_UI.h"
#include "View_king.h"

#include "Monster_boss_big.h"

bool Scene_UI::init()
{

	Layer::init();

	Audio::stop_backgroundMusic();



	data = new DatePos_Array;
	data->clear();




	bg = MenuItemSprite::create(Sprite::create("bg.jpg"), Sprite::create("bg.jpg"), [=](Ref*)
	{
		for (int i = 0; i < tower_queue.size(); i++)
		{
			tower_queue[i]->setClick(false);
		}
	});

	bg->setPosition(960 / 2, 640 / 2);

	auto menu = Menu::create(bg, nullptr);
	menu->setPosition(0, 0);
	this->addChild(menu);





	initQueue_way();

	initScene(this);


	this->loadSceneWay();


	/*

		tower_queue.push_back(new Tower_Bottle(this, PublicFunc::convertToPoint(1, 4), 3));

		data->push_back(1, 4);
		*/

	Sprite*start = Sprite::createWithSpriteFrameName("start01.png");
	this->addChild(start);
	start->setPosition(PublicFunc::convertToPoint(queue_way.front().x, queue_way.front().y));
	view_click_gloal = 0;


	view_up_menu = new View_Up_Menu(this, base_money);

	view_king = new View_king(this, PublicFunc::convertToPoint(queue_way.back().x, queue_way.back().y));
	view_click_gloal = new View_Click_gloal(this);

	initAbleTower();


	/*Init bonus*/
	initBonus();

	/**********************************************************************/

	wave_manager = new Wave_Manager(this);
	initWave_manager();

	/*

		wave_manager->push_back(1, Each_One(13, 1), true);
		wave_manager->push_back(1, Each_One(13, 1));

		*/



	this->scheduleUpdate();


	/*初始化  开始   倒计时   */

	view_up_menu->setPause(true);


	auto menu_ = MenuItemImage::create("bg.jpg", "bg.jpg", [=](Ref*)
	{

	});
	menu_->setPosition(960 / 2, 640 / 2);
	menu_->setOpacity(0);

	x = Menu::create(menu_, nullptr);
	x->setPosition(0, 0);
	this->addChild(x, 10);




	sp_count_1 = Sprite::createWithSpriteFrameName("countdown_11.png");
	this->addChild(sp_count_1, 11);
	sp_count_1->setPosition(960 / 2, 640 / 2);

	sp_count_2 = Sprite::createWithSpriteFrameName("countdown_12.png");
	this->addChild(sp_count_2, 11);
	sp_count_2->setPosition(960 / 2, 640 / 2);

	sp_count_2->runAction(RepeatForever::create(RotateBy::create(1.0, -360)));

	SimpleAudioEngine::getInstance()->playEffect("Music/CountDown.mp3");


	sp_count = Sprite::createWithSpriteFrameName("countdown_01.png");

	sp_count->setPosition(960 / 2, 640 / 2);
	this->addChild(sp_count, 11);

	this->runAction(Sequence::create(DelayTime::create(1),
		CallFunc::create([=]()
	{
		sp_count->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("countdown_02.png"));
		SimpleAudioEngine::getInstance()->playEffect("Music/CountDown.mp3");

	})
		, DelayTime::create(1), CallFunc::create([=]()
	{
		sp_count->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("countdown_03.png"));
		SimpleAudioEngine::getInstance()->playEffect("Music/CountDown.mp3");


	})

		, DelayTime::create(1), CallFunc::create([=]()
	{
		sp_count->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("countdown_13.png"));
		SimpleAudioEngine::getInstance()->playEffect("Music/GO.mp3");

	}),


		DelayTime::create(0.3),

		CallFunc::create([=]()
	{
		x->setVisible(false);

		for (int i = 0; i < queue_f.size(); i++)
		{
			queue_f[i]->removeFromParentAndCleanup(true);

		}
		queue_f.clear();

		sp_count->removeFromParentAndCleanup(true);

		view_up_menu->setPause(false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic(false);

		sp_count_1->removeFromParentAndCleanup(true);
		sp_count_2->removeFromParentAndCleanup(true);

		//	x->removeAllChildrenWithCleanup(true);
		x->removeFromParentAndCleanup(true);

	}), nullptr));


	/*倒计时，显示可放的 位置*/
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			if (data->isUseAble(x, y) == true)
			{
				Sprite*sp = Sprite::createWithSpriteFrameName("select_00.png");

				sp->runAction(RepeatForever::create(Sequence::create(
					FadeOut::create(0.5), FadeIn::create(0.5)

					, nullptr)));
				this->addChild(sp);
				sp->setPosition(PublicFunc::convertToPoint(x, y));
				queue_f.push_back(sp);
			}
		}
	}


	sp_bonus_clear = Sprite::createWithSpriteFrameName("targetscleard_CN.png");
	this->addChild(sp_bonus_clear, 4);
	sp_bonus_clear->setPosition(960 / 2, -0);
	sp_bonus_clear->setVisible(false);


	return true;
}


void  Scene_UI::update(float delta)
{

	//	log("size is  %d", monster_queue.size());


	view_up_menu->sync_upgradeAble();


	for (int i = 0; i < monster_queue.size(); i++)
	{
		monster_queue[i]->updateWay();

	}

	for (int i = 0; i < monster_queue.size();)
	{
		if (monster_queue[i]->hp_now <= 0)
		{
			monster_queue[i]->Destory();
			i = 0;
		}
		else
			++i;

	}


	wave_manager->sync();





	for (vector<Tower_UI*>::iterator it = tower_queue.begin(); it != tower_queue.end();)
	{

		if (monster_queue.size() == 0)
		{/*修复 最后一个怪 被打死 金钱无线增长 bug*/
			(*it)->setTarget(0);


			(*it)->sync();
			++it;
			continue;
		}


		if ((*it)->target == 0)/*没有攻击目标*/
		{
			/*寻找最近的目标 攻击*/
			int min = 9999; int min_index = 0; int dis_tmp;
			for (int i = 0; i < monster_queue.size(); i++)
			{
				if (monster_queue[i]->is_Bonus == true)continue;

				dis_tmp = PublicFunc::cacl_distance((*it)->sprite->getPosition(), monster_queue[i]->sprite->getPosition());
				if (dis_tmp < min)
				{
					min = dis_tmp;
					min_index = i;
				}
			}


			(*it)->setTarget(monster_queue[min_index]);
		}


		/*如果攻击范围内的奖励 被选中 那么攻击*/
		for (int i = 0; i < monster_queue.size(); i++)
		{
		//	if (monster_queue[i]->is_Bonus)
			{
				if ((monster_queue[i]->is_selected == true) && PublicFunc::isInattackRange((*it), monster_queue[i]))
				{
					(*it)->setTarget(monster_queue[i]);
					break;
				}
			}
		}



		/*目标是奖励 但未选中  取消攻击*/
		if ((*it)->target->is_selected == false && (*it)->target->is_Bonus == true)
		{
			(*it)->setTarget(0);
		}


		(*it)->sync();
		++it;
	}





}








void  Scene_UI::loadSceneWay()
{


	queue<Vec2> tmp = queue_way;



	while (!tmp.empty())
	{
		/*	Sprite*sp = Sprite::createWithSpriteFrameName("cloud05.png");
			this->addChild(sp);
			sp->setPosition(Vec2(PublicFunc::convertToPoint(tmp.front().x, tmp.front().y)));
			sp->setScaleY(1.3);

			*/



		data->push_back(tmp.front());
		tmp.pop();

	}

}


void  Scene_UI::initWave_manager()
{
	/*
		wave_manager->push_back(1, Each_One(13, 122),true);
		wave_manager->push_back(1, Each_One(13, 222));
		wave_manager->push_back(1, Each_One(13, 122));
		wave_manager->push_back(1, Each_One(13, 76));
		wave_manager->push_back(1, Each_One(13, 111));
		wave_manager->push_back(1, Each_One(13, 111));
		wave_manager->push_back(1, Each_One(13, 222));
		wave_manager->push_back(1, Each_One(13, 122));



		wave_manager->push_back(2, Each_One(2, 122),true);
		wave_manager->push_back(2, Each_One(2, 122));
		wave_manager->push_back(2, Each_One(2, 122));
		wave_manager->push_back(2, Each_One(2, 122));

		*/

}







void Scene_UI::Destroy()
{

	this->unscheduleUpdate();

	delete data;

	/* men lack  bug*/

	for (int i = 0; i < monster_queue.size(); i++)
	{
		monster_queue[i]->Delete();
		//delete monster_queue[i];

	}


	for (int i = 0; i < tower_queue.size(); i++)
	{
		tower_queue[i]->Delete();
		//delete tower_queue[i];
	}

	tower_queue.clear();
	monster_queue.clear();


	view_king->Destory();
	view_click_gloal->Destory();
	view_up_menu->Destory();
	bg->removeFromParentAndCleanup(true);
	wave_manager->Destory();



	this->removeAllChildrenWithCleanup(true);

	//	view_king->sprite->release();

	/*delete view_king;
	delete view_click_gloal;
	delete view_up_menu;
	delete wave_manager;



	*/


	removeRes();

	TextureCache::getInstance()->removeAllTextures();
	//log("%s", TextureCache::getInstance()->getCachedTextureInfo());


	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/Main/BGMusic.mp3", true);




}





void Scene_UI::BonusAllclear()
{
	sp_bonus_clear->stopAllActions();
	sp_bonus_clear->setVisible(true);
	sp_bonus_clear->setPosition(960 / 2, -0);


	sp_bonus_clear->runAction(Sequence::create(MoveBy::create(0.1, Vec2(0, 80)), DelayTime::create(3.0),
		CallFunc::create([=]()
	{
		sp_bonus_clear->setVisible(false);


	}), nullptr));


}
