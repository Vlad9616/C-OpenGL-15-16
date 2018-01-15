// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// OpenGL without using GLUT - 2013 by Neil Dansey, Tim Dykes and Ian Cant, and using excerpts from here:
// http://bobobobo.wordpress.com/2008/02/11/opengl-in-a-proper-windows-app-no-glut/
// Feel free to adapt this for what you need, but please leave these comments in.

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#pragma once

#include <windows.h>	// need this file if you want to create windows etc
#include <gl/gl.h>		// need this file to do graphics with opengl
#include <gl/glu.h>		// need this file to set up a perspective projection easily
#include <math.h>
#include "Common.h" 
#include "Bullet.h"
#include "Turret.h"
#include "PowerUp.h"
#include "Tank.h"
#include "Game.h"
// include the opengl and glu libraries
#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glu32.lib")




// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


float turretVertices[18] =
{
	-0.05f, -0.05f, 0.0f,
	0.05f, -0.05f, 0.0f,
	-0.05f, 0.05f, 0.0f,
	-0.05f, 0.05f, 0.0f,
	0.05f, -0.05f, 0.0f,
	0.05f, 0.05f, 0.0f
};

float turretColor[24] =
{
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};
float bulletVertices[18] =
{
	-0.01f, -0.01f, 0.0f,
	0.01f, -0.01f, 0.0f,
	-0.01f, 0.01f, 0.0f,
	-0.01f, 0.01, 0.0f,
	0.01f, -0.01f, 0.0f,
	0.01f, 0.01f, 0.0f
};

float bulletColor[24] =
{
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f

};

float powerup_vertices[18] =
{
	-0.05f, -0.05f, 0.0f,
	0.05f, -0.05f, 0.0f,
	-0.05f, 0.05f, 0.0f,
	-0.05f, 0.05, 0.0f,
	0.05f, -0.05f, 0.0f,
	0.05f, 0.05f, 0.0f
};

float powerup_color[24]=
{
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f
};
float tankVertices[18] = {
	-0.1f, -0.1f, 0.0f,
	0.1f, -0.1f, 0.0f,
	-0.1f, 0.1f, 0.0f,
	-0.1f, 0.1, 0.0f,
	0.1f, -0.1f, 0.0f,
	0.1f, 0.1f, 0.0f
};


float tankVertexColors[24] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f
};

float tankVertexColors2[24] = {
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f
};






bool detectCollision(float x1, float y1, float x2, float y2, float maxDistance);
void draw(Game *GamePointer);
void update(Game *GamePointer);
// function prototypes:
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow);


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// In a C++ Windows app, the starting point is WinMain() rather than _tmain() or main().
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	// some basic numbers to hold the position and size of the window
	int windowWidth = 800;
	int windowHeight = 600;
	int windowTopLeftX = 50;
	int windowTopLeftY = 50;

	// some other variables we need for our game...
	MSG msg;								// this will be used to store messages from the operating system
	bool keepPlaying = true;				// whether or not we want to keep playing



	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// this section contains all the window initialisation code, 
	// and should probably be collapsed for the time being to avoid confusion	
#pragma region  <-- click the plus/minus sign to collapse/expand!

	// this bit creates a window class, basically a template for the window we will make later, so we can do more windows the same.
	WNDCLASS myWindowClass;
	myWindowClass.cbClsExtra = 0;											// no idea
	myWindowClass.cbWndExtra = 0;											// no idea
	myWindowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// background fill black
	myWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// arrow cursor       
	myWindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// type of icon to use (default app icon)
	myWindowClass.hInstance = hInstance;									// window instance name (given by the OS when the window is created)   
	myWindowClass.lpfnWndProc = WndProc;									// window callback function - this is our function below that is called whenever something happens
	myWindowClass.lpszClassName = TEXT("my window class name");				// our new window class name
	myWindowClass.lpszMenuName = 0;											// window menu name (0 = default menu?) 
	myWindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;				// redraw if the window is resized horizontally or vertically, allow different context for each window instance

	// Register that class with the Windows OS..
	RegisterClass(&myWindowClass);

	// create a rect structure to hold the dimensions of our window
	RECT rect;
	SetRect(&rect, windowTopLeftX,				// the top-left corner x-coordinate
		windowTopLeftY,				// the top-left corner y-coordinate
		windowTopLeftX + windowWidth,		// far right
		windowTopLeftY + windowHeight);	// far left

	// adjust the window, no idea why.
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	// call CreateWindow to create the window
	HWND myWindow = CreateWindow(TEXT("my window class name"),		// window class to use - in this case the one we created a minute ago
		TEXT("CT4TOGA Coursework Template"),		// window title
		WS_OVERLAPPEDWINDOW,						// ??
		windowTopLeftX, windowTopLeftY,			// x, y
		windowWidth, windowHeight,				// width and height
		NULL, NULL,								// ??
		hInstance, NULL);							// ??


	// check to see that the window created okay
	if (myWindow == NULL)
	{
		FatalAppExit(NULL, TEXT("CreateWindow() failed!")); // ch15
	}

	// if so, show it
	ShowWindow(myWindow, iCmdShow);


	// get a device context from the window
	HDC myDeviceContext = GetDC(myWindow);


	// we create a pixel format descriptor, to describe our desired pixel format. 
	// we set all of the fields to 0 before we do anything else
	// this is because PIXELFORMATDESCRIPTOR has loads of fields that we won't use
	PIXELFORMATDESCRIPTOR myPfd = { 0 };


	// now set only the fields of the pfd we care about:
	myPfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);		// size of the pfd in memory
	myPfd.nVersion = 1;									// always 1

	myPfd.dwFlags = PFD_SUPPORT_OPENGL |				// OpenGL support - not DirectDraw
		PFD_DOUBLEBUFFER |				// double buffering support
		PFD_DRAW_TO_WINDOW;					// draw to the app window, not to a bitmap image

	myPfd.iPixelType = PFD_TYPE_RGBA;					// red, green, blue, alpha for each pixel
	myPfd.cColorBits = 24;								// 24 bit == 8 bits for red, 8 for green, 8 for blue.
	// This count of color bits EXCLUDES alpha.

	myPfd.cDepthBits = 32;								// 32 bits to measure pixel depth.


	// now we need to choose the closest pixel format to the one we wanted...	
	int chosenPixelFormat = ChoosePixelFormat(myDeviceContext, &myPfd);

	// if windows didnt have a suitable format, 0 would have been returned...
	if (chosenPixelFormat == 0)
	{
		FatalAppExit(NULL, TEXT("ChoosePixelFormat() failed!"));
	}

	// if we get this far it means we've got a valid pixel format
	// so now we need to set the device context up with that format...
	int result = SetPixelFormat(myDeviceContext, chosenPixelFormat, &myPfd);

	// if it failed...
	if (result == NULL)
	{
		FatalAppExit(NULL, TEXT("SetPixelFormat() failed!"));
	}

	// we now need to set up a render context (for opengl) that is compatible with the device context (from windows)...
	HGLRC myRenderContext = wglCreateContext(myDeviceContext);

	// then we connect the two together
	wglMakeCurrent(myDeviceContext, myRenderContext);


	// opengl display setup
	glMatrixMode(GL_PROJECTION);	// select the projection matrix, i.e. the one that controls the "camera"
	glLoadIdentity();				// reset it
	gluPerspective(45.0, (float)windowWidth / (float)windowHeight, 1, 1000);	// set up fov, and near / far clipping planes
	glViewport(0, 0, windowWidth, windowHeight);							// make the viewport cover the whole window
	glClearColor(0.5, 0, 0, 1.0);											// set the colour used for clearing the screen

	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#pragma endregion

	// main game loop starts here!
	Game *GamePointer = new Game;
	//Player 1
	GamePointer->tankList[0].set_xaxis(0.0f);
	GamePointer->tankList[0].set_yaxis(0.0f);
	GamePointer->tankList[0].setRotation(0.0f);
	//Player 2
	GamePointer->tankList[1].set_xaxis(0.5f);
	GamePointer->tankList[1].set_yaxis(0.5f);
	GamePointer->tankList[1].setRotation(0.0f);

	// keep doing this as long as the player hasnt exited the app: 
	while (keepPlaying == true)
	{
		//GamePointer->frameStratTime = GetTickCount();
		// we need to listen out for OS messages.
		// if there is a windows message to process...
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// and if the message is a "quit" message...
			if (msg.message == WM_QUIT || msg.wParam==VK_ESCAPE)
			{
				keepPlaying = false;	// we want to quit asap
			}
			else
				if (msg.message == WM_KEYDOWN)
				{
					//Player 1
					//
					switch (msg.wParam)
					{
					case 'A':GamePointer->tankList[0].setTurnLeft(true);
						break;
					case 'D':GamePointer->tankList[0].setTurnRight(true);
						break;
					case 'W':GamePointer->tankList[0].setSpeedUp(true);
						break;
					case 'S':GamePointer->tankList[0].setSpeedDown(true);
						break;
					case'F':GamePointer->tankList[0].setFire(true);
						break;
					case'Q':GamePointer->tankList[0].createTurret->setLrotation(true);
						break;
					case 'E':GamePointer->tankList[0].createTurret->setRrotation(true);
						break;
					}
					//
					//Player 2
					//
					switch (msg.wParam)
					{
					case 'J':GamePointer->tankList[1].setTurnLeft(true);
						break;
					case 'L':GamePointer->tankList[1].setTurnRight(true);
						break;
					case 'I':GamePointer->tankList[1].setSpeedUp(true);
						break;
					case 'K':GamePointer->tankList[1].setSpeedDown(true);
						break;
					case'H':GamePointer->tankList[1].setFire(true);
						break;
					case'U':GamePointer->tankList[1].createTurret->setLrotation(true);
						break;
					case 'O':GamePointer->tankList[1].createTurret->setRrotation(true);
						break;
					}
					//
				}
				else
					if (msg.message == WM_KEYUP)
					{
						//Player 1	
						switch (msg.wParam)
						{
						case 'A':GamePointer->tankList[0].setTurnLeft(false);
							break;
						case 'D':GamePointer->tankList[0].setTurnRight(false);
							break;
						case 'W':GamePointer->tankList[0].setSpeedUp(false);
							break;
						case 'S':GamePointer->tankList[0].setSpeedDown(false);
							break;
						case'F':GamePointer->tankList[0].setFire(false);
							break;
						case'Q':GamePointer->tankList[0].createTurret->setLrotation(false);
							break;
						case 'E':GamePointer->tankList[0].createTurret->setRrotation(false);
							break;
						}
						//Player 2
						switch (msg.wParam)
						{
						case 'J':GamePointer->tankList[1].setTurnLeft(false);
							break;
						case 'L':GamePointer->tankList[1].setTurnRight(false);
							break;
						case 'I':GamePointer->tankList[1].setSpeedUp(false);
							break;
						case 'K':GamePointer->tankList[1].setSpeedDown(false);
							break;
						case'H':GamePointer->tankList[1].setFire(false);
							break;
						case'U':GamePointer->tankList[1].createTurret->setLrotation(false);
							break;
						case 'O':GamePointer->tankList[1].createTurret->setRrotation(false);
							break;
						}
					}	
			
			// or if it was any other type of message (i.e. one we don't care about), process it as normal...
					else
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear screen
		update(GamePointer);
		draw(GamePointer);
		SwapBuffers(myDeviceContext);							// update graphics
	}


	// the next bit will therefore happen when the player quits the app,
	// because they are trapped in the previous section as long as (keepPlaying == true).

	// UNmake our rendering context (make it 'uncurrent')
	wglMakeCurrent(NULL, NULL);

	// delete the rendering context, we no longer need it.
	wglDeleteContext(myRenderContext);

	// release our window's DC from the window
	ReleaseDC(myWindow, myDeviceContext);
	//clear


	delete GamePointer;
	GamePointer = NULL;
	// end the program
	return msg.wParam;
}
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// this part contains some code that should be collapsed for now too...
#pragma region keep_this_bit_collapsed_too!

// this function is called when any events happen to our window
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{

	switch (message)
	{
		// if they exited the window...
	case WM_DESTROY:
		// post a message "quit" message to the main windows loop
		PostQuitMessage(0);
		return 0;
		break;
	}

	// must do this as a default case (i.e. if no other event was handled)...
	return DefWindowProc(hwnd, message, wparam, lparam);

}
#pragma endregion
//COLLISION
bool detectCollision(float x1, float y1, float x2, float y2, float maxDistance)
{
	float xDiff = x1 - x2;
	float yDiff = y1 - y2;
	float xDiffSquared = pow(xDiff, 2);
	float yDiffSquared = pow(yDiff, 2);
	float total = xDiffSquared + yDiffSquared;
	float distance = sqrt(total);
	if (distance < maxDistance)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//DRAW
void draw(Game *GamePointer)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glMatrixMode(GL_MODELVIEW);
	for (int i = 0; i <2; i++)
	{
		glVertexPointer(3, GL_FLOAT, 0, tankVertices);
		if (i == 0)
		{
			glColorPointer(4, GL_FLOAT, 0, tankVertexColors);
		}
		else
		{
			glColorPointer(4, GL_FLOAT, 0, tankVertexColors2);
		}
		glLoadIdentity();
		glTranslatef(GamePointer->tankList[i].get_xaxis(), GamePointer->tankList[i].get_yaxis(), -5.0);
		glRotatef(GamePointer->tankList[i].get_rotation(), 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		//draw bullets
		glVertexPointer(3, GL_FLOAT, 0, bulletVertices);
		glColorPointer(4, GL_FLOAT, 0, bulletColor);
		glLoadIdentity();
		glTranslatef(GamePointer->tankList[i].createBullet->get_xaxis(), GamePointer->tankList[i].createBullet->get_yaxis(), -5.0);
		glRotatef(GamePointer->tankList[i].createBullet->get_rotation(), 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		//draw turrnet
		glVertexPointer(3, GL_FLOAT, 0, turretVertices);
		glColorPointer(4, GL_FLOAT, 0, turretColor);
		glLoadIdentity();
		glTranslatef(GamePointer->tankList[i].get_xaxis(), GamePointer->tankList[i].get_yaxis(), -5.0);
		glRotatef(GamePointer->tankList[i].createTurret->get_rotation(),0.0,0.0,1.0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	//draw power up1
	glVertexPointer(3, GL_FLOAT, 0, powerup_vertices);
	glColorPointer(4, GL_FLOAT, 0, powerup_color);
	glLoadIdentity();
	glTranslatef(GamePointer->Power1->get_xaxis(), GamePointer->Power1->get_yaxis(), -5.0);
	glRotatef(GamePointer->Power1->get_rotation(), 0.0, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//draw power up2
	glVertexPointer(3,GL_FLOAT,0,powerup_vertices);
	glColorPointer(4,GL_FLOAT,0,powerup_color);
	glLoadIdentity();
	glTranslatef(GamePointer->Power2->get_xaxis(), GamePointer->Power2->get_yaxis(),-5.0);
	glRotatef(GamePointer->Power2->get_rotation(), 0.0, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLES,0,6);
	//
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
};
//UPDATE
void update(Game *GamePointer)
{
	//Collision Detection
	if (detectCollision(GamePointer->tankList[0].get_xaxis(), GamePointer->tankList[0].get_yaxis(), GamePointer->tankList[1].get_xaxis(), GamePointer->tankList[1].get_yaxis(), 0.2f) == true || detectCollision(GamePointer->tankList[0].get_xaxis(), GamePointer->tankList[0].get_yaxis(), GamePointer->tankList[1].createBullet->get_xaxis(), GamePointer->tankList[1].createBullet->get_yaxis(), 0.2f) == true || detectCollision(GamePointer->tankList[1].get_xaxis(), GamePointer->tankList[1].get_yaxis(), GamePointer->tankList[0].createBullet->get_xaxis(), GamePointer->tankList[0].createBullet->get_yaxis(), 0.2f) == true)
	{
		glClearColor(1.0, 1.0, 1.0, 1.0);
	}
	///PlayerMovement///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Player 1
	if (GamePointer->tankList[0].getTurnLeft() == true)
	{
		GamePointer->tankList[0].setRotation(GamePointer->tankList[0].get_rotation() + 1);
	}
	if (GamePointer->tankList[0].getTurnRight() == true)
	{
		GamePointer->tankList[0].setRotation(GamePointer->tankList[0].get_rotation() - 1);
	}
	if (GamePointer->tankList[0].getSpeedUp() == true)
	{
		GamePointer->tankList[0].set_xaxis(GamePointer->tankList[0].get_xaxis() + (0.01*cos(0.01745f *GamePointer->tankList[0].get_rotation())));
		GamePointer->tankList[0].set_yaxis(GamePointer->tankList[0].get_yaxis() + (0.01*sin(0.01745f *GamePointer->tankList[0].get_rotation())));
	}
	if (GamePointer->tankList[0].getSpeedDown() == true)
	{
		GamePointer->tankList[0].set_xaxis(GamePointer->tankList[0].get_xaxis() + (-0.01*cos(0.01745f *GamePointer->tankList[0].get_rotation())));
		GamePointer->tankList[0].set_yaxis(GamePointer->tankList[0].get_yaxis() + (-0.01*sin(0.01745f *GamePointer->tankList[0].get_rotation())));
	}
	//PLAYER 1 BULLETS
	if (GamePointer->tankList[0].getFire() == true && GamePointer->tankList[0].getReloader() == true)
	{
		GamePointer->tankList[0].createBullet->set_xaxis(GamePointer->tankList[0].get_xaxis());
		GamePointer->tankList[0].createBullet->set_yaxis(GamePointer->tankList[0].get_yaxis());
		GamePointer->tankList[0].createBullet->setRotation(GamePointer->tankList[0].createTurret->get_rotation());
		GamePointer->tankList[0].setReloaded(false);
	}
	GamePointer->tankList[0].createBullet->set_xaxis(GamePointer->tankList[0].createBullet->get_xaxis() + (0.01*cos(0.01745f *GamePointer->tankList[0].createBullet->get_rotation())));
	GamePointer->tankList[0].createBullet->set_yaxis(GamePointer->tankList[0].createBullet->get_yaxis() + (0.01*sin(0.01745f *GamePointer->tankList[0].createBullet->get_rotation())));
	//TURRET PLAYER 1
	//ROTATING
	if (GamePointer->tankList[0].createTurret->getRrotation() == true)
	{
		GamePointer->tankList[0].createTurret->setRotation(GamePointer->tankList[0].createTurret->get_rotation() - 1);
	}
	if (GamePointer->tankList[0].createTurret->getLrotation() == true)
	{
		GamePointer->tankList[0].createTurret->setRotation(GamePointer->tankList[0].createTurret->get_rotation() + 1);
	}
	GamePointer->tankList[0].createTurret->set_xaxis(GamePointer->tankList[0].createTurret->get_xaxis() + (0.01*cos(0.01745f *GamePointer->tankList[0].createTurret->get_rotation())));
	GamePointer->tankList[0].createTurret->set_yaxis(GamePointer->tankList[0].createTurret->get_yaxis() + (0.01*sin(0.01745f *GamePointer->tankList[0].createTurret->get_rotation())));
	//PLAYER 2
	if (GamePointer->tankList[1].getTurnLeft() == true)
	{
		GamePointer->tankList[1].setRotation(GamePointer->tankList[1].get_rotation() + 1);
	}
	if (GamePointer->tankList[1].getTurnRight() == true)
	{
		GamePointer->tankList[1].setRotation(GamePointer->tankList[1].get_rotation() - 1);
	}
	if (GamePointer->tankList[1].getSpeedUp() == true)
	{
		GamePointer->tankList[1].set_xaxis(GamePointer->tankList[1].get_xaxis() + (0.01*cos(0.01745f *GamePointer->tankList[1].get_rotation())));
		GamePointer->tankList[1].set_yaxis(GamePointer->tankList[1].get_yaxis() + (0.01*sin(0.01745f *GamePointer->tankList[1].get_rotation())));
	}
	if (GamePointer->tankList[1].getSpeedDown() == true)
	{
		GamePointer->tankList[1].set_xaxis(GamePointer->tankList[1].get_xaxis() + (-0.01*cos(0.01745f *GamePointer->tankList[1].get_rotation())));
		GamePointer->tankList[1].set_yaxis(GamePointer->tankList[1].get_yaxis() + (-0.01*sin(0.01745f *GamePointer->tankList[1].get_rotation())));
	}
	//PLAYER 2 BULLETS
	if (GamePointer->tankList[1].getFire() == true && GamePointer->tankList[1].getReloader() == true)
	{
		GamePointer->tankList[1].createBullet->set_xaxis(GamePointer->tankList[1].get_xaxis());
		GamePointer->tankList[1].createBullet->set_yaxis(GamePointer->tankList[1].get_yaxis());
		GamePointer->tankList[1].createBullet->setRotation(GamePointer->tankList[1].createTurret->get_rotation());
		GamePointer->tankList[1].setReloaded(false);
	}
	GamePointer->tankList[1].createBullet->set_xaxis(GamePointer->tankList[1].createBullet->get_xaxis() + (0.01*cos(0.01745f *GamePointer->tankList[1].createBullet->get_rotation())));
	GamePointer->tankList[1].createBullet->set_yaxis(GamePointer->tankList[1].createBullet->get_yaxis() + (0.01*sin(0.01745f *GamePointer->tankList[1].createBullet->get_rotation())));
	//TURRET PLAYER 2
	//ROTATING
	if (GamePointer->tankList[1].createTurret->getRrotation() == true)
	{
		GamePointer->tankList[1].createTurret->setRotation(GamePointer->tankList[1].createTurret->get_rotation() - 1);
	}
	if (GamePointer->tankList[1].createTurret->getLrotation() == true)
	{
		GamePointer->tankList[1].createTurret->setRotation(GamePointer->tankList[1].createTurret->get_rotation() + 1);
	}
	GamePointer->tankList[1].createTurret->set_xaxis(GamePointer->tankList[1].createTurret->get_xaxis() + (0.01*cos(0.01745f *GamePointer->tankList[1].createTurret->get_rotation())));
	GamePointer->tankList[1].createTurret->set_yaxis(GamePointer->tankList[1].createTurret->get_yaxis() + (0.01*sin(0.01745f *GamePointer->tankList[1].createTurret->get_rotation())));
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//SET BULLETS TO 100 100
	if (GamePointer->tankList[0].createBullet->get_xaxis() > 2.5f)
	{
		GamePointer->tankList[0].createBullet->set_xaxis(100);
		GamePointer->tankList[0].setReloaded(true);
	}
	if (GamePointer->tankList[0].createBullet->get_xaxis() < -2.5f)
	{
		GamePointer->tankList[0].createBullet->set_xaxis(100);
		GamePointer->tankList[0].setReloaded(true);
	}
	if (GamePointer->tankList[0].createBullet->get_yaxis() > 2.5f)
	{
		GamePointer->tankList[0].createBullet->set_yaxis(100);
		GamePointer->tankList[0].setReloaded(true);
	}
	if (GamePointer->tankList[0].createBullet->get_yaxis() < -2.5f)
	{
		GamePointer->tankList[0].createBullet->set_yaxis(100);
		GamePointer->tankList[0].setReloaded(true);
	}

	if (GamePointer->tankList[1].createBullet->get_xaxis() > 2.5f)
	{
		GamePointer->tankList[1].createBullet->set_xaxis(100);
		GamePointer->tankList[1].setReloaded(true);
	}
	if (GamePointer->tankList[1].createBullet->get_xaxis() < -2.5f)
	{
		GamePointer->tankList[1].createBullet->set_xaxis(100);
		GamePointer->tankList[1].setReloaded(true);
	}
	if (GamePointer->tankList[1].createBullet->get_yaxis() > 2.5f)
	{
		GamePointer->tankList[1].createBullet->set_yaxis(100);
		GamePointer->tankList[1].setReloaded(true);
	}
	if (GamePointer->tankList[1].createBullet->get_yaxis() < -2.5f)
	{
		GamePointer->tankList[1].createBullet->set_yaxis(100);
		GamePointer->tankList[1].setReloaded(true);
	}
	//screen wrapping
	//Player 1
	if (GamePointer->tankList[0].get_xaxis() > 2.5f)
	{
		GamePointer->tankList[0].set_xaxis(-2.5f);
	}
	if (GamePointer->tankList[0].get_xaxis() < -2.5f)
	{
		GamePointer->tankList[0].set_xaxis(2.5f);
	}

	if (GamePointer->tankList[0].get_yaxis() > 2.5f)
	{
		GamePointer->tankList[0].set_yaxis(-2.5f);
	}
	if (GamePointer->tankList[0].get_yaxis() < -2.5f)
	{
		GamePointer->tankList[0].set_yaxis(2.5f);
	}
	//Player 2
	if (GamePointer->tankList[1].get_xaxis() > 2.5f)
	{
		GamePointer->tankList[1].set_xaxis(-2.5f);
	}
	if (GamePointer->tankList[1].get_xaxis() < -2.5f)
	{
		GamePointer->tankList[1].set_xaxis(2.5f);
	}

	if (GamePointer->tankList[1].get_yaxis() > 2.5f)
	{
		GamePointer->tankList[1].set_yaxis(-2.5f);
	}
	if (GamePointer->tankList[1].get_yaxis() < -2.5f)
	{
		GamePointer->tankList[1].set_yaxis(2.5f);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}