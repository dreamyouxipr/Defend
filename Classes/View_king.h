

#ifndef View_king__

#define View_king__


#include "object.h"

class View_king
{
public:
	Sprite*sprite;
	Sprite*sprite_hp;
	void Destory();

	int hp;
	
	View_king(Node*scene, Vec2 pos);
	Menu*menu;

	void beenAttack(int damage);
	void  runTouchAction();




private:
	void updateState();
	Node *scene;

};





#endif // 


