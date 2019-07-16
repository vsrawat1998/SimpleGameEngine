#pragma once
#include<iostream>
#include<string>
#include<GL/glew.h>
#include<SDL/SDL.h>

#include "Sprite.h"

enum class GameState {
	PLAY,
	EXIT
};

class MainGame
{
	SDL_Window* _window;
	GameState _gameState;
	Sprite _sprite;
	int _screenWidth, _screenHeight;

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
public:
	MainGame();
	~MainGame();

	void run();

	
	
};

