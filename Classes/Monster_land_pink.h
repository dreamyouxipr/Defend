

#ifndef Monster_land_pink__

#define Monster_land_pink__


#include "Monster_UI.h"

class Monster_land_pink :public Monster_UI 
{

private:
	virtual void runMoveAction();

public:
	Monster_land_pink(int t_hp,Node*scene, Vec2 pos,queue<Vec2> que);

	virtual void initBase()
	{
		damage = 1;

		moveSpeed = 60;//200--50
		money = 14;
		/*land 60   fly 30*/



		moveDir = 8;
		moveSpeed_readOnly = moveSpeed;
		SimpleAudioEngine::getInstance()->playEffect("Music/MC.mp3");
	}

	virtual void playEffect();
};





#endif // 


