#pragma once 
#include "Common.h"
#include "Bullet.h"
#include "Turret.h"


class Tank : public CommonData
{
public:
	Bullet *createBullet = new Bullet;
	Turret *createTurret = new Turret;
	Tank()
	{
		reloaded = true;
	}
	//getters
	bool getReloader();
	bool getSpeedUp(void);
	bool getSpeedDown(void);
	bool getTurnLeft(void);
	bool getTurnRight(void);
	bool getFire(void);
	//SETTERS
	void setReloaded(bool theReloaded);
	void setSpeedUp(bool theSpeedUp);
	void setSpeedDown(bool theSpeedDown);
	void setTurnLeft(bool theTurnLeft);
	void setTurnRight(bool theTurnRight);
	void setFire(bool theFire);
private:
	bool speed_up;
	bool speed_down;
	bool turn_left;
	bool turn_right;
	bool fire;
	bool reloaded;
};