#include "Common.h"

//getters
float CommonData::get_xaxis(void)
{
	return xaxis;
}
float CommonData::get_yaxis(void)
{
	return yaxis;
}
float CommonData::get_rotation(void)
{
	return rotation;
}
//setters
void CommonData::set_xaxis(float thexAxis)
{
	xaxis = thexAxis;
}
void CommonData::set_yaxis(float theyAxis)
{
	yaxis = theyAxis;
}
void CommonData::setRotation(float theRotation)
{
	rotation = theRotation;
}