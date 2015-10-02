

#ifndef View_Click_gloal__

#define View_Click_gloal__


#include "object.h"


class View_Click_gloal/*添加炮塔 视图*/
{
public:
	vector<int>tower_able;/*允许购买的炮塔id*/




	View_Click_gloal(Node*scene);

	void Destory();

	void updateState();/* 外部调用 更新购买能力*/
	bool setAllVisFalse();/*如果有已经可见true， 没有返回false  */


private:
	MenuItemSprite* array[12][7];

	void doClickAction();/*单击后 添加炮塔 */


	Menu*menu_buy;
	void setBuyVisable(bool v);/*购买菜单*/

	int x_now, y_now;/*当前index*/
	char str[100];


	Sprite*menu_1;/*1 号炮塔标志 bottle */
	Sprite*menu_2;/*2 号炮塔标志  shit */
	Sprite*menu_3;/*3 号炮塔  star  */
	Sprite*menu_4;/*4 号炮塔  ball */
	Sprite*menu_5;/*5 号炮塔  fan*/
	Sprite*menu_6; /* fire*/
	Sprite*menu_7;/*blue*/
	Sprite*menu_8;/*sun*/
	Sprite*menu_9;/*rock*/
	Sprite*menu_10;/* pin*/
	Sprite*menu11;/*arrow*/
	Sprite*menu12;/* snow*/
	Sprite*menu13;/*plane*/
	Sprite*menu14;/*fish*/
	Sprite*menu15;/*cuttle*/
	Sprite*menu16;/*anchor*/




};





#endif // !TowerBase


