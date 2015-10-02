#ifndef Scene_Help__
#define Scene_Help__

#include "object.h"



class Scene_Help :public Layer
{
public:

	bool init();
	static Scene* createScene();

private:
	Layer*layer_1, *layer_2, *layer_3;
	Sprite*sprite_up;
	MenuItemLabel*menu_1, *menu_2, *menu_3;

	Sprite*sprite_1_1;
	Sprite*sprite_1_2;

	Sprite*sprite_2_1;
	Sprite*sprite_2_2;


	int index_1;
	Label*label_1, *label_2;

	char str[100];

	int index_3;
	void setIndex_1();
	void init_1();
	void init_2();

	void setIndex_3();
	void init_3();

	void setLayerVisible(int  index);



public:

	CREATE_FUNC(Scene_Help);

};





#endif 
