#ifndef QUAD_GL_H
#define QUAD_GL_H

#include "polygon_gl.h"

class QuadGL : public PolygonGL
{
private:
	GLfloat x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
public:
	QuadGL();
	~QuadGL();
	void render();
};

#endif
