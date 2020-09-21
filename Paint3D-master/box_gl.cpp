#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "box_gl.h"

BoxGL::BoxGL() : PolygonGL()
{
	GLfloat size = 1.f;
	this->x1 = -size / 2.f;
	this->y1 = -size / 2.f;
	this->z1 = size / 2.f;
	this->x2 = size / 2.f;
	this->y2 = -size / 2.f;
	this->z2 = size / 2.f;
	this->x3 = size / 2.f;
	this->y3 = size / 2.f;
	this->z3 = size / 2.f;
	this->x4 = -size / 2.f;
	this->y4 = size / 2.f;
	this->z4 = size / 2.f;
	this->x21 = -size / 2.f;
	this->y21 = -size / 2.f;
	this->z21 = -size / 2.f;
	this->x22 = size / 2.f;
	this->y22 = -size / 2.f;
	this->z22 = -size / 2.f;
	this->x23 = size / 2.f;
	this->y23 = size / 2.f;
	this->z23 = -size / 2.f;
	this->x24 = -size / 2.f;
	this->y24 = size / 2.f;
	this->z24 = -size / 2.f;

}
BoxGL::~BoxGL()
{

}
void BoxGL::render()
{
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
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

	glBegin(GL_TRIANGLES);
	glVertex3f(this->x23, this->y23, this->z23);
	glVertex3f(this->x22, this->y22, this->z22);
	glVertex3f(this->x21, this->y21, this->z21);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x21, this->y21, this->z21);
	glVertex3f(this->x24, this->y24, this->z24);
	glVertex3f(this->x23, this->y23, this->z23);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(this->x2, this->y2, this->z2);
	glVertex3f(this->x22, this->y22, this->z22);
	glVertex3f(this->x23, this->y23, this->z23);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x23, this->y23, this->z23);
	glVertex3f(this->x3, this->y3, this->z3);
	glVertex3f(this->x2, this->y2, this->z2);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x1, this->y1, this->z1);
	glVertex3f(this->x21, this->y21, this->z21);
	glVertex3f(this->x24, this->y24, this->z24);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x24, this->y24, this->z24);
	glVertex3f(this->x4, this->y4, this->z4);
	glVertex3f(this->x1, this->y1, this->z1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(this->x1, this->y1, this->z1);
	glVertex3f(this->x21, this->y21, this->z21);
	glVertex3f(this->x2, this->y2, this->z2);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x2, this->y2, this->z2);
	glVertex3f(this->x22, this->y22, this->z22);
	glVertex3f(this->x21, this->y21, this->z21);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(this->x4, this->y4, this->z4);
	glVertex3f(this->x24, this->y24, this->z24);
	glVertex3f(this->x3, this->y3, this->z3);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(this->x3, this->y3, this->z3);
	glVertex3f(this->x23, this->y23, this->z23);
	glVertex3f(this->x24, this->y24, this->z24);
	glEnd();

	glPopMatrix();
}