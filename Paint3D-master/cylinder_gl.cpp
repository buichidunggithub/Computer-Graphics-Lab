#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "cylinder_gl.h"

CylinderGL::CylinderGL() : PolygonGL()
{
	GLfloat size = 1.f;
	this->r = size / 2.f;
	this->h = size;
	this->res = 25;

}
CylinderGL::~CylinderGL()
{

}
void CylinderGL::render()
{
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->frontFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	int num_segments = this->res;
	for (int ii = 0; ii < num_segments; ii++){
		glBegin(GL_TRIANGLES);
		glVertex3f(0, 0, 0.f);
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
		float x = this->r * cosf(theta);
		float y = this->r * sinf(theta);
		glVertex3f(x, 0.f, y);
		theta = 2.0f * 3.1415926f * float(ii + 1) / float(num_segments);
		x = this->r * cosf(theta);
		y = this->r * sinf(theta);
		glVertex3f(x, 0.f, y);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3f(0, this->h, 0.f);
		theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
		x = this->r * cosf(theta);
		y = this->r * sinf(theta);
		glVertex3f(x, this->h, y);
		theta = 2.0f * 3.1415926f * float(ii + 1) / float(num_segments);
		x = this->r * cosf(theta);
		y = this->r * sinf(theta);
		glVertex3f(x, this->h, y);
		glEnd();

		glBegin(GL_QUADS);
		theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
		x = this->r * cosf(theta);
		y = this->r * sinf(theta);
		glVertex3f(x, 0.f, y);
		glVertex3f(x , this -> h, y );
		theta = 2.0f * 3.1415926f * float(ii + 1) / float(num_segments);
		x = this->r * cosf(theta);
		y = this->r * sinf(theta);
		glVertex3f(x, this->h, y);
		glVertex3f(x, 0.f, y);
		glEnd();
	}

	glPopMatrix();
}