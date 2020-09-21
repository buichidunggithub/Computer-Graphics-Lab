#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "torus_gl.h"

TorusGL::TorusGL() : PolygonGL() {
	this->innerR = 0.25f;
	this->outerR = 0.8f;
	this->stacks = 32.f;
	this->slices = 32.f;
}

TorusGL::~TorusGL() {

}

void TorusGL::render() {
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	glutWireTorus(this->innerR, this->outerR, this->stacks, this->slices);
	glPopMatrix();
}