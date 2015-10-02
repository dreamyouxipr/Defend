

#ifndef View_Up_Menu__

#define View_Up_Menu__


#include "object.h"

class View_Up_Menu
{
public:
	Sprite*bg;
	void Destory();
	int money;/*max 9999999*/

	View_Up_Menu(Node*scene, int mon);

	void setMoney(int m);
	void incMoney(int m);

	void addMoney(int m);/*外部接口，添加money  怪物消灭，炮塔出售等*/
	bool buySomething(int need_m);/*外部接口*/
	bool isEnough(int cos);/*外部接口*/
	void sync_upgradeAble();

	void sync_wave_info(int current, int max)
	{
		sprintf(ss, "%d/%d", current + 1, max + 1);
		label_wave_info->setString(ss);

	}




	void show_win(int current, int max,int lev);

	void show_lose(int current, int max);


	void setPause(bool p);


private:
	void updateState();
	Label *label_money;
	char ss[100];
	Sprite*sprite_pause;
	Sprite*sprite_is_pause;
	Label*label_wave_info;
	Node*scene;

	bool isPause;
	Layer *layer_menu_win;
	Layer *layer_menu_lose;
	Layer*layer_menu;

	
	void show_menu();


};





#endif // !TowerBase


