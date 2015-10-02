#ifndef Scene_Selector_2_
#define Scene_Selector_2_

#include "object.h"


class Scene_Selector_2 :public Layer
{
	public:
	Sprite*sprite_tower_able;

	Sprite *sprite;
	char str[100];

	void callback_play();


	MenuItemSprite*menu_lef;
	MenuItemSprite*menu_rig;

	int index_now;
	Sprite*sprite_lock;
	Sprite*sprite_lock_1;

public:

	bool init();
	static Scene* createScene();

	void setIndex(int index);/*1~12*/

	void sync();
	Sprite*sprite_lev;/*关卡成就*/
	Sprite*sprite_allclear;/*全部清除 Bonus*/




	CREATE_FUNC(Scene_Selector_2);

};





#endif 
