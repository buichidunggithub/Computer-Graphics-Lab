#ifndef TRIANGLE_GL_H
#define TRIANGLE_GL_H

#include "polygon_gl.h"

class TriangleGL : public PolygonGL
{
private:
	GLfloat x1, y1, z1, x2, y2, z2, x3, y3, z3;
public:
	TriangleGL();
	~TriangleGL();
	void render();
};

#endif
