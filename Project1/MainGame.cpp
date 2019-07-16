#include "MainGame.h"

MainGame::MainGame() {
	
	_window = nullptr; // If the Window does not open up due to some issue, then null pointer violation will
	// help us identify it.

	// Initial parameter values for testing purposes 
	_screenWidth = 600;
	_screenHeight = 320;
	_gameState = GameState::PLAY;
}
MainGame::~MainGame() {
	
}
void MainGame::run() {
	initSystems();
	gameLoop();
}

void MainGame::initSystems() {
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window with the given width and height
	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight, SDL_WINDOW_OPENGL);
}
void MainGame::processInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y << "\n";
		}
	}

}
void MainGame::gameLoop() {
	while (_gameState != GameState::EXIT) {
		processInput();
	}
}