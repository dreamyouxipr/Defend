#include "View_king.h"


#include "PublicFunc.h"

#include "Scene_UI.h"

void View_king::Destory()
{
	//sprite->removeFromParentAndCleanup(true);
	//sprite_hp->removeFromParentAndCleanup(true);


	delete this;

} 


View_king::View_king(Node*scene, Vec2 pos)
{

	hp = 10;
	this->scene = scene;

	sprite = Sprite::create();
	scene->addChild(sprite, 2);
	sprite->setPosition(pos);


	sprite_hp = Sprite::create();
	scene->addChild(sprite_hp, 2);
	sprite_hp->setPosition(Vec2(pos.x + 50, pos.y));




	auto sp = MenuItemSprite::create(Sprite::createWithSpriteFrameName("hlb21.png"),
		Sprite::createWithSpriteFrameName("hlb21.png"), [=](Ref*)
	{
		runTouchAction();

	});

	sp->setPosition(pos);
	sp->setOpacity(0);

	menu = Menu::create(sp, nullptr);
	menu->setPosition(0, 0);
	scene->addChild(menu);










	updateState();


	/*auto ani = Animation::create();

	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_00.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("select_04.png"));


	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

	sprite->runAction(Animate::create(ani));
	*/


/*
	sprite;;
	sprite_hp;;*/
}

void View_king::updateState()
{
	char str[500];


	if (hp == 10)
	{
		sprintf(str, "BossHP10.png");
	}
	else
	{
		sprintf(str, "BossHP0%d.png", hp);
	}



	sprite_hp->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));

	

	if (hp == 7)
	{
		sprintf(str, "hlb8.png");
	}

	else if (hp == 5)
	{
		sprintf(str, "hlb6.png");
	}
	else
	{
		sprintf(str, "hlb%d.png", hp);
	}



	sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));


}




void  View_king:: beenAttack(int damage)
{
	hp -= damage;


	if (hp <= 0)
	{
		auto x = ((Scene_UI*)scene);
		x->view_up_menu->show_lose(x->wave_manager->current_wave_index,x->wave_manager->max_wave_index);

	//	Destory();
		
		return;

	};

	updateState();
	SimpleAudioEngine::getInstance()->playEffect("Music/King/Crash.mp3");
}




void  View_king:: runTouchAction()
{
	if (hp != 10)return;

	sprite->stopAllActions();
	sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb21.png"));


	switch (rand()%2)
	{
	case 0:SimpleAudioEngine::getInstance()->playEffect("Music/King/carrot2.mp3");
		break;
	case 1:SimpleAudioEngine::getInstance()->playEffect("Music/King/carrot3.mp3");
		break;

	}
	
	auto ani = Animation::create();

	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb10.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb11.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb12.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb13.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb14.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb15.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb16.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb17.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hlb18.png"));
	
	ani->setDelayPerUnit(0.03);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);

	sprite->runAction(Animate::create(ani));

}
