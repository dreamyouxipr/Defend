#ifndef Scene_Welcome__
#define Scene_Welcome__

#include "object.h"



class logo : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(logo);
};


class Scene_Welcome :public Layer
{
public:

	bool init();
	static Scene* createScene();



	CREATE_FUNC(Scene_Welcome);

};





#endif 
