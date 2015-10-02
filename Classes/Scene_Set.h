#ifndef Scene_Set__
#define Scene_Set__

#include "object.h"



class Scene_Set :public Layer
{
public:

	bool init();
	static Scene* createScene();


	MenuItemSprite*menu_eff_on, *menu_mus_on;
	MenuItemSprite*menu_eff_off, *menu_mus_off;

	void setEffectEnable(bool b);


	void setMusicEnable(bool b);

public:
	void reset();
	void unclockAll();
	Layer*layer_reset;





	Layer*layer_unlockall;

	CREATE_FUNC(Scene_Set);

};





#endif 
