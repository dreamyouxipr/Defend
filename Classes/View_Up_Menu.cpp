#include "View_Up_Menu.h"


#include "PublicFunc.h"

#include "Scene_UI.h"
#include "Scene_Selector_1.h"
void View_Up_Menu::Destory()
{


	bg->removeFromParentAndCleanup(true);
	label_money->removeFromParentAndCleanup(true);
	sprite_pause->removeFromParentAndCleanup(true);
	sprite_is_pause->removeFromParentAndCleanup(true);


	if (label_wave_info)
	{
		label_wave_info->removeAllChildrenWithCleanup(true);
		label_wave_info->removeFromParentAndCleanup(true);
	}

	if (layer_menu_win)
	{
		layer_menu_win->removeAllChildrenWithCleanup(true);
		layer_menu_win->removeFromParentAndCleanup(true);
	}

	if (layer_menu_lose)
	{
		layer_menu_lose->removeAllChildrenWithCleanup(true);
		layer_menu_lose->removeFromParentAndCleanup(true);
	}



	delete this;

}



View_Up_Menu::View_Up_Menu(Node*scene, int mon)
{


	label_wave_info = 0;

	layer_menu_win = 0;

	layer_menu_lose = 0;

	layer_menu = 0;




	money = mon;

	bg = Sprite::createWithSpriteFrameName("MenuBG.png");
	scene->addChild(bg, 5);
	bg->setPosition(960 / 2, 640 - 40);



	label_money = Label::create("", FONT, 30);
	scene->addChild(label_money, 5);
	label_money->setPosition(960 / 2 - 300, 640 - 30);


	label_wave_info = Label::create("0/0", FONT, 30);
	scene->addChild(label_wave_info, 5);
	label_wave_info->setPosition(960 / 2, 640 - 30);


	isPause = false;
	this->scene = scene;



	auto	menu_pause = MenuItemSprite::create(Sprite::createWithSpriteFrameName("pause02.png"), Sprite::createWithSpriteFrameName("pause02.png"),
		[=](Ref*)
	{


		//Director::getInstance()->popScene();

		Audio::play_Button();

		setPause(!isPause);



	}
	);
	menu_pause->setPosition(960 / 2 + 240, 640 - 40);

	sprite_pause = Sprite::create();
	sprite_pause->setPosition(menu_pause->getPosition());








	auto	menu_menu = MenuItemSprite::create(Sprite::createWithSpriteFrameName("menu01.png"), Sprite::createWithSpriteFrameName("menu02.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		show_menu();
	}
	);
	menu_menu->setPosition(960 / 2 + 350, 640 - 40);












	auto menu = Menu::create(menu_pause, menu_menu, nullptr);
	scene->addChild(menu, 6);
	menu->setPosition(0, 0);

	scene->addChild(sprite_pause, 6);

	menu_menu;;

	menu_pause;;
	bg;;
	sprite_pause;;

	sprite_is_pause = Sprite::createWithSpriteFrameName("MenuCenter_02_CN.png");
	sprite_is_pause->setPosition(960 / 2, 640 - 40);
	scene->addChild(sprite_is_pause, 6);

	sprite_is_pause;;

/*
	sprite_is_pause->runAction(RepeatForever::create(Sequence::create(ScaleTo::create(0.2, 1.8), ScaleTo::create(0.1, 1.5), nullptr)));
	*/
	
	sprite_is_pause->setVisible(false);


	updateState();


}

void View_Up_Menu::updateState()
{

	sprintf(ss, "%d", money);
	label_money->setString(ss);

	Scene_UI*scen = (Scene_UI*)bg->getParent();

	for (int i = 0; i < scen->tower_queue.size(); i++)
	{
		if (scen->tower_queue[i]->isClicked())
		{
			scen->tower_queue[i]->view_click->updateState();
			return;
		}
	}

	if (scen->view_click_gloal)
		scen->view_click_gloal->updateState();



	//sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));


}




void  View_Up_Menu::setMoney(int m)
{
	money = m;
	updateState();
}

void  View_Up_Menu::addMoney(int m)
{
	money += m;



	updateState();
}


void  View_Up_Menu::incMoney(int m)
{
	money -= m;
	updateState();
}


bool  View_Up_Menu::buySomething(int need_m)/*外部接口*/
{
	if (money >= need_m)
	{
		incMoney(need_m);
		return true;
	}
	return false;
}


bool  View_Up_Menu::isEnough(int cos)/*外部接口*/
{
	if (money >= cos)
	{
		return true;
	}
	return false;
}



void View_Up_Menu::sync_upgradeAble()
{
	Scene_UI*sce = (Scene_UI*)sprite_pause->getParent();

	for (int i = 0; i < sce->tower_queue.size(); i++)
	{
		if (isEnough(sce->tower_queue[i]->cos_upgrade) && sce->tower_queue[i]->level <= 2)
		{

			sce->tower_queue[i]->sprite_upgrade->setVisible(true);

		}
		else
		{
			sce->tower_queue[i]->sprite_upgrade->setVisible(false);

		}



	}





}


void View_Up_Menu::setPause(bool p)
{


	if (p)
	{
		scene->unscheduleUpdate();

		isPause = true;
		sprite_pause->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("pause12.png"));
		sprite_is_pause->setVisible(isPause);


		Scene_UI*x = (Scene_UI*)scene;
		x->wave_manager->action->pause();

		/*暂停怪物*/
		for (int i = 0; i < x->monster_queue.size(); i++)
		{
			x->monster_queue[i]->sprite->pause();

		}

		/*暂停子弹*/
		for (int i = 0; i < x->tower_queue.size(); i++)
		{
			for (int ii = 0; ii < x->tower_queue[i]->bullet_queue.size(); ii++)
			{
				x->tower_queue[i]->bullet_queue[ii]->sprite->pause();

			}
		}
		return;

	}

	scene->scheduleUpdate();
	sprite_is_pause->setVisible(isPause);

	Scene_UI*x = (Scene_UI*)scene;

	x->wave_manager->action->resume();


	sprite_pause->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("pause02.png"));
	isPause = false;
	sprite_is_pause->setVisible(isPause);

	/*恢复怪物*/
	for (int i = 0; i < x->monster_queue.size(); i++)
	{
		x->monster_queue[i]->sprite->resume();

	}


	/*恢复子弹*/
	for (int i = 0; i < x->tower_queue.size(); i++)
	{
		for (int ii = 0; ii < x->tower_queue[i]->bullet_queue.size(); ii++)
		{
			x->tower_queue[i]->bullet_queue[ii]->sprite->resume();

		}
	}





}





void View_Up_Menu::show_win(int current, int max, int lev)
{
	setPause(true);
	SimpleAudioEngine::getInstance()->playEffect("Music/win.mp3");


	/*数据持久化*/
	if (PublicFunc::getUserDefault_Lev_ByKey(((Scene_UI*)scene)->key_to_) < lev)
	{
		PublicFunc::setUserDefault_Lev(
			((Scene_UI*)scene)->key_to_	
			, lev);



		/*解锁*/
		int max = ((Scene_UI*)scene)->key_to_.at(0)-'0';
 
		char str[30];

		switch (max)
		{
		case  1:
		{
				   sprintf(str, "%d_%d", max,((Scene_UI*)scene)->current_level+1);
				   if (((Scene_UI*)scene)->current_level >= 12)
				   {
					   sprintf(str, "%d_%d", 2,1);
				   }
		}
			break;

		case  2:
		{
				   sprintf(str, "%d_%d", max, ((Scene_UI*)scene)->current_level + 1);
				   if (((Scene_UI*)scene)->current_level >= 12)
				   {
					   sprintf(str, "%d_%d", 3, 1);
				   }
		}
			break;


		case  3:
		{
				   sprintf(str, "%d_%d", max, ((Scene_UI*)scene)->current_level + 1);
				   if (((Scene_UI*)scene)->current_level >= 12)
				   {
					   sprintf(str, "%d_%d", 4, 1);
				   }
		}
			break;


		case  4:
		{
				   sprintf(str, "%d_%d", max, ((Scene_UI*)scene)->current_level + 1);		
		}
			break;

		}

		PublicFunc::setUserDefault_Lev(str, -1);















	}












	layer_menu_win = Layer::create();

	auto sp = MenuItemSprite::create(Sprite::create("bg.jpg"),
		Sprite::create("bg.jpg"), [=](Ref*)
	{

	});

	sp->setPosition(960 / 2, 640 / 2);
	sp->setOpacity(90);


	auto menu1 = Menu::create(sp, nullptr);
	layer_menu_win->addChild(menu1);
	menu1->setPosition(0, 0);




	auto menu_go_on = MenuItemSprite::create(Sprite::createWithSpriteFrameName("continue_normal_CN.png"),
		Sprite::createWithSpriteFrameName("continue_pressed_CN.png"), [=](Ref*)
	{Audio::play_Button();

	std::function<void(void)> x = ((Scene_UI*)scene)->callback_next;

	((Scene_UI*)scene)->Destroy();
	x();
	}

	);
	menu_go_on;;
	menu_go_on->setPosition(960 / 2 + 120, 220);



	auto menu_select = MenuItemSprite::create(Sprite::createWithSpriteFrameName("select_normal_CN.png"),
		Sprite::createWithSpriteFrameName("select_pressed_CN.png"), [=](Ref*)
	{Audio::play_Button();

	((Scene_UI*)scene)->Destroy();
	Director::getInstance()->popScene();

	}

	);


	menu_select;;
	menu_select->setPosition(960 / 2 - 120, 220);




	Sprite *dark = Sprite::createWithSpriteFrameName("win_bg.png");
	layer_menu_win->addChild(dark);
	dark->setPosition(960 / 2, 640 / 2);
	dark;;



	/*胜利背景*/
	Sprite *sp1 = Sprite::createWithSpriteFrameName("win_bg_CN.png");
	layer_menu_win->addChild(sp1);
	sp1->setPosition(960 / 2, 640 / 2);
	sp1;;

	/*击退波数*/

	sprintf(ss, "%d", max + 1);

	Label*lab = Label::create(ss, FONT, 40);
	layer_menu_win->addChild(lab);
	lab->setPosition(960 / 2 + 90, 640 / 2 + 30);



	sprintf(ss, "%d", current);

	Label*lab1 = Label::create(ss, FONT, 40);
	layer_menu_win->addChild(lab1);
	lab1->setPosition(960 / 2 + 5, 640 / 2 + 30);

	lab1->setColor(Color3B(240, 240, 60));


	sprintf(ss, "%d", ((Scene_UI*)scene)->current_level);

	Label*lab12 = Label::create(ss, FONT, 30);
	layer_menu_win->addChild(lab12);
	lab12->setPosition(430, 293);

	lab12->setColor(lab1->getColor());


	/*评分*/
	Sprite*sp2;

	switch (lev)
	{

	case 3:{  sp2 = Sprite::createWithSpriteFrameName("gainhonor_3.png"); }break;
	case 2:{  sp2 = Sprite::createWithSpriteFrameName("gainhonor_2.png"); }break;
	case 1:{  sp2 = Sprite::createWithSpriteFrameName("gainhonor_1.png"); }break;
	}

	layer_menu_win->addChild(sp2);
	sp2->setPosition(960 / 2, 640 / 2 + 140);
	sp2;;



	auto menu = Menu::create(menu_go_on, menu_select, nullptr);
	layer_menu_win->addChild(menu);
	menu->setPosition(0, 0);



	scene->addChild(layer_menu_win, 8);

}


void View_Up_Menu::show_lose(int current, int max)
{
	setPause(true);

	--current;

	SimpleAudioEngine::getInstance()->playEffect("Music/Lose.mp3");

	layer_menu_lose = Layer::create();

	auto sp = MenuItemSprite::create(Sprite::create("bg.jpg"),
		Sprite::create("bg.jpg"), [=](Ref*)
	{

	});

	sp->setPosition(960 / 2, 640 / 2);
	sp->setOpacity(90);


	auto menu1 = Menu::create(sp, nullptr);
	layer_menu_lose->addChild(menu1);
	menu1->setPosition(0, 0);




	auto menu_select = MenuItemSprite::create(Sprite::createWithSpriteFrameName("select_normal_CN.png"),
		Sprite::createWithSpriteFrameName("select_pressed_CN.png"), [=](Ref*)
	{Audio::play_Button();

	((Scene_UI*)scene)->Destroy();

	Director::getInstance()->popScene();

	}

	);


	menu_select;;
	menu_select->setPosition(960 / 2 - 120, 220);



	/*重新开始 */
	auto menu_re = MenuItemSprite::create(Sprite::createWithSpriteFrameName("menu_restart_normal_CN.png"),
		Sprite::createWithSpriteFrameName("menu_restart_pressed_CN.png"), [=](Ref*)
	{
		Audio::play_Button();

		std::function<void(void)> x = ((Scene_UI*)scene)->callback_restart;

		((Scene_UI*)scene)->Destroy();

		x();


	}

	);


	menu_re;;
	menu_re->setPosition(960 / 2 + 120, 220);




	Sprite *dark = Sprite::createWithSpriteFrameName("lose_bg.png");
	layer_menu_lose->addChild(dark);
	dark->setPosition(960 / 2, 640 / 2);
	dark;;



	/*胜利背景*/
	Sprite *sp1 = Sprite::createWithSpriteFrameName("win_bg_CN.png");
	layer_menu_lose->addChild(sp1);
	sp1->setPosition(960 / 2, 640 / 2);
	sp1;;

	/*击退波数*/

	sprintf(ss, "%d", max + 1);

	Label*lab = Label::create(ss, FONT, 40);
	layer_menu_lose->addChild(lab);
	lab->setPosition(960 / 2 + 90, 640 / 2 + 30);



	sprintf(ss, "%d", current);

	Label*lab1 = Label::create(ss, FONT, 40);
	layer_menu_lose->addChild(lab1);
	lab1->setPosition(960 / 2 + 5, 640 / 2 + 30);

	lab1->setColor(Color3B(240, 240, 60));


	sprintf(ss, "%d", ((Scene_UI*)scene)->current_level);

	Label*lab12 = Label::create(ss, FONT, 30);
	layer_menu_lose->addChild(lab12);
	lab12->setPosition(430, 293);

	lab12->setColor(lab1->getColor());




	auto menu = Menu::create(menu_select, menu_re, nullptr);
	layer_menu_lose->addChild(menu);
	menu->setPosition(0, 0);



	scene->addChild(layer_menu_lose, 8);

}





void View_Up_Menu::show_menu()
{


	setPause(true);


	layer_menu = Layer::create();

	auto sp = MenuItemSprite::create(Sprite::create("bg.jpg"),
		Sprite::create("bg.jpg"), [=](Ref*)
	{

	});

	sp->setPosition(960 / 2, 640 / 2);
	sp->setOpacity(90);


	auto menu1 = Menu::create(sp, nullptr);
	layer_menu->addChild(menu1);
	menu1->setPosition(0, 0);



	/*继续游戏*/
	auto menu_go_on = MenuItemSprite::create(Sprite::createWithSpriteFrameName("menu_resume_normal_CN.png"),
		Sprite::createWithSpriteFrameName("menu_resume_pressed_CN.png"), [=](Ref*)
	{

		Audio::play_Button();

		layer_menu->removeAllChildrenWithCleanup(true);
		layer_menu->removeFromParentAndCleanup(true);
		setPause(false);
	}


	);
	menu_go_on;;
	menu_go_on->setPosition(960 / 2, 640 / 2 + 95);


	/*选关 */
	auto menu_select = MenuItemSprite::create(Sprite::createWithSpriteFrameName("select_normal_CN.png"),
		Sprite::createWithSpriteFrameName("select_pressed_CN.png"), [=](Ref*)
	{
		Audio::play_Button();

		((Scene_UI*)scene)->Destroy();
		Director::getInstance()->popScene();

	}

	);


	menu_select;;
	menu_select->setPosition(960 / 2, 640 / 2 - 88);



	/*重新开始 */
	auto menu_re = MenuItemSprite::create(Sprite::createWithSpriteFrameName("menu_restart_normal_CN.png"),
		Sprite::createWithSpriteFrameName("menu_restart_pressed_CN.png"), [=](Ref*)
	{Audio::play_Button();

	std::function<void(void)> x = ((Scene_UI*)scene)->callback_restart;

	((Scene_UI*)scene)->Destroy();

	x();

	}

	);


	menu_re;;
	menu_re->setPosition(960 / 2, 640 / 2 + 2);


	/*背景*/
	Sprite *sp1 = Sprite::createWithSpriteFrameName("menu_bg.png");
	layer_menu->addChild(sp1);
	sp1->setPosition(960 / 2, 640 / 2);
	sp1;;




	auto menu = Menu::create(menu_go_on, menu_select, menu_re, nullptr);
	layer_menu->addChild(menu);
	menu->setPosition(0, 0);



	scene->addChild(layer_menu, 8);








}


