#include "Bonus_4_3.h"

#include "Scene_UI.h"




Bonus_4_3::Bonus_4_3(Node*scene,Vec2 pos)
{
	
	string str = "cloud03.png";


	initBase();
	is_Bonus = true;


	Scene_UI*sce = (Scene_UI*)scene;
	menu = MenuItemSprite::create(Sprite::createWithSpriteFrameName(str), Sprite::createWithSpriteFrameName(str), [=](Ref*)
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
	menu->setPosition(pos);
	menu;;




	men = Menu::create(menu, nullptr);
	men->setPosition(0, 0);
	scene->addChild(men);


	sprite = Sprite::createWithSpriteFrameName(str);

	scene->addChild(sprite);
	sprite->setPosition(pos);
	sprite;;



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
	sprite_selected->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height );
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
	hp_sprite_1->setScaleY(0.7);




	sprite_effect_slow = Sprite::createWithSpriteFrameName("PShit-12.png");
	sprite->addChild(sprite_effect_slow);

	auto ani1 = Animation::create();
	ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-12.png"));
	ani1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-11.png"));

	ani1->setDelayPerUnit(0.1);
	ani1->setRestoreOriginalFrame(false);
	ani1->setLoops(-1);
	sprite_effect_slow->runAction(Animate::create(ani1));
	sprite_effect_slow->setPosition(sprite->getContentSize().width / 2, 20);


	sprite_effect_slow->setVisible(false);




	hp_sprite_1->setVisible(false);
	hp_sprite_2->setVisible(false);















	/*init ’º”√Œª÷√*/

	queue_takeplace_pos.push_back(Vec2(PublicFunc::convertToX(pos.x), PublicFunc::convertToY(pos.y)));



	for (int i = 0; i < queue_takeplace_pos.size(); i++)
	{
		sce->data->push_back(queue_takeplace_pos[i]);
	}



}




