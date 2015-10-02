

#ifndef Monster_land_boss_star__

#define Monster_land_boss_star__


#include "Monster_UI.h"

class Monster_land_boss_star :public Monster_UI
{

private:
	virtual void runMoveAction();

public:
	Monster_land_boss_star(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que);

	virtual void initBase()
	{
		damage = 2;
		hp = 300;
		moveSpeed = 60;//200--50
		money = 14;



		hp_now = hp;
		moveDir = 8;
		moveSpeed_readOnly = moveSpeed;
		SimpleAudioEngine::getInstance()->playEffect("Music/MC.mp3");
	}

	virtual void playEffect()
	{
		SimpleAudioEngine::getInstance()->playEffect("Music/Monster/LittleBoss.mp3");
	}

};





#endif // 


