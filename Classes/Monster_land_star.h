

#ifndef Monster_land_star__

#define Monster_land_star__


#include "Monster_UI.h"

class Monster_land_star :public Monster_UI
{

private:
	virtual void runMoveAction();

public:
	Monster_land_star(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que);

	virtual void initBase()
	{
		damage = 1;
		hp = 300;
		moveSpeed = 55;//200--50
		money = 14;



		hp_now = hp;
		moveDir = 8;
		moveSpeed_readOnly = moveSpeed;
		SimpleAudioEngine::getInstance()->playEffect("Music/MC.mp3");
	}

	virtual void playEffect();

};





#endif // 


