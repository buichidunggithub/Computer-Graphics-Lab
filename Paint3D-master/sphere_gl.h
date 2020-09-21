#ifndef SPHERE_GL_H
#define SPHERE_GL_H

#include "polygon_gl.h"

class SphereGL : public PolygonGL
{
private:
	GLfloat r, slices, stacks;
public:
	SphereGL();
	~SphereGL();
	void render();
};

#endif
