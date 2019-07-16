#pragma once

#include<GL/glew.h>
#include<SDL/SDL.h>

#include "GLSLProgram.h"
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
	GLSLProgram _colorProgram;
	int _screenWidth, _screenHeight;

	void initSystems();
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();
public:
	MainGame();
	~MainGame();

	void run();

	
	
};

