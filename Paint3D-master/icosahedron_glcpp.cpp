#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "icosahedron_gl.h"

IcosahedronGL::IcosahedronGL() : PolygonGL() {

}

IcosahedronGL::~IcosahedronGL() {

}

void IcosahedronGL::render() {
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	glutWireIcosahedron();
	glPopMatrix();
}