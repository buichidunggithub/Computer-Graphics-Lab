#ifndef TORUS_GL_H
#define TORUS_GL_H

#include "polygon_gl.h"

class TorusGL : public PolygonGL
{
private:
	GLfloat innerR, outerR, slices, stacks;
public:
	TorusGL();
	~TorusGL();
	void render();
};

#endif

