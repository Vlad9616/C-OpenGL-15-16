#pragma once 
#include "PowerUp.h"
#include "Common.h"

class PowerUp : public CommonData
{
public:
	PowerUp();
	PowerUp(float x, float y, float r);
};
PowerUp::PowerUp()
{
	set_xaxis(1.0);
	set_yaxis(1.0);
	setRotation(0.0);
}
PowerUp::PowerUp(float x, float y, float r)
{
	set_xaxis(x);
	set_yaxis(y);
	setRotation(r);
}