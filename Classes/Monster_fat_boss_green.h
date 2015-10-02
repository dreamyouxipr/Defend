

#ifndef Monster_fat_boss_green__

#define Monster_fat_boss_green__


#include "Monster_UI.h"

class Monster_fat_boss_green :public Monster_UI
{

private:
	virtual void runMoveAction();

public:
	Monster_fat_boss_green(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que);

	virtual void initBase()
	{
		damage = 2;
		hp = 300;
		moveSpeed = 50;//200--50
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


