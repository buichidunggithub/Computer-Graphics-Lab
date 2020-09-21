#include "object_gl.h"

ObjectGL::ObjectGL()
{
	this->color[0] = 1.f;
	this->color[1] = 1.f;
	this->color[2] = 1.f;
	this->color[3] = 1.f;

}
void ObjectGL::setColor(GLfloat r, GLfloat g, GLfloat b){
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
}

void ObjectGL::scale(GLfloat sx, GLfloat sy, GLfloat sz){
	this->m = glm::scale(this->m, glm::vec3(sx, sy, sz));
}

void ObjectGL::translate(GLfloat tx, GLfloat ty, GLfloat tz){
	this->m = glm::translate(this->m, glm::vec3(tx, ty, tz));
}

void ObjectGL::rotate(GLfloat angle, GLfloat tx, GLfloat ty, GLfloat tz){
	this->m = glm::rotate(this->m, glm::radians(angle), glm::vec3(tx, ty, tz));
}

