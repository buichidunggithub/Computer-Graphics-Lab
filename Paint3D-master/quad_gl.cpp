#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "quad_gl.h"

QuadGL::QuadGL() : PolygonGL()
{
	GLfloat size = 1.f;
	this->x1 = -size / 2.f;
	this->y1 = -size / 2.f;
	this->z1 = 0.f;
	this->x2 = size / 2.f;
	this->y2 = -size / 2.f;
	this->z2 = 0.f;
	this->x3 = size / 2.f;
	this->y3 = size / 2.f;
	this->z3 = 0.f;
	this->x4 = -size / 2.f;
	this->y4 = size / 2.f;
	this->z4 = 0.f;

}
QuadGL::~QuadGL()
{

}
void QuadGL::render()
{
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->backFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	glBegin(GL_TRIANGLES);
	glVertex3f(this->x1, this->y1, this->z1);
	glVertex3f(this->x2, this->y2, this->z2);
	glVertex3f(this->x3, this->y3, this->z3);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x3, this->y3, this->z3);
	glVertex3f(this->x4, this->y4, this->z4);
	glVertex3f(this->x1, this->y1, this->z1);
	glEnd();
	glPopMatrix();
}