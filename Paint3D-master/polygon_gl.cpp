#include "polygon_gl.h"
#include "object_gl.h"

PolygonGL::PolygonGL() : ObjectGL()
{
	this->frontFaceMode = GL_LINE;
	this->backFaceMode = GL_LINE;
}
