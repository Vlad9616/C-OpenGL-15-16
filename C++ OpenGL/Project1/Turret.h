#pragma once 
#include "Common.h"
class Turret : public CommonData
{
public:
	//getters
	bool getRrotation(void);
	bool getLrotation(void);
	//setters
	void setRrotation(bool theRrotation);
	void setLrotation(bool theLrotation);
	Turret()
	{
		setRotation(0.0);
	}
private:
	bool r;
	bool l;
};