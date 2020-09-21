#ifndef PIRAMIDE_GL_H
#define PIRAMIDE_GL_H

#include "polygon_gl.h"

class PiramidedGL : public PolygonGL
{
private:
	GLfloat x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5;
public:
	PiramidedGL();
	~PiramidedGL();
	void render();
};

#endif
