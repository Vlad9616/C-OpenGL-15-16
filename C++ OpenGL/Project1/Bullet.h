#pragma once
#include "Common.h"
class Bullet : public CommonData
{
public:
	float speed;
	Bullet()
	{
		set_xaxis(100);
		set_yaxis(100);
		speed = 0;
	}
};