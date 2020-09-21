#ifndef DISK_GL_H
#define DISK_GL_H

#include "polygon_gl.h"

class DiskGL : public PolygonGL
{
private:
	GLfloat r, h;
	int res;
public:
	DiskGL();
	~DiskGL();
	void render();
};

#endif
