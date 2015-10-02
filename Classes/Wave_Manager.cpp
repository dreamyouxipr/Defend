#include "Wave_Manager.h"


#include "Monster_boss_big.h"
#include "Monster_fat_boss_green.h"
#include "Monster_fat_green.h"
#include "Monster_fly_blue.h"
#include "Monster_fly_boss_blue.h"
#include "Monster_fly_boss_yellow.h"
#include "Monster_fly_yellow.h"
#include "Monster_land_boss_nima.h"
#include "Monster_land_nima.h"
#include "Monster_land_pink.h"
#include "Monster_land_star.h"
#include "Monster_land_boss_pink.h"
#include "Monster_land_boss_star.h"


#include "Scene_UI.h"



Wave_Manager::Wave_Manager(Scene_UI* scen)
{
	current_wave_index = 0;
	current_monster_index = 0;
	max_wave_index = 0;
	count = 0;
	is_music = false;

	for (int i = 0; i < 30; i++)
	{
		max_monster_index[i] = 0;
	}
	this->scene = scen;
	action = Sprite::create();
	scen->addChild(action);
	isDone_this_wave = true;



}




void  Wave_Manager::sync()/*刷新接口  对monster_queue 操作*/
{
	++count;


	if (current_wave_index > max_wave_index)
	{

		/* win*/

		for (int i = 0; i < scene->monster_queue.size(); i++)
		{
			if (scene->monster_queue[i]->is_Bonus == false)
			{/*还有怪物*/
				return;
			}
		}

		if (scene->view_king->hp == 10)
		{
			scene->view_up_menu->show_win(current_wave_index, max_wave_index, 3);
		}
		else if (scene->view_king->hp >= 6)
		{
			scene->view_up_menu->show_win(current_wave_index, max_wave_index, 2);
		}
		else
		{
			scene->view_up_menu->show_win(current_wave_index, max_wave_index, 1);
		}

		return;
	}






	if (count > 60)
	{
		count = 0;





		for (int i = 0; i < scene->monster_queue.size(); i++)
		{
			if (scene->monster_queue[i]->is_Bonus == false)
			{/*还有怪物*/
				return;
			}
		}



		if (isDone_this_wave == true)
		{
			//	log("is Done start to next wave");
			scene->view_up_menu->sync_wave_info(current_wave_index, max_wave_index);

			runWave(current_wave_index);
			scene->view_up_menu->sync_wave_info(current_wave_index, max_wave_index);

		}









	}

}




void  Wave_Manager::push_back(int wave, Each_One each, bool is)/*初始化 添加怪物*/
{
	wave -= 1;

	if (is)/*手动换挡*/
	{
		current_monster_index = 0;
	}

	array[wave][current_monster_index] = each;

	max_wave_index = wave;

	++max_monster_index[wave];

	current_monster_index++;

	scene->view_up_menu->sync_wave_info(current_wave_index, max_wave_index);


}





void  Wave_Manager::runWave(int wave)
{
	i_run = 0;
	if (isDone_this_wave == true)
	{
		isDone_this_wave = false;

		if (wave == max_wave_index)
		{
		
			
				SimpleAudioEngine::getInstance()->playEffect("Music/Finalwave.mp3");


				Sprite *sp = Sprite::createWithSpriteFrameName("finalwave.png");
				action->getParent()->addChild(sp, 8);
				sp->setPosition(960 / 2, 640 / 2);
				sp;;
				sp->setRotation(180);

				sp->runAction(Sequence::create(RotateTo::create(0.08, 0), DelayTime::create(1.0), RotateTo::create(0.05, -180), CallFunc::create([=]()
				{
					sp->removeFromParentAndCleanup(true);

				}), nullptr));


		}

		action->runAction(Repeat::create(Sequence::create(DelayTime::create(0.5), CCCallFunc::create([=]()
		{
			int i = i_run;
			i_run++;
			switch (array[current_wave_index][i].type)
			{
			case 1:
			{
					  scene->monster_queue.push_back(new Monster_boss_big(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 2:
			{
					  scene->monster_queue.push_back(new Monster_fat_boss_green(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 3:
			{
					  scene->monster_queue.push_back(new Monster_fat_green(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 4:
			{
					  scene->monster_queue.push_back(new Monster_fly_blue(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 5:
			{
					  scene->monster_queue.push_back(new Monster_fly_boss_blue(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 6:
			{
					  scene->monster_queue.push_back(new Monster_fly_boss_yellow(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 7:
			{
					  scene->monster_queue.push_back(new Monster_fly_yellow(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 8:
			{
					  scene->monster_queue.push_back(new Monster_land_boss_nima(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 9:
			{
					  scene->monster_queue.push_back(new Monster_land_boss_pink(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 10:
			{
					   scene->monster_queue.push_back(new Monster_land_boss_star(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 11:
			{
					   scene->monster_queue.push_back(new Monster_land_nima(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 12:
			{
					   scene->monster_queue.push_back(new Monster_land_pink(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;
			case 13:
			{
					   scene->monster_queue.push_back(new Monster_land_star(array[current_wave_index][i].hp, scene, PublicFunc::convertToPoint(scene->queue_way.front().x, scene->queue_way.front().y), scene->queue_way));

			}break;







			}


			if (i_run >= max_monster_index[current_wave_index])
			{	/*5  S 后 下一波*/
				++current_wave_index;
				i_run = -999999;
				action->runAction(Sequence::create(DelayTime::create(5.0), CallFunc::create([=]()
				{
					isDone_this_wave = true;

					i_run = 0;
				}), nullptr));



			}



		}), nullptr), max_monster_index[current_wave_index]));
	}
}
