#ifndef Scene_Selector_4_
#define Scene_Selector_4_

#include "object.h"


class Scene_Selector_4 :public Layer
{
	public:
	Sprite*sprite_tower_able;

	Sprite *sprite;
	char str[100];

	void callback_play();


	MenuItemSprite*menu_lef;
	MenuItemSprite*menu_rig;
	Sprite*sprite_lock;
	Sprite*sprite_lock_1;

	int index_now;

public:

	bool init();
	static Scene* createScene();

	void setIndex(int index);/*1~12*/


	void sync();
	Sprite*sprite_lev;/*关卡成就*/
	Sprite*sprite_allclear;/*全部清除 Bonus*/



	CREATE_FUNC(Scene_Selector_4);

};





#endif 
