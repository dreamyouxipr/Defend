#include "Monster_land_star.h"

#include "Scene_UI.h"

void Monster_land_star::runMoveAction()
{
	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("land_star01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("land_star02.png"));
	ani->setDelayPerUnit(3.0 / 30.0);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

	auto an = Animate::create(ani);
	sprite->runAction(an);

}




void Monster_land_star::playEffect()
{
	auto x = (Scene_UI*)sprite->getParent();

	switch (x->key_to_[0])
	{
	case '1':
	{
				switch (rand() % 2)
				{
				case 0:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land121.mp3"); break;
				case 1:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land122.mp3"); break;
		
				}
	}break;

	case '2':
	{

				switch (rand() % 2)
				{
				case 0:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land221.mp3"); break;
				case 1:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land222.mp3"); break;

				}

	}break;

	case '3':
	{
				switch (rand() % 3)
				{
				case 0:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land321.mp3"); break;
				case 1:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land322.mp3"); break;
				case 2:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land323.mp3"); break;
				}
	}break;

	case '4':
	{
				switch (rand() % 3)
				{
				case 0:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land621.mp3"); break;
				case 1:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land622.mp3"); break;
				case 2:
					SimpleAudioEngine::getInstance()->playEffect("Music/Monster/Land623.mp3"); break;
				}
	}break;



	}





}


Monster_land_star::Monster_land_star(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que)
{

	string str = "land_star01.png";


	initBase();
	hp = t_hp;
	hp_now = hp;

	queue_way = que;
	sprite = Sprite::createWithSpriteFrameName(str);
	scene->addChild(sprite);
	sprite->setPosition(pos);

	sprite;;


	Scene_UI*sce = (Scene_UI*)scene;

	menu = MenuItemSprite::create(Sprite::create("1.png"), Sprite::create("1.png"), [=](Ref*)
	{
		is_selected = !is_selected;

		if (is_selected)
		{
			for (int i = 0; i < sce->monster_queue.size(); i++)
			{
				;
				{
					((Bonus_UI*)sce->monster_queue[i])->sprite_selected->setVisible(false);
					((Bonus_UI*)sce->monster_queue[i])->is_selected = false;

				}

			}

			is_selected = true;
			sprite_selected->setVisible(true);
			return;
		}
		sprite_selected->setVisible(false);

	});
	menu->setPosition(sprite->getContentSize().width/2,sprite->getContentSize().height/2);


	men = Menu::create(menu, nullptr);
	men->setPosition(0, 0);
	sprite->addChild(men);


	menu->setScale(sprite->getContentSize().height / 2.0 / 40.0);



	sprite_selected = Sprite::createWithSpriteFrameName("point01.png");

	{
		auto ani = Animation::create();
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("point01.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("point02.png"));
		ani->setDelayPerUnit(3.0 / 30.0);
		ani->setRestoreOriginalFrame(false);
		ani->setLoops(-1);

		sprite_selected->runAction(Animate::create(ani));
	}
	sprite_selected->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height);
	sprite->addChild(sprite_selected);
	sprite_selected->setVisible(false);








	hp_sprite_2 = Sprite::createWithSpriteFrameName("MonsterHP02.png");
	hp_sprite_2->setPosition(Vec2(sprite->getContentSize().width / 4, sprite->getContentSize().height - 5));
	sprite->addChild(hp_sprite_2);



	hp_sprite_1 = Sprite::createWithSpriteFrameName("MonsterHP01.png");
	hp_sprite_1->setPosition(Vec2(sprite->getContentSize().width / 4, sprite->getContentSize().height - 5));
	sprite->addChild(hp_sprite_1);



	hp_sprite_1->setAnchorPoint(Vec2(0, 0.5));


	hp_sprite_2->setAnchorPoint(Vec2(0, 0.5));


	hp_sprite_1->setVisible(false);
	hp_sprite_2->setVisible(false);

	hp_sprite_1->setScaleY(0.7);

	resetWay();

	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("mcm01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("mcm02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("mcm02.png"));


	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);
	sprite->runAction(Animate::create(ani));


/*
	hp_sprite_1;;
	hp_sprite_2;;
*/

	



}




