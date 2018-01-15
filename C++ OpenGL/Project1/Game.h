#pragma once
#include "PowerUp.h"
#include "Tank.h"

class Game
{
public:
	Tank *tankList;
	PowerUp *Power1 = new PowerUp(0, 0, 0);
	PowerUp *Power2 = new PowerUp(1, 1, 1);
	Game()
	{
		tankList = new Tank[2];
	}
	~Game()
	{

		delete Power1;
		Power1 = NULL;
		delete Power2;
		Power2 = NULL;
		delete[] tankList;
		tankList = NULL;
	}
};