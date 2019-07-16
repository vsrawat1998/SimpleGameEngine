#include "Errors.h"
#include<iostream>
#include<SDL/SDL.h>

void fatalError(std::string errString) {
	std::cout << errString << "\n";
	std::cout << "Enter any key to exit...";
	int x;
	std::cin >> x;
	SDL_Quit();
}