#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "dodecahedro_gl.h"

DodecahedronGL::DodecahedronGL() : PolygonGL() {

}

DodecahedronGL::~DodecahedronGL() {

}

void DodecahedronGL::render() {
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	glutWireDodecahedron();
	glPopMatrix();
}