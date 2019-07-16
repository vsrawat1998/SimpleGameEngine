#pragma once
#include<string>
#include<GL/glew.h>
class GLSLProgram
{
	GLuint _progID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
	
	int _numAttributes;

	void compileShader(const std::string& filePath, GLuint id);
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string &vertexShaderFilePath,
		const std::string &fragmentShaderFilePath);
	void linkShaders();

	void addAttribute(const std::string &attributeName);

	void use();
	void unuse();

};

