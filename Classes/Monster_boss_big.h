

#ifndef Monster_boss_big__

#define Monster_boss_big__


#include "Monster_UI.h"

class Monster_boss_big :public Monster_UI 
{

private:
	virtual void runMoveAction();

public:
	Monster_boss_big(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que);

	virtual void initBase()
	{
		damage = 3;
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
		SimpleAudioEngine::getInstance()->playEffect("Music/Monster/BigBoss.mp3");
	}


};





#endif // 


