#ifndef CYLINDER_GL_H
#define CYLINDER_GL_H

#include "polygon_gl.h"

class CylinderGL : public PolygonGL
{
private:
	GLfloat r, h;
	int res;
public:
	CylinderGL();
	~CylinderGL();
	void render();
};

#endif
