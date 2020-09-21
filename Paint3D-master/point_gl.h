#ifndef POINT_GL_H
#define POINT_GL_H

#include "polygon_gl.h"

class PointGL : public PolygonGL
{
private:
	GLfloat x1, y1, z1;
public:
	PointGL();
	~PointGL();
	void points(GLfloat a, GLfloat b, GLfloat c);
	void render();
};

#endif
