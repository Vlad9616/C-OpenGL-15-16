#include "Turret.h"
#include "Common.h"

//getters
bool Turret::getRrotation(void)
{
	return r;
}
bool Turret::getLrotation(void)
{
	return l;
}
//setters
void Turret::setRrotation(bool theRrotation)
{
	r = theRrotation;
}
void Turret::setLrotation(bool theLrotation)
{
	l = theLrotation;
}