#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "sphere_gl.h"

SphereGL::SphereGL() : PolygonGL() {
	this->r = 1.f;
	this->stacks = 20.f;
	this->slices = 20.f;
}

SphereGL::~SphereGL(){

}


void SphereGL::render() {
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	glutWireSphere(this->r, this->stacks, this->slices);
	glPopMatrix();
}