#ifndef ICOSAHEDRON_GL_H
#define ICOSAHEDRON_GL_H

#include "polygon_gl.h"

class IcosahedronGL : public PolygonGL
{
public:
	IcosahedronGL();
	~IcosahedronGL();
	void render();
};

#endif

