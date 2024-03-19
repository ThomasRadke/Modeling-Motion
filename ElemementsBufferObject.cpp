#include"ElementsBufferObject.h"

ElementsBufferObject::ElementsBufferObject(GLuint* indices, GLsizeiptr size) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void ElementsBufferObject::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
}

void ElementsBufferObject::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementsBufferObject::Delete() {
	glDeleteBuffers(1, &ID);
}
