
#ifndef Monster_UI__

#define Monster_UI__


#include "MonsterBase.h"







class Monster_UI :public MonsterBase
{
public:

	bool is_selected;/*是否被选中*/
	bool is_Bonus;/*是否是奖励*/




	bool is_effect_slow;
	Sprite*sprite_effect_slow;
	int effect_slow_lev;
	virtual	void set_effect_slow(int lev, int tag = 1);/*减速效果*/
	virtual void set_effect_slow_Blue(int lev);/* 蓝星减速效果*/



	int effect_last_damage_times;
	int effect_last_damage_lev;
	Sprite*sprite_last_damage;
	void set_effect_last_damage(int lev);/*pin 持续伤害*/




	int effect_pause_lev_1;
	Sprite*sprite_effect_pause_1;
	int effect_pause_times_1;
	virtual	void set_effect_pause_fish(int lev);/*fish 暂停*/





	int effect_pause_lev;
	Sprite*sprite_effect_pause;
	int effect_pause_times;
	virtual void set_effect_pause(int lev);/*暂停*/





	Monster_UI() :count(0), is_effect_slow(false), sprite_effect_slow(0), effect_slow_lev(0)
	{
		isDone = true;
		effect_last_damage_lev = 0;
		effect_pause_lev = 0;
		effect_pause_lev_1 = 0;
		is_Bonus = false;
		is_selected = false;

	}
	int count;
	bool isDone;

	virtual	void updateWay();

	void resetWay();

	Sprite*sprite;
	Sprite*hp_sprite_1;
	Sprite*hp_sprite_2;
	Sprite*bonus;

	queue<Vec2> queue_way;


	virtual void Destory(bool isKing = false);/*清除 接口*/
	virtual void Delete();
	virtual void runMoveAction() {};/*播放移动动画 接口*/



	virtual int beenAttacked(int damage);

	/*单体被攻击通用*//*被攻击接口*/



	~Monster_UI()
	{
		while (!queue_way.empty())
		{
			queue_way.pop();

		}
		//	log(" ~~~Monster_UI");

	}


	long long zzz = 0;






	void runRocketBoomAction();
	void runFanBoomAction();
	void runBottleBoomAction();
	void runShitBoomAction();
	void runStarBoomAction();
	void runBallBoomAction();
	void runFireBottleBoomAction();
	void runBlueStarBoomAction();
	void runArrowBoomAction();
	void runPlaneBoomAction();
	void runFishBoomAction();
	void runFishBoomAction_2();
	void runCuttleBoomAction();
	void runAnchorBoomAction();
	void runAnchorBoomAction_2();

	virtual void playEffect() = 0;

	Menu*men;
	Sprite*sprite_selected;
	MenuItemSprite*menu;

};




#endif // 




