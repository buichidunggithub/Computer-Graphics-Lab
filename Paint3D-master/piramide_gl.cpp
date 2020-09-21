#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "piramide_gl.h"

PiramidedGL::PiramidedGL() : PolygonGL()
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
	this->x5 = -size / 2.f;
	this->y5 = size / 2.f;
	this->z5 = size / 2.f;
	

}
PiramidedGL::~PiramidedGL()
{

}
void PiramidedGL::render()
{
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	glPushMatrix();
	glTranslatef(0.f, -.5f, .0f);
	glPushMatrix();
	
	glPopMatrix();
	glBegin(GL_TRIANGLES);//frente
	glVertex3f(-0.5f, 0.f, 0.5f);
	glVertex3f(0.5f, 0.f, 0.5f);
	glVertex3f(0.f, 1.0f, 0.f);
	glEnd();
	glBegin(GL_TRIANGLES);//derecha
	glVertex3f(0.5f, 0.f, 0.5f);
	glVertex3f(0.5f, 0.f, -0.5f);
	glVertex3f(0.f, 1.0f, 0.f);
	glEnd();
	glBegin(GL_TRIANGLES);//atras
	glVertex3f(0.5f, 0.f, -0.5f);
	glVertex3f(-0.5f, 0.f, -0.5f);
	glVertex3f(0.f, 1.0f, 0.f);
	glEnd();
	glBegin(GL_TRIANGLES);//izquierda
	glVertex3f(-0.5f, 0.f, -0.5f);
	glVertex3f(-0.5f, 0.f, 0.5f);
	glVertex3f(0.f, 1.0f, 0.f);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}