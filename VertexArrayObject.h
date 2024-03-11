#ifndef VertexArrayObject_CLASS_H
#define VertexArrayObject_CLASS_H

#include<GL/glew.h>
#include"VertexBufferObject.h"

class VertexArrayObject {
public:
	GLuint ID; //reference ID
	VertexArrayObject(); //constructor

	void Link(VertexBufferObject& VBO, GLuint layout, GLuint numComponents, GLuint type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};




#endif