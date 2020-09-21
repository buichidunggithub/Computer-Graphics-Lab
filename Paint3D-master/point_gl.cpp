#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "point_gl.h"

PointGL::PointGL() : PolygonGL()
{
	this->x1 = 0.f;
	this->y1 = 0.f;
	this->z1 = 0.f;

}
PointGL::~PointGL()
{

}
void PointGL::points(GLfloat a, GLfloat b, GLfloat c)
{
	this->x1 = a;
	this->y1 = b;
	this->z1 = c;
}
void PointGL::render()
{
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->backFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();

	glBegin(GL_POINTS);
	glVertex3f(this->x1, this->y1, this->z1);
	glEnd();

	glPopMatrix();
}