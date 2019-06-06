#include "MainGame.h"

MainGame::MainGame() {
	
	_window = nullptr; // If the Window does not open up due to some issue, then null pointer violation will
	// help us identify it.

	// Initial parameter values for testing purposes 
	_screenWidth = 1368;
	_screenHeight = 768;
}
MainGame::~MainGame() {
	
}
void MainGame::run() {
	initSystems();
}

void MainGame::initSystems() {
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window with the given width and height
	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight, SDL_WINDOW_OPENGL);
}
