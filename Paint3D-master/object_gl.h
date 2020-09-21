#ifndef OBJECT_GL_H
#define OBJECT_GL_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class ObjectGL
{
public:
	glm::mat4 m;
	GLfloat color[4];
public:
	ObjectGL();
	void setColor(GLfloat r, GLfloat g, GLfloat b);
	void scale(GLfloat sx, GLfloat sy, GLfloat sz);
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);
	void rotate(GLfloat angle, GLfloat tx, GLfloat ty, GLfloat tz);
	virtual void render() = 0;
};

#endif
