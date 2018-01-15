#include "Common.h"
#include "Tank.h"

bool Tank::getReloader()
{
	return reloaded;
}
bool Tank::getSpeedUp(void)
{
	return speed_up;
}
bool Tank::getSpeedDown(void)
{
	return speed_down;
}
bool Tank::getTurnLeft(void)
{
	return turn_left;
}
bool Tank::getTurnRight(void)
{
	return turn_right;
}
bool Tank::getFire(void)
{
	return fire;
}
//SETTERS
void Tank :: setReloaded(bool theReloaded)
{
	reloaded = theReloaded;
}
void Tank :: setSpeedUp(bool theSpeedUp)
{
	speed_up = theSpeedUp;
}
void Tank::setSpeedDown(bool theSpeedDown)
{
	speed_down = theSpeedDown;
}
void Tank::setTurnLeft(bool theTurnLeft)
{
	turn_left = theTurnLeft;
}
void Tank::setTurnRight(bool theTurnRight)
{
	turn_right = theTurnRight;
}
void Tank::setFire(bool theFire)
{
	fire = theFire;
}