#ifndef TEAPOT_GL_H
#define TEAPOT_GL_H

#include "polygon_gl.h"

class TeapotGL : public PolygonGL
{
private:
	GLfloat size;
public:
	TeapotGL();
	~TeapotGL();
	void render();
};

#endif

