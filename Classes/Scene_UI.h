#ifndef Scene_UI__
#define Scene_UI__

#include "object.h"



#include "Monster_UI.h"
#include "Tower_UI.h"

#include "Monster_land_pink.h"
#include "Tower_Bottle.h"
#include "View_king.h"
#include "View_Click_gloal.h"
#include "View_Up_Menu.h"
#include "Bonus_UI.h"

#include "Wave_Manager.h"



class Scene_UI :public Layer
{
public:
	friend class Wave_Manager;


	void Destroy();

	string key_to_;/*关卡用于读取保存 关卡成就*/




	DatePos_Array*data;/*占位 数据容器*/

	vector<Monster_UI*>monster_queue;/*怪物*/
	vector<Tower_UI*>tower_queue;/*炮塔*/
	View_king *view_king;/* 萝卜*/
	View_Click_gloal*view_click_gloal;/*用户点击 安置炮塔*/
	View_Up_Menu*view_up_menu;/*上方菜单*/



	virtual void update(float delta);

	MenuItemSprite*bg;/*场景背景*/


	queue<Vec2> queue_way;/*路径*/



	bool init();
	int current_level;/*当前关数*/


	std::function<void(void)> callback_next;
	std::function<void(void)> callback_restart;

	Wave_Manager *wave_manager;


	virtual void removeRes()/*移除该场景资源*/
	{

	}
	void BonusAllclear();

private:
	void loadSceneWay();
	/*倒计时*/
	Menu*x;
	Sprite*sp_count;
	Sprite*sp_count_1;
	Sprite*sp_count_2;

	vector <Sprite*>queue_f;

	
protected:
	int base_money;/*本场景基础钱*/

	Sprite*sp_bonus_clear;

	virtual void initQueue_way() = 0;/* 初始化怪物路径*/
	virtual void initAbleTower() = 0;/*本场景允许的 炮塔ID*/
	virtual void initBonus() = 0;
	virtual void initScene(Node*p)
	{
		/*初始化背景图片 , 路径图片, 金钱*/
		//while (true);
	}

	virtual void initWave_manager();/*初始化 数据*/
};




















#endif 
