#include "object.h"


void DatePos_Array:: clear()
{
	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			data[x][y] = 0;
		}
	}
}


