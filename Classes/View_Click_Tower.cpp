#include "View_Click_Tower.h"

#include "Tower_UI.h"
#include "PublicFunc.h"
#include "Scene_UI.h"
void View_Click_Tower::Destory()
{

	Scene_UI*scene = (Scene_UI*)base->getParent();

	//menu->removeAllChildrenWithCleanup(true);



	scene->removeChild(base);
	scene->removeChild(menu);
	scene->removeChild(select);

	scene->removeChild(upGrade);

	delete this;


}



void View_Click_Tower::updateState()
{
	if (!cos)return;


	Scene_UI*scene = (Scene_UI*)menu->getParent();



	if (scene->view_up_menu->isEnough(cos))
	{
		sprintf(str, "upgrade_%d.png", cos);
	}
	else
	{
		sprintf(str, "upgrade_-%d.png", cos);
	}

	upGrade->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));




}


View_Click_Tower::View_Click_Tower(int type, void*tower1)
{
	Tower_UI*tower = (Tower_UI*)tower1;
	Node*scene = tower->sprite->getParent();
	Vec2 pos = tower->sprite->getPosition();
	auto x = (Scene_UI*)scene;

	{
		Scene_UI*scen = (Scene_UI*)scene;
		for (int i = 0; i < scen->tower_queue.size(); i++)
		{
			scen->tower_queue[i]->setClick(false);
		}


	}


	switch (type)
	{

	case 1:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 80;
						cos = 180;
						base = Sprite::createWithSpriteFrameName("range_300.png");
			  }
				  break;
			  case 2:
			  {
						sell = 224;
						cos = 260;

						base = Sprite::createWithSpriteFrameName("range_340.png");
			  }
				  break;
			  case 3:
			  {
						sell = 432;
						cos = 0;

						base = Sprite::createWithSpriteFrameName("range_452.png");
			  }
				  break;
			  }
	}
		break;


	case 2:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 96;
						cos = 220;
						base = Sprite::createWithSpriteFrameName("range_200.png");
			  }
				  break;
			  case 2:
			  {
						sell = 272;
						cos = 260;

						base = Sprite::createWithSpriteFrameName("range_240.png");
			  }
				  break;
			  case 3:
			  {
						sell = 480;
						cos = 0;

						base = Sprite::createWithSpriteFrameName("range_300.png");
			  }
				  break;

			  default:
				  break;
			  }
	}
		break;


	case 3:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 128;
						cos = 220;
						base = Sprite::createWithSpriteFrameName("range_300.png");
			  }
				  break;
			  case 2:
			  {
						sell = 304;
						cos = 260;

						base = Sprite::createWithSpriteFrameName("range_340.png");
			  }
				  break;
			  case 3:
			  {
						sell = 512;
						cos = 0;

						base = Sprite::createWithSpriteFrameName("range_452.png");
			  }
				  break;

			  default:
				  break;
			  }
	}
		break;


	case 4:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 128;
						cos = 320;
						base = Sprite::createWithSpriteFrameName("range_300.png");
						base->setScale(340.0 / 300);
			  }
				  break;
			  case 2:
			  {
						sell = 384;
						cos = 480;

						base = Sprite::createWithSpriteFrameName("range_340.png");
						base->setScale(424.0 / 340);

			  }
				  break;
			  case 3:
			  {
						sell = 768;
						cos = 0;

						base = Sprite::createWithSpriteFrameName("range_452.png");
						base->setScale(480.0 / 452);

			  }
				  break;


			  }
	}
		break;

	case 5:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 128;
						cos = 220;
						base = Sprite::createWithSpriteFrameName("range_300.png");
						base->setScale(340.0 / 300);
			  }
				  break;
			  case 2:
			  {
						sell = 304;
						cos = 260;
						base = Sprite::createWithSpriteFrameName("range_340.png");
						base->setScale(424.0 / 340);

			  }
				  break;
			  case 3:
			  {
						sell = 512;
						cos = 0;
						base = Sprite::createWithSpriteFrameName("range_452.png");
						base->setScale(480.0 / 452);

			  }
				  break;


			  }
	}
		break;

	case 6:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 128;
						cos = 260;
						base = Sprite::createWithSpriteFrameName("range_300.png");
			  }
				  break;
			  case 2:
			  {
						sell = 336;
						cos = 320;

						base = Sprite::createWithSpriteFrameName("range_340.png");
			  }
				  break;
			  case 3:
			  {
						sell = 592;
						cos = 0;

						base = Sprite::createWithSpriteFrameName("range_452.png");
			  }
				  break;

			  default:
				  break;
			  }
	}
		break;

	case 7:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 144;
						cos = 260;
						base = Sprite::createWithSpriteFrameName("range_240.png");
			  }
				  break;
			  case 2:
			  {
						sell = 352;
						cos = 320;
						base = Sprite::createWithSpriteFrameName("range_300.png");
			  }
				  break;
			  case 3:
			  {
						sell = 608;
						cos = 0;
						base = Sprite::createWithSpriteFrameName("range_340.png");
			  }
				  break;

			  default:
				  break;
			  }
	}
		break;

	case 8:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 144;
						cos = 260;
						base = Sprite::createWithSpriteFrameName("range_300.png");
			  }
				  break;
			  case 2:
			  {
						sell = 352;
						cos = 320;

						base = Sprite::createWithSpriteFrameName("range_340.png");
			  }
				  break;
			  case 3:
			  {
						sell = 608;
						cos = 0;
						base = Sprite::createWithSpriteFrameName("range_340.png");

			  }
				  break;
			  }
	}
		break;

	case 9:
	{
			  switch (tower->level)
			  {
			  case 1:
			  {
						sell = 176;
						cos = 260;
						base = Sprite::createWithSpriteFrameName("range_452.png");
						base->setScale(420.0 / 452);
			  }
				  break;
			  case 2:
			  {
						sell = 384;
						cos = 380;
						base = Sprite::createWithSpriteFrameName("range_452.png");
						base->setScale(476.0 / 340);

			  }
				  break;
			  case 3:
			  {
						sell = 688;
						cos = 0;
						base = Sprite::createWithSpriteFrameName("range_452.png");
						base->setScale(640.0 / 452);

			  }
				  break;


			  }
	}
		break;

	case 10:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 128;
						 cos = 260;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(300.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 336;
						 cos = 320;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(350.0 / 340);

			   }
				   break;
			   case 3:
			   {
						 sell = 592;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(400.0 / 452);

			   }
				   break;


			   }
	}
		break;

	case 11:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 176;
						 cos = 260;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(340.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 384;
						 cos = 380;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(425.0 / 340);

			   }
				   break;
			   case 3:
			   {
						 sell = 688;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(480.0 / 452);

			   }
				   break;


			   }
	}
		break;

	case 12:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 128;
						 cos = 220;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(300.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 304;
						 cos = 320;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(340.0 / 340);

			   }
				   break;
			   case 3:
			   {
						 sell = 560;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(380.0 / 452);

			   }
				   break;


			   }
	}
		break;

	case 13:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 176;
						 cos = 320;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(420.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 432;
						 cos = 380;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(476.0 / 340);

			   }
				   break;
			   case 3:
			   {
						 sell = 736;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(640.0 / 452);

			   }
				   break;


			   }
	}break;

	case 14:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 144;
						 cos = 260;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(300.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 352;
						 cos = 320;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(350.0 / 340);

			   }
				   break;
			   case 3:
			   {
						 sell = 608;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(400.0 / 452);

			   }
				   break;



			   }
			
			   









	}break;

	case 15:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 176;
						 cos = 260;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(300.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 384;
						 cos = 320;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(360.0 / 452);

			   }
				   break;
			   case 3:
			   {
						 sell = 640;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(420.0 / 452);

			   }
				   break;



			   }

	}break;

	case 16:
	{
			   switch (tower->level)
			   {
			   case 1:
			   {
						 sell = 208;
						 cos = 320;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(340.0 / 452);
			   }
				   break;
			   case 2:
			   {
						 sell = 464;
						 cos = 380;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(420.0 / 452);

			   }
				   break;
			   case 3:
			   {
						 sell = 768;
						 cos = 0;
						 base = Sprite::createWithSpriteFrameName("range_452.png");
						 base->setScale(480.0 / 452);

			   }
				   break;



			   }

	}
		break;


	}


	base->setPosition(pos);
	scene->addChild(base, 3);

	select = Sprite::createWithSpriteFrameName("select_00.png");
	select->setPosition(pos);

	scene->addChild(select, 3);

	

	auto ani = Animation::create();
	//	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_00.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_04.png"));


	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

	select->runAction(Animate::create(ani));


	sprintf(str, "sell_%d.png", sell);
	menu_sell = MenuItemSprite::create(Sprite::createWithSpriteFrameName(str), Sprite::createWithSpriteFrameName(str),
		[=](Ref*)
	{
		menu_sell->setEnabled(false);
		x->view_up_menu->addMoney(sell);
		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerSell.mp3");
		tower->Destory();


	}
	);



	if (tower->level <= 2)
	{
		if (x->view_up_menu->isEnough(cos))
		{
			sprintf(str, "upgrade_%d.png", cos);
		}
		else
		{
			sprintf(str, "upgrade_-%d.png", cos);
		}
	}

	else
	{
		sprintf(str, "upgrade_0_CN.png");
	}

	menu_upGrade = MenuItemSprite::create(Sprite::createWithSpriteFrameName(str), Sprite::createWithSpriteFrameName(str),
		[=](Ref*)
	{

		if (tower->level <= 2)
		{

			auto x = (Scene_UI*)scene;
			if (x->view_up_menu->buySomething(cos))
			{
				SimpleAudioEngine::getInstance()->playEffect("Music/Tower/TowerUpdata.mp3");
				tower->setLevel(++tower->level);
				Destory();
			}
		}

	}
	);


	menu_upGrade->setPosition(Vec2(pos.x, pos.y + 80));
	menu_sell->setPosition(Vec2(pos.x, pos.y - 80));


	menu = Menu::create(menu_sell, menu_upGrade, nullptr);
	scene->addChild(menu, 3);
	menu->setPosition(0, 0);

	upGrade = Sprite::createWithSpriteFrameName(str);

	scene->addChild(upGrade, 3);

	upGrade->setPosition(menu_upGrade->getPosition());




	menu_sell;;
	upGrade;;
	menu_upGrade;;

	select;;


	int xx = PublicFunc::convertToX(pos);
	int yy = PublicFunc::convertToY(pos);



	if ((xx > 0) && (xx <= 10) && yy <= 0)
	{
		menu_sell->setPositionX(pos.x + 80);
		menu_sell->setPositionY(pos.y);
	}

	if ((xx > 0) && (xx <= 10) && yy >= 6)
	{
		menu_upGrade->setPositionX(pos.x + 80);
		menu_upGrade->setPositionY(pos.y);
		upGrade->setPosition(menu_upGrade->getPosition());

	}



	if ((xx <= 0) && (yy <= 0))
	{
		menu_upGrade->setPosition(Vec2(pos.x, pos.y + 80));
		menu_sell->setPositionX(pos.x + 80);
		menu_sell->setPositionY(pos.y);
		upGrade->setPosition(menu_upGrade->getPosition());

		return;
	}


	if ((xx >= 11) && (yy <= 0))
	{
		menu_upGrade->setPosition(Vec2(pos.x, pos.y + 80));
		menu_sell->setPositionX(pos.x - 80);
		menu_sell->setPositionY(pos.y);
		upGrade->setPosition(menu_upGrade->getPosition());

		return;
	}


	if ((xx >= 11) && (yy >= 6))
	{
		menu_sell->setPosition(Vec2(pos.x, pos.y - 80));
		menu_upGrade->setPositionX(pos.x - 80);
		menu_upGrade->setPositionY(pos.y);
		upGrade->setPosition(menu_upGrade->getPosition());

		return;


	}


	if ((xx <= 0) && (yy >= 6))
	{
		menu_upGrade->setPositionX(pos.x + 80);
		menu_upGrade->setPositionY(pos.y);
		menu_sell->setPosition(Vec2(pos.x, pos.y - 80));
		upGrade->setPosition(menu_upGrade->getPosition());

	}






}

