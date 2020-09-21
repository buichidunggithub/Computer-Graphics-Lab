#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "line_gl.h"

LineGL::LineGL() : PolygonGL()
{
	this->x1 = 0.f;
	this->y1 = 0.f;
	this->z1 = 0.f;
	this->x2 = 0.f;
	this->y2 = 0.f;
	this->z2 = 0.f;

}
LineGL::~LineGL()
{

}
void LineGL::points(GLfloat a, GLfloat b, GLfloat c, GLfloat d, GLfloat e, GLfloat f)
{
	this->x1 = a;
	this->y1 = b;
	this->z1 = c;
	this->x2 = d;
	this->y2 = e;
	this->z2 = f;
}
void LineGL::render()
{
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->backFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();

	glBegin(GL_LINES);
	glVertex3f(this->x1, this->y1, this->z1);
	glVertex3f(this->x2, this->y2, this->z2);
	glEnd();

	glPopMatrix();
}