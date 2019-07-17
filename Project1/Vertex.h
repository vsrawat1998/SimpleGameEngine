#pragma once

#include<GL/glew.h>

// Size of the Vertex struct should be a multiple of 4 
// to prevent alignment issues.

struct Position {
	float x, y;
};

struct Color {
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

struct Vertex {
	 
	Position position;

	Color color;
};