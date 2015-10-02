#ifndef Theme_Selector__
#define Theme_Selector__

#include "object.h"


class Theme_Selector :public Layer
{
private:

	Sprite *sprite;
	char str[100];

	void callback_play();


	MenuItemSprite*menu_lef;
	MenuItemSprite*menu_rig;

	int index_now;
	Label*label;

public:

	bool init();
	static Scene* createScene();

	void setIndex(int index);/*1~12*/




	CREATE_FUNC(Theme_Selector);

};





#endif 
