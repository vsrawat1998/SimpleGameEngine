#pragma once
#include<GL/glew.h>

class Sprite
{
	float _x;
	float _y;
	float _height;
	float _width;
	GLuint _vboID;
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);
	void draw();
};

