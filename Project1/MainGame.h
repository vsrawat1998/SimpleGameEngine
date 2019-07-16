#pragma once
#include<iostream>
#include<GL/glew.h>
#include<SDL/SDL.h>

enum class GameState {
	PLAY,
	EXIT
};

class MainGame
{
	SDL_Window* _window;
	GameState _gameState;
	int _screenWidth, _screenHeight;

	void initSystems();
	void processInput();
	void gameLoop();
public:
	MainGame();
	~MainGame();

	void run();

	
	
};

