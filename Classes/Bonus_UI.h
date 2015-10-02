
#ifndef Bonus_UI__

#define Bonus_UI__


#include "Monster_UI.h"




/*Bonus 基础坐标位于左下角*/
class Bonus_UI :public Monster_UI
{
public:

	Bonus_UI(){};

	vector<Vec2> queue_takeplace_pos;/*占用的坐标*/


	virtual void Destory(bool isKing = false);/*清除 接口*/

	virtual void updateWay(){ 111; }

	virtual	void set_effect_slow(int lev, int tag = 1){};/*减速效果*/
	virtual void set_effect_slow_Blue(int lev){};/* 蓝星减速效果*/
	virtual	void set_effect_pause_fish(int lev){};/*fish 暂停*/
	virtual void set_effect_pause(int lev){};/*暂停*/

	virtual void playEffect(){}

};




#endif // 


