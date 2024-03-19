#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include"GL/glew.h"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
public:
	GLuint ID;
	Shader(const char* vShaderFile, const char* fShaderFile);
	void Activate();
	void Delete();

private:
	void CompileErrors(unsigned int Shader, const char* type);
};
#endif // !SHADERCLASS_CLASS_H
