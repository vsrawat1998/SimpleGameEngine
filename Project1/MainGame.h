#pragma once
#include<GL/glew.h>
#include<SDL/SDL.h>
class MainGame
{
	SDL_Window* _window;
	int _screenWidth, _screenHeight;
public:
	MainGame();
	~MainGame();

	void run();

	void initSystems();
	
};

