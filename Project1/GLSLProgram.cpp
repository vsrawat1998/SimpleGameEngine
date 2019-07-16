#include "GLSLProgram.h"
#include "Errors.h"

#include<fstream>
#include<vector>

GLSLProgram::GLSLProgram():_progID(0),_vertexShaderID(0),
_fragmentShaderID(0), _numAttributes(0){

}

GLSLProgram::~GLSLProgram() {

}

void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath,
	const std::string& fragmentShaderFilePath) {

	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0) {
		fatalError("Vertex shader failed to be created!");
	}
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0) {
		fatalError("Fragment shader failed to be created!");
	}

	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);

}
void GLSLProgram::linkShaders() {
	_progID = glCreateProgram();

	glAttachShader(_progID, _vertexShaderID);
	glAttachShader(_progID, _fragmentShaderID);

	glLinkProgram(_progID);

	GLint isLinked = 0;
	glGetProgramiv(_progID, GL_LINK_STATUS, (int*)& isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(_progID, GL_INFO_LOG_LENGTH , &maxLength);
	
		std::vector<char> errorLog(maxLength);

		glGetProgramInfoLog(_progID, maxLength, &maxLength, &errorLog[0]);

		glDeleteProgram(_progID);

		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);
		  

		fatalError("Shaders failed to link!");
		std::printf("%s\n", &(errorLog[0]));

		return;
	}

	glDetachShader(_progID, _vertexShaderID);
	glDetachShader(_progID, _fragmentShaderID);

	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}
void GLSLProgram::compileShader(const std::string& filePath, GLuint id) {
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {
		perror(filePath.c_str());
		fatalError("Failed to open " + filePath);
	}

	std::string fileContents = "";
	std::string line;
	while (std::getline(vertexFile, line)) {
		fileContents += line + "\n";
	}
	vertexFile.close();
	const char* contentsPtr = fileContents.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);

	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(id);

		fatalError("Shader "+ filePath +" failed to compile!");
		std::printf("%s\n", &(errorLog[0]));
		return;
	}
}
void GLSLProgram::addAttribute(const std::string& attributeName) {
	glBindAttribLocation(_progID, _numAttributes++, attributeName.c_str());
}

void GLSLProgram::use(){
	glUseProgram(_progID);
	for (int i = 0; i < _numAttributes; i++) {
		glEnableVertexAttribArray(i);
	}
}
void GLSLProgram::unuse(){
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++) {
		glDisableVertexAttribArray(i);
	}
}