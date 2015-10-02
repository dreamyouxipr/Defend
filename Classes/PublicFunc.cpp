#include "PublicFunc.h"


int  PublicFunc::cacl_distance(const Vec2 & pos1, const Vec2 &pos2)
{
	int x = abs(pos1.x - pos2.x);
	int y = abs(pos1.y - pos2.y);

	return  sqrt(x*x + y*y);
}

float  PublicFunc::getRotation(Vec2 pos, Vec2 pos_1)/*pos_1 = Tower */
{
	float rot;

	if (pos.y >= pos_1.y)/*  pos 在 pos1 上面*/
	{

		float xx = (pos.x - pos_1.x) / PublicFunc::cacl_distance(pos, pos_1);
		if (xx >= 1)xx = 1;
		if (xx <= -1)xx = -1;
		rot = 57.29578*asin(xx);
	}
	else if (pos.y <= pos_1.y)
	{
		float xx = (pos.x - pos_1.x) / PublicFunc::cacl_distance(pos, pos_1);
		if (xx >= 1)xx = 1;
		if (xx <= -1)xx = -1;
		rot = -57.29578*asin(xx);
		rot = 180.f + rot;
	}
	else
	{
		if (pos.x > pos_1.x){ rot = 90.f; }
		else rot = 270.f;
	}

	return rot;
}


bool  PublicFunc::isInattackRange(Tower_UI*tower, Monster_UI*monster)
{


	return (tower->attackRange + monster->sprite->getContentSize().width / 2) >
		PublicFunc::cacl_distance(monster->sprite->getPosition(),
		tower->sprite->getPosition());



}



void   PublicFunc::setEffectEnable(bool b)
{
	UserDefault::getInstance()->setBoolForKey("isEffect", !b);

	if (b)
	{
		SimpleAudioEngine::getInstance()->setEffectsVolume(1);

	}
	else
	{
		SimpleAudioEngine::getInstance()->setEffectsVolume(0);

	}

}


void  PublicFunc::setMusicEnable(bool b)
{
	UserDefault::getInstance()->setBoolForKey("isMusic", !b);
	if (b)
	{
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);

	}
	else
	{
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0);

	}
}




void PublicFunc::setUserDefault_AllClear(string  key, bool b )
{
	key = "all_" + key;

	UserDefault::getInstance()->setBoolForKey(key.c_str(), b);
	UserDefault::getInstance()->flush();

}


void PublicFunc::setUserDefault_Lev(string key, int lev)/*保存关卡成就 3最高*/
{
	UserDefault::getInstance()->setIntegerForKey(key.c_str(), lev);
	UserDefault::getInstance()->flush();

}

bool PublicFunc::getUserDefault_AllClear_ByKey(string  key)
{
	return UserDefault::getInstance()->getBoolForKey(key.c_str());
}


int PublicFunc::getUserDefault_Lev_ByKey(string key)/*保存关卡成就 3最高*/
{
	return UserDefault::getInstance()->getIntegerForKey(key.c_str());

}
