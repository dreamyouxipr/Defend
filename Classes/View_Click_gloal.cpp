#include "View_Click_gloal.h"
#include "Scene_UI.h"
#include "Tower_Shit.h"
#include "Tower_Star.h"
#include "Tower_Ball.h"
#include "Tower_Fan.h"
#include "Tower_FireBottle.h"
#include "Tower_BlueStar.h"
#include "Tower_Sun.h"
#include "Tower_Rocket.h"
#include "Tower_Pin.h"
#include "Tower_Arrow.h"
#include "Tower_Snow.h"
#include "Tower_Plane.h"
#include "Tower_Fish.h"
#include "Tower_Cuttle.h"
#include "Tower_Anchor.h"
Scene_UI*scene;



void View_Click_gloal::Destory()
{
	menu_buy->removeAllChildrenWithCleanup(true);
	delete this;

}



void View_Click_gloal::doClickAction()
{
	/* 显示可购买 炮塔菜单*/
	DatePos_Array* data = scene->data;
	if (data->isUseAble(x_now, y_now) == false)return;
	array[x_now][y_now]->setOpacity(100);
	setBuyVisable(true);


}





View_Click_gloal::View_Click_gloal(Node*p)
{
	scene = (Scene_UI*)p;
	DatePos_Array* data = scene->data;

	x_now = y_now = 0;

	for (int x = 0; x < 12; x++)/*新建格子菜单 除了路径其他地方都有  */
	{
		for (int y = 0; y < 7; y++)
		{
			array[x][y] = 0;
			if (!data->isUseAble(x, y))continue;

			auto m = MenuItemSprite::create(
				Sprite::createWithSpriteFrameName("select_01.png"),
				Sprite::createWithSpriteFrameName("select_01.png"),
				[=](Ref*)
			{

				if (!data->isUseAble(x, y) || setAllVisFalse())
				{
					/*已有一个炮塔被点击 清空*/
					setBuyVisable(false);
					return;
				}

				if (array[x][y]->getOpacity() == 0)
				{
					for (int i = 0; i < scene->tower_queue.size(); i++)
					{
						if (scene->tower_queue[i]->isClicked())
						{
							/*如果已点击 炮塔 则放弃选择安置炮塔*/
							scene->tower_queue[i]->setClick(false);
							return;
						}
					}
					//data->push_back(x, y);
					x_now = x;
					y_now = y;

					doClickAction();
				}

			}
			);
			m->setPosition(PublicFunc::convertToPoint(x, y));
			m;;
			m->setOpacity(0);
			array[x][y] = m;

			auto menu = Menu::create(m, nullptr);
			menu->setPosition(0, 0);
			scene->addChild(menu);



			auto ani = Animation::create();
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_00.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_01.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_02.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_03.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_04.png"));


			ani->setDelayPerUnit(0.1);
			ani->setRestoreOriginalFrame(false);
			ani->setLoops(-1);

			m->getNormalImage()->
				runAction(Animate::create(ani));



		}
	}



	/*购买 炮塔菜单*/
	/*1号*/
	auto menu_11 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Bottle01.png"),
		Sprite::createWithSpriteFrameName("Bottle01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(100))
		{

			if (data->isUseAble(x_now, y_now))
			{
				data->push_back(x_now, y_now);
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				scene->tower_queue.push_back(
					new Tower_Bottle(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);
	menu_1 = Sprite::create();
	menu_11->setTag(1);

	/*2号*/
	auto menu_21 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Shit01.png"),
		Sprite::createWithSpriteFrameName("Shit01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(120))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Shit(scene, PublicFunc::convertToPoint(x_now, y_now), 1));
			}
		}

	}
	);

	menu_2 = Sprite::create();
	menu_21->setTag(2);







	/*3号*/
	auto menu_31 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Star01.png"),
		Sprite::createWithSpriteFrameName("Star01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(160))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Star(scene, PublicFunc::convertToPoint(x_now, y_now), 1));
			}
		}

	}
	);

	menu_3 = Sprite::create();
	menu_31->setTag(3);








	/*4号*/
	auto menu_41 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Ball01.png"),
		Sprite::createWithSpriteFrameName("Ball01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(160))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Ball(scene, PublicFunc::convertToPoint(x_now, y_now), 1));
			}
		}

	}
	);

	menu_4 = Sprite::create();
	menu_41->setTag(4);





	/*5号*/
	auto menu_51 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Fan01.png"),
		Sprite::createWithSpriteFrameName("Fan01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(160))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Fan(scene, PublicFunc::convertToPoint(x_now, y_now), 1));
			}
		}

	}
	);

	menu_5 = Sprite::create();
	menu_51->setTag(5);






	/*6号*/
	auto menu_61 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Bottle01.png"),
		Sprite::createWithSpriteFrameName("Bottle01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(100))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_FireBottle(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);
	menu_6 = Sprite::create();
	menu_61->setTag(6);










	/*7号*/
	auto menu_71 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("BStar01.png"),
		Sprite::createWithSpriteFrameName("BStar01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(180))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_BlueStar(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);
	menu_7 = Sprite::create();
	menu_71->setTag(7);





	/*8号*/
	auto menu_81 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Sun01.png"),
		Sprite::createWithSpriteFrameName("Sun01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(180))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Sun(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);
	menu_8 = Sprite::create();
	menu_81->setTag(8);




	/*9号*/
	auto menu_91 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Rocket01.png"),
		Sprite::createWithSpriteFrameName("Rocket01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(180))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Rocket(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);
	menu_9 = Sprite::create();
	menu_91->setTag(9);




	/*10号*/
	auto menu_101 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Pin01.png"),
		Sprite::createWithSpriteFrameName("Pin01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(180))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Pin(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);
	menu_10 = Sprite::create();
	menu_101->setTag(10);






	/*11号*/
	auto menu_111 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Arrow01.png"),
		Sprite::createWithSpriteFrameName("Arrow01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(220))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Arrow(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);

	menu11 = Sprite::create();
	menu_111->setTag(11);








	/*12号*/
	auto menu_121 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Snow01.png"),
		Sprite::createWithSpriteFrameName("Snow01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(220))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Snow(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);

	menu12 = Sprite::create();
	menu_121->setTag(12);













	/*13号*/
	auto menu_131 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Plane01.png"),
		Sprite::createWithSpriteFrameName("Plane01.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(220))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Plane(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);

	menu13 = Sprite::create();
	menu_131->setTag(13);










	/*14号*/
	auto menu_141 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Fish01.png"),
		Sprite::createWithSpriteFrameName("Fish00.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(180))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Fish(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);

	menu14 = Sprite::create();
	menu_141->setTag(14);





	/*15号*/
	auto menu_151 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Cuttle01.png"),
		Sprite::createWithSpriteFrameName("Cuttle00.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(220))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Cuttle(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);

	menu15 = Sprite::create();
	menu_151->setTag(15);



	/*16号*/
	auto menu_161 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Anchor01.png"),
		Sprite::createWithSpriteFrameName("Anchor00.png"), [=](Ref*)
	{

		/*清除*/
		array[x_now][y_now]->setOpacity(0);
		array[x_now][y_now];;

		setBuyVisable(false);
		if (scene->view_up_menu->buySomething(260))
		{

			if (data->isUseAble(x_now, y_now))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerBulid.mp3");
				data->push_back(x_now, y_now);
				scene->tower_queue.push_back(
					new Tower_Anchor(scene, PublicFunc::convertToPoint(x_now, y_now), 1));

			}
		}

	}
	);

	menu16= Sprite::create();
	menu_161->setTag(16);



	menu_buy = Menu::create(menu_11, menu_21,menu_31,menu_41,menu_51,menu_61,menu_71,
		menu_81, menu_91,menu_101,menu_111,menu_121,menu_131,menu_141,menu_151,menu_161,nullptr);
	scene->addChild(menu_buy, 5);
	menu_buy->setPosition(0, 0);

	for (int i = 1; i <= 16; i++)
	{
		menu_buy->getChildByTag(i)->
			setPosition(PublicFunc::convertToPoint(-2,-2));
	}

	scene->addChild(menu_1, 5);
	scene->addChild(menu_2, 5);
	scene->addChild(menu_3, 5);
	scene->addChild(menu_4, 5);
	scene->addChild(menu_5, 5);
	scene->addChild(menu_6, 5);
	scene->addChild(menu_7, 5);
	scene->addChild(menu_8, 5);
	scene->addChild(menu_9, 5);
	scene->addChild(menu_10,5);
	scene->addChild(menu11,5);
	scene->addChild(menu12, 5);
	scene->addChild(menu13, 5);
	scene->addChild(menu14, 5);
	scene->addChild(menu15, 5);
	scene->addChild(menu16, 5);




	menu_1;;
	menu_2;;
	menu_3;;
	menu_4;;
	menu_5;;
	menu_6;;
	menu_7;;
	menu_8;;
	menu_9;;
	menu_10;;
	menu11;;
	menu12;;
	menu13;;
	menu14;;
	menu15;;
	menu16;;







	menu_11;;
	menu_21;;
	menu_31;;
	menu_41;;
	menu_51;;
	menu_61;;
	menu_71;;
	menu_81;;
	menu_91;;
	menu_101;;
	menu_111;;
	menu_121;;
	menu_131;;
	menu_141;;
	menu_151;;
	menu_161;;




	/* end*/
	updateState();
	setBuyVisable(false);

}


void View_Click_gloal::setBuyVisable(bool v)
{

	if (v)
	{

		menu_buy->setVisible(true);


		/*购买菜单位置校准*/
		float x_index=-0.5*(tower_able.size()-1);
		x_index+=x_now;

		if ((x_now+1) <= tower_able.size()/2)
		{
			x_index = x_now;
		}
		if ((12-x_now) <= tower_able.size() / 2)
		{
			x_index = x_now-tower_able.size()+1;
		}

		float y_index = y_now + 0.6;

		if (y_now >= 6)
		{
			y_index -= 1.2;
			y_index -= 0.5;

		}
		else
		{
			y_index += 0.5;
		}

		/*校准完毕*/

		

		/*只显示可购买的炮塔*/
		for (int i = 0; i < tower_able.size(); i++)
		{
			menu_buy->getChildByTag(tower_able[i])->
				setPosition(PublicFunc::convertToPoint(x_index+i, y_index));



			switch (tower_able[i])
			{
			case 1:
			{
					  menu_1->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_1->setVisible(true);
			}
				break;


			case 2:
			{
					  menu_2->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_2->setVisible(true);
			}
				break;


			case 3:
			{
					  menu_3->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_3->setVisible(true);
			}
				break;


			case 4:
			{
					  menu_4->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_4->setVisible(true);
			}
				break;



			case 5:
			{
					  menu_5->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_5->setVisible(true);
			}
				break;

			case 6:
			{
					  menu_6->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_6->setVisible(true);
			}
				break;

			case 7:
			{
					  menu_7->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_7->setVisible(true);
			}
				break;


			case 8:
			{
					  menu_8->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_8->setVisible(true);
			}
				break;



			case 9:
			{
					  menu_9->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_9->setVisible(true);
			}
				break;



			case 10:
			{
					  menu_10->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					  menu_10->setVisible(true);
			}
				break;


			case 11:
			{
					   menu11->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					   menu11->setVisible(true);
			}
				break;


			case 12:
			{
					   menu12->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					   menu12->setVisible(true);
			}
				break;





			case 13:
			{
					   menu13->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					   menu13->setVisible(true);
			}
				break;


			case 14:
			{
					   menu14->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					   menu14->setVisible(true);
			}
				break;



			case 15:
			{
					   menu15->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					   menu15->setVisible(true);
			}
				break;


			case 16:
			{
					   menu16->setPosition(PublicFunc::convertToPoint(x_index + i, y_index));
					   menu16->setVisible(true);
			}
				break;



			}
		}








	}
	else
	{
		menu_1->setVisible(false);
		menu_2->setVisible(false);
		menu_3->setVisible(false);
		menu_4->setVisible(false);
		menu_5->setVisible(false);
		menu_6->setVisible(false);
		menu_7->setVisible(false);
		menu_8->setVisible(false);
		menu_9->setVisible(false);
		menu_10->setVisible(false);
		menu11->setVisible(false);
		menu12->setVisible(false);
		menu13->setVisible(false);
		menu14->setVisible(false);
		menu15->setVisible(false);
		menu16->setVisible(false);


		menu_buy->setVisible(false);
	}


	updateState();

}



void View_Click_gloal::updateState()
{

	if (scene->view_up_menu->isEnough(100))
	{
		strcpy(str, "Bottle01.png");
	}
	else
	{
		strcpy(str, "Bottle00.png");
	}

	menu_1->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));




	if (scene->view_up_menu->isEnough(120))
	{
		strcpy(str, "Shit01.png");
	}
	else
	{
		strcpy(str, "Shit00.png");
	}

	menu_2->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));


	if (scene->view_up_menu->isEnough(160))
	{
		strcpy(str, "Star01.png");
	}
	else
	{
		strcpy(str, "Star00.png");
	}

	menu_3->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));

	if (scene->view_up_menu->isEnough(160))
	{
		strcpy(str, "Ball01.png");
	}
	else
	{
		strcpy(str, "Ball00.png");
	}

	menu_4->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));



	if (scene->view_up_menu->isEnough(160))
	{
		strcpy(str, "Fan01.png");
	}
	else
	{
		strcpy(str, "Fan00.png");
	}

	menu_5->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));





	if (scene->view_up_menu->isEnough(160))
	{
		strcpy(str, "FBottle01.png");
	}
	else
	{
		strcpy(str, "FBottle00.png");
	}

	menu_6->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));





	if (scene->view_up_menu->isEnough(180))
	{
		strcpy(str, "BStar01.png");
	}
	else
	{
		strcpy(str, "BStar00.png");
	}

	menu_7->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));




	if (scene->view_up_menu->isEnough(180))
	{
		strcpy(str, "Sun01.png");
	}
	else
	{
		strcpy(str, "Sun00.png");
	}

	menu_8->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));





	if (scene->view_up_menu->isEnough(220))
	{
		strcpy(str, "Rocket01.png");
	}
	else
	{
		strcpy(str, "Rocket00.png");
	}

	menu_9->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));




	if (scene->view_up_menu->isEnough(160))
	{
		strcpy(str, "Pin01.png");
	}
	else
	{
		strcpy(str, "Pin00.png");
	}

	menu_10->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));


	if (scene->view_up_menu->isEnough(220))
	{
		strcpy(str, "Arrow01.png");
	}
	else
	{
		strcpy(str, "Arrow00.png");
	}

	menu11->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));



	if (scene->view_up_menu->isEnough(160))
	{
		strcpy(str, "Snow01.png");
	}
	else
	{
		strcpy(str, "Snow00.png");
	}

	menu12->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));


	if (scene->view_up_menu->isEnough(220))
	{
		strcpy(str, "Plane01.png");
	}
	else
	{
		strcpy(str, "Plane00.png");
	}

	menu13->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));




	if (scene->view_up_menu->isEnough(180))
	{
		strcpy(str, "Fish01.png");
	}
	else
	{
		strcpy(str, "Fish00.png");
	}

	menu14->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));


	if (scene->view_up_menu->isEnough(220))
	{
		strcpy(str, "Cuttle01.png");
	}
	else
	{
		strcpy(str, "Cuttle00.png");
	}

	menu15->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));



	if (scene->view_up_menu->isEnough(260))
	{
		strcpy(str, "Anchor01.png");
	}
	else
	{
		strcpy(str, "Anchor00.png");
	}

	menu16->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));



}







bool View_Click_gloal::setAllVisFalse()
{
	bool ss = false;

	/*清除*/
	for (int x1 = 0; x1 < 12; x1++)
	{
		for (int y1 = 0; y1 < 7; y1++)
		{
			if (array[x1][y1] == 0)continue;


			if (array[x1][y1]->getOpacity() == 100)
			{
				ss = true;
			}
			array[x1][y1]->setOpacity(0);
		}
	}
	setBuyVisable(false);

	return ss;


}

