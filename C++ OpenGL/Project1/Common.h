#pragma once

class CommonData
{
private:
	float xaxis;
	float yaxis;
	float rotation;
public:
	//getters
	float get_xaxis(void);
	float get_yaxis(void);
	float get_rotation(void);
	//setters
	void set_xaxis(float thexAxis);
	void set_yaxis(float theyAxis);
	void setRotation(float theRotation);
};