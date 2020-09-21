#ifndef OCTAHEDRON_GL_H
#define OCTAHEDRON_GL_H

#include "polygon_gl.h"

class OctahedronGL : public PolygonGL
{
public:
	OctahedronGL();
	~OctahedronGL();
	void render();
};

#endif

