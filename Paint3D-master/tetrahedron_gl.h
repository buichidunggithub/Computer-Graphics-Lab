#ifndef TETRAHEDRON_GL_H
#define TETRAHEDRON_GL_H

#include "polygon_gl.h"

class TetrahedronGL : public PolygonGL
{
public:
	TetrahedronGL();
	~TetrahedronGL();
	void render();
};

#endif
