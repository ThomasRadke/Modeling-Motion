#ifndef VertexBufferObject_CLASS_H
#define VertexBufferObject_CLASS_H
#include<GL/glew.h>

class VertexBufferObject {
public:
	GLuint ID;
	VertexBufferObject(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};


#endif