

#ifndef object___

#define object___



#include "object.h"


#include "Monster_UI.h"
#include "Tower_UI.h"


class PublicFunc
{
public:
	static int cacl_distance(const Vec2 & pos1, const Vec2 &pos2);


	static float getRotation(Vec2 pos, Vec2 pos_1);/*pos_1 = Tower */


	static bool isInattackRange(Tower_UI*tower, Monster_UI*monster);

	static int convertToX(float x)
	{
		return(x - 40) / 80;
	}

	static int convertToY(float y)
	{
		return (y - 40) / 80;
	}


	static int convertToX(Vec2& x)
	{
		return (x.x - 40) / 80;
	}

	static int convertToY(Vec2& y)
	{
		return (y.y - 40) / 80;
	}



	static Vec2 convertToPoint(float x, float y)/*逻辑点 转换为像素*/
	{
		return Vec2(x * 80 + 40, y * 80 + 40);
	}



	static int getDirection(Vec2 &pre, Vec2 &next)/* next 位于 pre的位置*/
	{

		if (pre.x == next.x)
		{
			if (pre.y > next.y)return 2;
			return 8;
		}

		if (pre.x > next.x)return 4;
		return 6;


	}

	static void setEffectEnable(bool b);
	static void setMusicEnable(bool b);









	/*数据持久化*/
	static	void setUserDefault_AllClear(string  key, bool b = true);
	static void setUserDefault_Lev(string key, int lev);/*保存关卡成就 3最高*/
	static bool  getUserDefault_AllClear_ByKey(string  key);
	static	int getUserDefault_Lev_ByKey(string key);/*保存关卡成就 3最高*/







};








#endif // !TowerBase


