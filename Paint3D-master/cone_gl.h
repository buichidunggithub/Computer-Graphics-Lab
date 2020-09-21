#ifndef CONE_GL_H
#define CONE_GL_H

#include "polygon_gl.h"

class ConeGL : public PolygonGL
{
private:
	GLfloat x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x21, y21, z21, x22, y22, z22, x23, y23, z23, x24, y24, z24;
public:
	ConeGL();
	~ConeGL();
	void render();
};

#endif
