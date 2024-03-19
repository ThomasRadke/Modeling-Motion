#ifndef ELEMENTSBUFFEROBJECT_CLASS_H
#define ELEMENTSBUFFEROBJECT_CLASS_H
#include"GL/glew.h"

class ElementsBufferObject {
public:
	GLuint ID;

	ElementsBufferObject(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();


};

#endif // !ELEMENTSBUFFEROBJECT_CLASS_H

