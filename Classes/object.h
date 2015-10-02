#ifndef object__

#define object__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace  std;
using namespace CocosDenshion;

#define  WIDTH Director::getInstance()->getVisibleSize().width
#define  FONT "FZHPJW_2.ttf"

class  Audio
{
public:
	static void play_Button()
	{
		SimpleAudioEngine::getInstance()->playEffect("Music/Main/Select.mp3");

	}

	static void stop_backgroundMusic()
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic(false);

	}















};


class DatePos_Array/*地图辅助数组*/
{
private:
	int data[12][7];/*0 代表 可用 其他代表不可用*/

public:
	void push_back(Vec2 v)
	{
		int x = v.x;
		int y = v.y;
		 data[x][y]=1;
	}
	void push_back( int x,int y)
	{
		data[x][y] = 1;
	}

	void pop(Vec2 v)
	{
		int x = v.x;
		int y = v.y;
		data[x][y]=0;
	}

	void pop( int x,int y)
	{
		data[x][y] = 0;
	}
	bool isUseAble(Vec2 v)
	{
		int x = v.x;
		int y = v.y;
		return !data[x][y];
	}
	bool isUseAble(int x,int y)
	{
		return !data[x][y];
	}


	void clear();




};



#endif // 


