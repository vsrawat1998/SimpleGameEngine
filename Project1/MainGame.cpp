#include "MainGame.h"
#include "Errors.h"
#include<iostream>
#include<string>

MainGame::MainGame():
	_window(nullptr),
	_gameState(GameState::PLAY),
	_screenWidth(500), 
	_screenHeight(500),
	_time(0) 
{
	
}
MainGame::~MainGame() {
	
}
void MainGame::run() {
	initSystems();

	_sprite.init(-1.0f, -1.0f, 2.0f, 2.0f);

	gameLoop();
}

void MainGame::initSystems() {
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window with the given width and height
	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,_screenWidth,_screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL_GL Context could not be created!");
	}

	GLenum glError = glewInit();
	if (glError != GLEW_OK) {
		fatalError("Could not initialize GLEW!");
	}

	// Uses a double buffer Window to prevent flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	initShaders();
}

void MainGame::initShaders() {
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.linkShaders();
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
		_time += 0.01;
		drawGame();
	}
}

void MainGame::drawGame() {

	//Set base depth to 1.0
	glClearDepth(1.0);
	//Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	_colorProgram.use();

	GLuint timeLocation = _colorProgram.getUniformLocation("time");
	glUniform1f(timeLocation, _time);

	_sprite.draw();

	_colorProgram.unuse();

	//Swap the buffer and draw onto the screen.
	SDL_GL_SwapWindow(_window);
}