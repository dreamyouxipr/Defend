 
#include "Scene_Help.h"

bool Scene_Help::init()
{

	Layer::init();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_Help/help_1-hd.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_Help/help_2-hd.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Scene_Help/help_3-hd.plist");

	auto bg = Sprite::createWithSpriteFrameName("help_bg.png");
	bg->setPosition(960 / 2, 640 / 2);
	this->addChild(bg);


	 
	auto menu_back=MenuItemSprite::create(Sprite::createWithSpriteFrameName("help_home_normal.png"),
		Sprite::createWithSpriteFrameName("help_home_pressed.png"),
		[=](Ref*)
	{
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_Help/help_1-hd.plist");
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_Help/help_2-hd.plist");
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Scene_Help/help_3-hd.plist");

		layer_1->removeAllChildrenWithCleanup(true);
		layer_2->removeAllChildrenWithCleanup(true);
		layer_3->removeAllChildrenWithCleanup(true);

		Audio::play_Button();


		this->removeAllChildrenWithCleanup(true);


		Director::getInstance()->popScene();
	
	});
	menu_back->setPosition(960 / 2 - 400, 640 - 50);



	layer_1 = Layer::create();
	layer_2 = Layer::create();
	layer_3 = Layer::create();


	this->addChild(layer_1);
	this->addChild(layer_2);
	this->addChild(layer_3);



	auto dic = Dictionary::createWithContentsOfFile("string_CN.plist");

	 menu_1 = MenuItemLabel::create(Label::create( ((String*)dic->objectForKey("help"))->getCString() ,FONT,40),
		[=](Ref*)
	{
		
		 setLayerVisible(1);

		 Audio::play_Button();

	});
	menu_1->setPosition(960 / 2-180 , 640 - 50);


	 menu_2 = MenuItemLabel::create(Label::create(((String*)dic->objectForKey("monster"))->getCString(), FONT, 40),
		[=](Ref*)
	{

		 setLayerVisible(2);
		 Audio::play_Button();


	});
	menu_2->setPosition(960 / 2 , 640 - 50);


	 menu_3 = MenuItemLabel::create(Label::create(((String*)dic->objectForKey("tower"))->getCString(), FONT, 40),
		[=](Ref*)
	{

		 setLayerVisible(3);
		 Audio::play_Button();


	});
	menu_3->setPosition(960 / 2 + 180, 640 - 50);


	auto menu = Menu::create(menu_back,menu_1,menu_2,menu_3, nullptr);
	menu->setPosition(0, 0);
	this->addChild(menu);



	sprite_up = Sprite::create();
	this->addChild(sprite_up);


	init_1();
	init_2();
	init_3();





	setLayerVisible(1);
	return true;
}




Scene* Scene_Help::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_Help::create();
	scene->addChild(layer);
	return scene;
}



void  Scene_Help:: setIndex_1()
{

	switch (index_1)
	{
	case 1:
	{
			  sprite_1_1->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_1.png"));
			  sprite_1_2->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_text_1_CN.png"));
			  label_1->setString("1/4");


	}break;

	case 2:
	{
			  sprite_1_1->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_2.png"));
			  sprite_1_2->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_text_2_CN.png"));
			  label_1->setString("2/4");


	}break;
	case 3:
	{
			  sprite_1_1->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_3.png"));
			  sprite_1_2->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_text_3_CN.png"));
			  label_1->setString("3/4");


	}break;
	case 4:
	{
			  sprite_1_1->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_4.png"));
			  sprite_1_2->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_text_4_CN.png"));
			  label_1->setString("4/4");


	}break;

	}
}
void  Scene_Help::init_1()
{
	index_1 = 1;

	auto	menu_lef = MenuItemSprite::create(Sprite::createWithSpriteFrameName("recommend_left_normal.png"),
		Sprite::createWithSpriteFrameName("recommend_left_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		if (index_1 > 1)
		{
			--index_1;
			setIndex_1();
		}



	}
	);
	menu_lef->setPosition(960 / 2 - 400, 640 / 2 - 200);




	auto menu_rig = MenuItemSprite::create(Sprite::createWithSpriteFrameName("recommend_right_normal.png"),
		Sprite::createWithSpriteFrameName("recommend_right_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		if (index_1 <= 3)
		{
			++index_1;
			setIndex_1();
		}

	}
	);
	menu_rig->setPosition(960 / 2 + 400, 640 / 2 - 200);


	menu_lef->setScale(2.5);
	menu_rig->setScale(2.5);



	sprite_1_1 = Sprite::createWithSpriteFrameName("tips_1.png");
	sprite_1_1->setPosition(960 / 2, 640 / 2 + 50);
	layer_1->addChild(sprite_1_1);


	sprite_1_2 = Sprite::createWithSpriteFrameName("tips_text_1_CN.png");
	sprite_1_2->setPosition(960 / 2, 640 / 2 - 200);
	layer_1->addChild(sprite_1_2);

	label_1 = Label::create("1/4", FONT, 35);
	layer_1->addChild(label_1);
	label_1->setPosition(960 / 2, 640 / 2 - 270);






	auto menu_11 = Menu::create(menu_lef, menu_rig, nullptr);
	layer_1->addChild(menu_11);
	menu_11->setPosition(0, 0);




	setIndex_1();




}
void  Scene_Help::init_2()
{
	auto sp = Sprite::createWithSpriteFrameName("help_monster.png");
	layer_2->addChild(sp);
	sp->setPosition(960 / 2, 640 / 2 - 60);


	auto sp1 = Sprite::createWithSpriteFrameName("help_monster_CN.png");
	layer_2->addChild(sp1);
	sp1->setPosition(960 / 2, 640 / 2 - 60);



}

void  Scene_Help::setIndex_3()
{
	int index_ = index_3;

	if (index_ == 16)
	{
		index_ = 17;
	}

	if (index_ == 15)
	{
		index_ = 16;
	}


	if (index_ <= 9)
	{
		sprintf(str, "tower_0%d.png", index_);
	}
	else
	{
		sprintf(str, "tower_%d.png", index_);
	}
	sprite_2_1->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));




	if (index_3 <= 9)
	{
		sprintf(str, "tower_0%d_CN.png", index_);
	}
	else
	{
		sprintf(str, "tower_%d_CN.png", index_);
	}
	sprite_2_2->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));

	sprintf(str, "%d/16", index_3);
	label_2->setString(str);


}
void Scene_Help::init_3()
{
	index_3 = 1;

	auto	menu_lef = MenuItemSprite::create(Sprite::createWithSpriteFrameName("recommend_left_normal.png"),
		Sprite::createWithSpriteFrameName("recommend_left_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		if (index_3 > 1)
		{
			--index_3;
			setIndex_3();
		}



	}
	);
	menu_lef->setPosition(960 / 2 - 400, 640 / 2);




	auto menu_rig = MenuItemSprite::create(Sprite::createWithSpriteFrameName("recommend_right_normal.png"),
		Sprite::createWithSpriteFrameName("recommend_right_pressed.png"),
		[=](Ref*)
	{
		Audio::play_Button();

		if (index_3 <= 15)
		{
			++index_3;
			setIndex_3();
		}

	}
	);
	menu_rig->setPosition(960 / 2 + 400, 640 / 2);


	menu_lef->setScale(2.5);
	menu_rig->setScale(2.5);



	sprite_2_1 = Sprite::createWithSpriteFrameName("tower_01.png");
	sprite_2_1->setPosition(960 / 2, 640 / 2);
	layer_3->addChild(sprite_2_1);


	sprite_2_2 = Sprite::createWithSpriteFrameName("tower_01_CN.png");
	sprite_2_2->setPosition(960 / 2, 640 / 2);
	layer_3->addChild(sprite_2_2);

	label_2 = Label::create("1/16", FONT, 35);
	layer_3->addChild(label_2);
	label_2->setPosition(960 / 2, 640 / 2 - 270);






	auto menu_11 = Menu::create(menu_lef, menu_rig, nullptr);
	layer_3->addChild(menu_11);
	menu_11->setPosition(0, 0);




	setIndex_3();





}

void  Scene_Help::setLayerVisible(int  index)
{
	layer_1->setVisible(false);
	layer_2->setVisible(false);
	layer_3->setVisible(false);

	switch (index)
	{
	case  1:
	{
			   layer_1->setVisible(true);
			   sprite_up->setPosition(960 / 2 - 180, 640 - 50);
			   sprite_up->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tips_selected_CN.png"));


	} break;


	case  2:
	{
			   layer_2->setVisible(true);
			   sprite_up->setPosition(960 / 2, 640 - 50);
			   sprite_up->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("monster_selected_CN.png"));

	} break;

	case  3:
	{
			   layer_3->setVisible(true);
			   sprite_up->setPosition(960 / 2 + 180, 640 - 50);
			   sprite_up->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tower_selected_CN.png"));

	} break;

	}




}

