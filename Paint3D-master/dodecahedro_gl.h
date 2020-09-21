#ifndef DODECAHEDRON_GL_H
#define DODECAHEDRON_GL_H

#include "polygon_gl.h"

class DodecahedronGL : public PolygonGL
{
public:
	DodecahedronGL();
	~DodecahedronGL();
	void render();
};

#endif

