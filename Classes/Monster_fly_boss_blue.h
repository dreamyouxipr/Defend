

#ifndef Monster_fly_boss_blue__

#define Monster_fly_boss_blue__


#include "Monster_UI.h"

class Monster_fly_boss_blue :public Monster_UI
{

private:
	virtual void runMoveAction();

public:
	Monster_fly_boss_blue(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que);

	virtual void initBase()
	{
		damage = 2;
		hp = 300;
		moveSpeed = 30;//200--50
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


