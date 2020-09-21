#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "teapot_gl.h"

TeapotGL::TeapotGL() : PolygonGL() {
	this->size = 1.f;
}

TeapotGL::~TeapotGL() {

}

void TeapotGL::render() {
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	glutWireTeapot(this->size);
	glPopMatrix();
}