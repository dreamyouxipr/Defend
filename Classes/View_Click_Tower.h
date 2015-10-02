

#ifndef Tower_UI____

#define Tower_UI____


#include "object.h"

class View_Click_Tower/*炮塔点击后视图*/
{
public:
	View_Click_Tower(int type, void*tower);

	void updateState();



	void Destory();

private:

	MenuItemSprite*menu_sell;
	Sprite*upGrade;
	MenuItemSprite*menu_upGrade;
	Sprite*base;
	Sprite*select;
	Menu*menu;

	char str[100];

	int cos;/*0，已经为最大等级*/
	int sell;
	/*升级花费 ，卖出价格*/


};





#endif // !TowerBase


