#ifndef POLYGON_GL_H
#define POLYGON_GL_H

#include "object_gl.h"

class PolygonGL : public ObjectGL
{
public:
	int frontFaceMode, backFaceMode;
public:
	PolygonGL();
	void render() = 0;
};

#endif
