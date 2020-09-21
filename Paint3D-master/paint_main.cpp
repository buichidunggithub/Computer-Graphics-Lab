// hello_world_camera_main.cpp
// HelloWorld OpenGL con Cámara Virtual Interactiva

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <list>

#include "line_gl.h"
#include "triangle_gl.h"
#include "quad_gl.h"
#include "disk_gl.h"
#include "box_gl.h"
#include "cylinder_gl.h"
#include "cone_gl.h"
#include "sphere_gl.h"
#include "torus_gl.h"
#include "tetrahedron_gl.h"
#include "octahedron_gl.h"
#include "dodecahedro_gl.h"
#include "icosahedron_gl.h"
#include "teapot_gl.h"
#include "piramide_gl.h"
#include "point_gl.h"

using namespace std;

// Tamaño de la ventana
GLint width = 800;
GLint height = 600;

// Parámetros de la cámara virtual
GLint mouseButton = 0;
GLboolean mouseRotate = false;
GLboolean mouseZoom = false;
GLboolean mousePan = false;
GLint xClick = 0;
GLint yClick = 0;
GLint xAux = 0;
GLint yAux = 0;
GLfloat rotX = 0.f;
GLfloat rotY = 0.f;
GLfloat panX = 0.f;
GLfloat panY = 0.f;
GLfloat zoomZ = -10.f;

GLfloat rotax = 0.f;
GLfloat rotay = 0.f;
GLfloat rotaz = 0.f;
GLboolean paint = false;
GLfloat xx = 0;
GLfloat yy = 0;
GLfloat zz = 0;
GLfloat xx2 = 0;
GLfloat yy2 = 0;
GLfloat zz2 = 0;
GLboolean line = TRUE;
GLboolean transladar = FALSE;
GLboolean escalar = FALSE;
GLboolean dibujaline = FALSE;
GLboolean dibujapunto = FALSE;
GLboolean dibuja = TRUE;
int obj = 1;
int colfunc[3];
list<ObjectGL *> scene;
list<float> scenepointx;
list<float> scenepointy;
list<float> scenepointz;

GLint Lbuttons[6], Rbuttons[6], Tbuttons[5];
GLint window;



void init()
{
	colfunc[0] = 1;
	colfunc[1] = 0;
	colfunc[2] = 0;
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glColor3f(1.f, 1.f, 1.f);



}



// Función que se invoca cada vez que se redimensiona la ventana
// Función que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
	if (h == 0)
	{
		h = 1;
	}
	width = w;
	height = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);		// Transf. de Proyección en Perspectiva
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height); // Transf. de Viewport (mapeo al área de dibujo)

	GLfloat subh = height / 6;

	for (int i = 0; i < 6; i++) {
		glutSetWindow(Lbuttons[i]);
		glutPositionWindow(0, subh * i);
		glutReshapeWindow(subh, subh);
	}

	for (int i = 0; i < 6; i++) {
		glutSetWindow(Rbuttons[i]);
		glutPositionWindow(width - subh, subh * i);
		glutReshapeWindow(subh, subh);
	}

	GLfloat middle = width / 2;
	glutSetWindow(Tbuttons[0]);
	glutPositionWindow(middle - (subh / 2), 0);
	glutReshapeWindow(subh, subh);


	for (int i = 1; i < 3; i++) {
		glutSetWindow(Tbuttons[i]);
		glutPositionWindow(middle + (subh * i) - (subh / 2), 0);
		glutReshapeWindow(subh, subh);

		glutSetWindow(Tbuttons[i + 2]);
		glutPositionWindow(middle - (subh * i) - (subh / 2), 0);
		glutReshapeWindow(subh, subh);
	}


}

// Geometría sistema coordenado
void geomCoordSys(GLfloat size)
{
	// Eje X (Rojo)
	glColor3f(1., 0., 0.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(size, 0., 0.);
	glEnd();

	// Eje Y (Verde))
	glColor3f(0., 1., 0.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(0., size, 0.);
	glEnd();

	// Eje Z (Azul)
	glColor3f(0., 0., 1.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(0., 0., size);
	glEnd();
	glColor3f(1., 1., 1.);
}


void mainDisplay(GLint num) {

	GLenum face = GL_FRONT_AND_BACK; //GL_FRONT_AND_BACK;
	GLenum mode = GL_LINE;
	BoxGL *box = new BoxGL();
	TriangleGL *tri = new TriangleGL();
	CylinderGL *cyli = new CylinderGL();
	ConeGL *cone = new ConeGL();
	DiskGL *disk = new DiskGL();
	LineGL *line = new LineGL();
	QuadGL *quad = new QuadGL();
	SphereGL *sphere = new SphereGL();
	TorusGL *torus = new TorusGL();
	TetrahedronGL *tetra = new TetrahedronGL();
	OctahedronGL *octa = new OctahedronGL();
	DodecahedronGL *dode = new DodecahedronGL();
	IcosahedronGL *ico = new IcosahedronGL();
	TeapotGL *tea = new TeapotGL();
	PiramidedGL *piram = new PiramidedGL();
	switch (num) {
	case 2:
		sphere->frontFaceMode = face;
		sphere->backFaceMode = mode;
		scene.push_back(sphere);
		break;
	case 3:
		//box->frontFaceMode = face;
		//box->backFaceMode = mode;
		scene.push_back(box);
		break;
	case 4:
		torus->frontFaceMode = face;
		torus->backFaceMode = mode;
		scene.push_back(torus);
		break;
	case 5:
		tetra->frontFaceMode = face;
		tetra->backFaceMode = mode;
		scene.push_back(tetra);
		break;
	case 6:
		octa->frontFaceMode = face;
		octa->backFaceMode = mode;
		scene.push_back(octa);
		break;
	case 7:
		dode->frontFaceMode = face;
		dode->backFaceMode = mode;
		scene.push_back(dode);
		break;
	case 8:
		ico->frontFaceMode = face;
		ico->backFaceMode = mode;
		scene.push_back(ico);
		break;
	case 9:
		tea->frontFaceMode = face;
		tea->backFaceMode = mode;
		scene.push_back(tea);
		break;
	case 10:
		//cyli->frontFaceMode = face;
		//cyli->backFaceMode = mode;
		scene.push_back(cyli);
		break;
	case 11:
		disk->frontFaceMode = face;
		disk->backFaceMode = mode;
		scene.push_back(disk);
		break;
	case 12:
		cone->frontFaceMode = face;
		cone->backFaceMode = mode;
		scene.push_back(cone);
		break;
	case 13:
		tri->frontFaceMode = face;
		tri->backFaceMode = mode;
		scene.push_back(tri);
		break;
	case 15:
		quad->frontFaceMode = face;
		quad->backFaceMode = mode;
		scene.push_back(quad);
		break;
	case 17:
		scene.push_back(piram);
		break;
	default:
		break;
	}
	scenepointx.push_back(0);
	scenepointy.push_back(0);
	scenepointz.push_back(0);
}

void drawButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && dibuja && state == GLUT_DOWN)
	{
		cout << "figure= " << glutGetWindow() << endl;
		mainDisplay(glutGetWindow());
		obj = scene.size();
		glutPostRedisplay();
	}

}

void display(GLint num) {
	GLenum face = GL_FRONT_AND_BACK; //GL_FRONT_AND_BACK;
	GLenum mode = GL_LINE;
	BoxGL *box = new BoxGL();
	TriangleGL *tri = new TriangleGL();
	CylinderGL *cyli = new CylinderGL();
	ConeGL *cone = new ConeGL();
	DiskGL *disk = new DiskGL();
	LineGL *line = new LineGL();
	QuadGL *quad = new QuadGL();
	SphereGL *sphere = new SphereGL();
	TorusGL *torus = new TorusGL();
	TetrahedronGL *tetra = new TetrahedronGL();
	OctahedronGL *octa = new OctahedronGL();
	DodecahedronGL *dode = new DodecahedronGL();
	IcosahedronGL *ico = new IcosahedronGL();
	TeapotGL *tea = new TeapotGL();
	PiramidedGL *piram = new PiramidedGL();

	switch (num) {
	case 2:
		sphere->frontFaceMode = face;
		sphere->backFaceMode = mode;
		sphere->scale(2.f, 2.f, 2.f);
		sphere->render();
		break;
	case 3:
		box->frontFaceMode = face;
		box->backFaceMode = mode;
		box->scale(2.f, 2.f, 2.f);
		box->render();
		break;
	case 4:
		torus->frontFaceMode = face;
		torus->backFaceMode = mode;
		torus->scale(2.f, 2.f, 2.f);
		torus->render();
		break;
	case 5:
		tetra->frontFaceMode = face;
		tetra->backFaceMode = mode;
		tetra->scale(2.f, 2.f, 2.f);
		tetra->render();
		break;
	case 6:
		octa->frontFaceMode = face;
		octa->backFaceMode = mode;
		octa->scale(2.f, 2.f, 2.f);
		octa->render();
		break;
	case 7:
		dode->frontFaceMode = face;
		dode->backFaceMode = mode;
		dode->render();
		break;
	case 8:
		ico->frontFaceMode = face;
		ico->backFaceMode = mode;
		ico->scale(2.f, 2.f, 2.f);
		ico->render();
		break;
	case 9:
		tea->frontFaceMode = face;
		tea->backFaceMode = mode;
		tea->scale(1.5f, 1.5f, 1.5f);
		tea->render();
		break;
	case 10:
		cyli->frontFaceMode = face;
		cyli->backFaceMode = mode;
		cyli->scale(2.f, 2.f, 2.f);
		cyli->render();
		break;
	case 11:
		disk->frontFaceMode = face;
		disk->backFaceMode = mode;
		disk->scale(2.f, 2.f, 2.f);
		disk->render();
		break;
	case 12:
		cone->frontFaceMode = face;
		cone->backFaceMode = mode;
		cone->scale(2.f, 2.f, 2.f);
		cone->render();
		break;
	case 13:
		tri->frontFaceMode = face;
		tri->backFaceMode = mode;
		tri->scale(2.f, 2.f, 2.f);
		tri->render();
		break;
	case 15:
		quad->frontFaceMode = face;
		quad->backFaceMode = mode;
		quad->scale(2.f, 2.f, 2.f);
		quad->render();
		break;
	case 17:
		piram->scale(2.f, 2.f, 2.f);
		piram->render();
		break;
	default:
		break;
	}
}


void buttonDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Se limpian los buffers con el color activo definido por glClearColor
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(30, 1.0, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	GLenum face = GL_FRONT_AND_BACK; //GL_FRONT_AND_BACK;
	GLenum mode = GL_LINE;
	display(glutGetWindow());
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


// Función que se invoca cada vez que se dibuja
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Se limpian los buffers con el color activo definido por glClearColor

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Transformación de vista
	glTranslatef(panX, panY, zoomZ);
	glRotatef(rotY, 1.0, 0.0, 0.0);
	glRotatef(rotX, 0.0, 1.0, 0.0);
	GLenum face = GL_FRONT_AND_BACK; //GL_FRONT_AND_BACK;
	GLenum mode = GL_LINE;
	// Escena

	int n = obj;
	int i = 0;
	for (list<ObjectGL *>::iterator it = scene.begin(); it != scene.end(); it++, i++)
	{
		if (i == n - 1) {
			(*it)->setColor(colfunc[0], colfunc[1], colfunc[2]);
		}
		else
		{
			(*it)->setColor(1, 1, 1);
		}
	}
	for (list<ObjectGL *>::iterator it = scene.begin(); it != scene.end(); it++)
	{
		(*it)->render();
	}
	//piramide(1, 2, 2, face, mode);


	glutSwapBuffers();			// Se intercambian buffers
}


#define PI 3.14159265
void moveobj(int x, int y) {
	float xa = (-(x - (width / 2)) / (1350 / zoomZ));
	float ya = ((y - (height / 2)) / (1350 / zoomZ));
	float za = 0;
	ObjectGL *a = scene.front();
	int n = obj;
	int i = 0;
	for (list<ObjectGL *>::iterator it = scene.begin(); i < n && it != scene.end(); it++, i++)
	{
		a = (*it);
	}
	xx = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
	yy = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
	zz = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));
	float dx, dy, dz;
	i = 0;
	for (list<float>::iterator it = scenepointx.begin(); i < n && it != scenepointx.end(); it++, i++)
	{
		dx = (*it);
	}
	i = 0;
	for (list<float>::iterator it = scenepointy.begin(); i < n && it != scenepointy.end(); it++, i++)
	{
		dy = (*it);
	}
	i = 0;
	for (list<float>::iterator it = scenepointz.begin(); i < n && it != scenepointz.end(); it++, i++)
	{
		dz = (*it);
	}
	float tx = xx - dx;
	float ty = yy - dy;
	float tz = zz - dz;
	a->translate(tx, ty, tz);
	i = 0;
	for (list<float>::iterator it = scenepointx.begin(); i < n && it != scenepointx.end(); it++, i++)
	{
		if (i == n - 1) {
			(*it) = xx;
		}
	}
	i = 0;
	for (list<float>::iterator it = scenepointy.begin(); i < n && it != scenepointy.end(); it++, i++)
	{
		if (i == n - 1) {
			(*it) = yy;
		}
	}
	i = 0;
	for (list<float>::iterator it = scenepointz.begin(); i < n && it != scenepointz.end(); it++, i++)
	{
		if (i == n - 1) {
			(*it) = zz;
		}
	}
}

void scaleobj(int x, int y) {
	float xa = (-(x - (width / 2)) / (1350 / zoomZ));
	float ya = ((y - (height / 2)) / (1350 / zoomZ));
	float za = 0;
	ObjectGL *a = scene.front();
	int n = obj;
	int i = 0;
	for (list<ObjectGL *>::iterator it = scene.begin(); i < n && it != scene.end(); it++, i++)
	{
		a = (*it);
	}
	float dx, dy, dz;
	if (line) {
		xx = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		yy = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		zz = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));

		line = FALSE;
	}
	else {
		xx2 = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		yy2 = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		zz2 = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));

		line = TRUE;
	}

	float tx = 1 + xx2 - xx;
	float ty = 1 + yy2 - yy;
	float tz = 1 + zz2 - zz;
	a->scale(tx, ty, tz);
}


void rotarobj(int x, int y) {
	ObjectGL *a = scene.front();
	int n = obj;
	int i = 0;
	for (list<ObjectGL *>::iterator it = scene.begin(); i < n && it != scene.end(); it++, i++)
	{
		a = (*it);
	}

	a->rotate(x * 3, 1, 0, 0);
	a->rotate(y * 3, 0, 1, 0);
}

void paintline(int x, int y) {
	float xa = (-(x - (width / 2)) / (1350 / zoomZ));
	float ya = ((y - (height / 2)) / (1350 / zoomZ));
	float za = 0;
	if (line) {
		xx = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		yy = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		zz = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));

		line = FALSE;
	}
	else {
		xx2 = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		yy2 = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
		zz2 = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));

		line = TRUE;
		LineGL *a = new LineGL();
		a->points(xx, yy, zz, xx2, yy2, zz2);

		scene.push_back(a);

		scenepointx.push_back(0);
		scenepointy.push_back(0);
		scenepointz.push_back(0);
	}
}

void paintpoint(int x, int y) {
	float xa = (-(x - (width / 2)) / (1350 / zoomZ));
	float ya = ((y - (height / 2)) / (1350 / zoomZ));
	float za = 0;
	xx = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
	yy = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
	zz = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));
	PointGL *a = new PointGL();
	a->points(xx, yy, zz);

	scene.push_back(a);

	scenepointx.push_back(0);
	scenepointy.push_back(0);
	scenepointz.push_back(0);

}

void keyboard(unsigned char key, int x, int y) {
	if (key == '+')
	{
		obj++;
		if (scene.size()<obj) {
			obj = 1;
		}
	}
	if (key == '-')
	{
		if (obj>1)
		{
			obj--;
		}
		else {
			obj = scene.size();
		}
	}
	if (key == 's' || key == 'S')
	{
		colfunc[0] = 0;
		colfunc[1] = 1;
		colfunc[2] = 1;
		dibujaline = FALSE;
		dibuja = FALSE;
		dibujapunto = FALSE;
		transladar = FALSE;
		escalar = TRUE;
		cout << "KEY= " << key << endl;
	}
	if (key == 't' || key == 'T')
	{
		colfunc[0] = 0;
		colfunc[1] = 1;
		colfunc[2] = 0;
		dibujaline = FALSE;
		dibuja = FALSE;
		dibujapunto = FALSE;
		transladar = TRUE;
		escalar = FALSE;
		cout << "KEY= " << key << endl;
	}
	if (key == 'P' || key == 'p')
	{
		dibujapunto = TRUE;
		dibujaline = FALSE;
		dibuja = FALSE;
		transladar = FALSE;
		escalar = FALSE;
		colfunc[0] = 1;
		colfunc[1] = 1;
		colfunc[2] = 1;
		cout << "KEY= " << key << endl;
	}
	if (key == 'l' || key == 'L')
	{
		dibujaline = TRUE;
		dibujapunto = FALSE;
		transladar = FALSE;
		dibuja = FALSE;
		escalar = FALSE;
		colfunc[0] = 1;
		colfunc[1] = 1;
		colfunc[2] = 1;
		cout << "KEY= " << key << endl;
	}
	if (key == 'd' || key == 'D')
	{
		dibujaline = FALSE;
		dibujapunto = FALSE;
		transladar = FALSE;
		dibuja = TRUE;
		escalar = FALSE;
		colfunc[0] = 1;
		colfunc[1] = 0;
		colfunc[2] = 0;
		cout << "KEY= " << key << endl;
	}
	cout << "obj= " << obj << endl;

	glutPostRedisplay();
	cout << " " << endl;
}
void specialkeyboard(int key, int x, int y) {
	if (key == 100) //left
	{
		cout << "KEY= " << key << endl;
		rotarobj(0, -2);
	}
	else if (key == 101) //top
	{
		cout << "KEY= " << key << endl;
		rotarobj(-2, 0);
	}
	else if (key == 102) //right
	{
		cout << "KEY= " << key << endl;
		rotarobj(0, 2);
	}
	else if (key == 103) //down
	{
		cout << "KEY= " << key << endl;
		rotarobj(2, 0);
	}
	glutPostRedisplay();
}



#define PI 3.14159265
void mouse(int button, int state, int x, int y)
{
	float xa = -(x - (width / 2)) / (1350 / zoomZ);
	float ya = (y - (height / 2)) / (1350 / zoomZ);
	//float za = (y - (height / 2)) / (1350 / zoomZ);
	mouseButton = button;
	mouseRotate = false;
	mouseZoom = false;
	mousePan = false;
	xClick = x;
	yClick = y;
	if (button == GLUT_LEFT_BUTTON)
	{
		mouseRotate = true;
		xAux = rotX;
		yAux = rotY;
		if (paint) {

		}
		else {

		}

	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN) {
			if (dibujaline)
			{
				paintline(x, y);
			}
			if (dibujapunto) {
				paintpoint(x, y);
				cout << "Puntos" << x << endl;
			}
			//paintline(x,y);
		}

		//SCALEOBJ
		if (escalar)
		{
			if (state == GLUT_DOWN) {
				//paintline(x,y);

				float xa = (-(x - (width / 2)) / (1350 / zoomZ));
				float ya = ((y - (height / 2)) / (1350 / zoomZ));
				float za = 0;
				xx = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
				yy = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
				zz = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));
				xx2 = ((xa)*(cos(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((ya)*(cos(rotay * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotay * PI / 180.0))*(cos(rotaz * PI / 180.0)));
				yy2 = ((ya)*(cos(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotaz * PI / 180.0))) + ((za)*(sin(rotax * PI / 180.0))*(cos(rotaz * PI / 180.0)));
				zz2 = ((za)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((xa)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + (-(ya)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));
			}
			scaleobj(x, y);
		}

		glutPostRedisplay();
		//mouseZoom = true;
		//xAux = zoomZ;
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		mousePan = true;
		xAux = panX;
		yAux = panY;
	}
}

void mouseMotion(int x, int y)
{
	if (mouseButton == GLUT_RIGHT_BUTTON) {
		if (transladar)
		{
			moveobj(x, y);
		}


	}

	if (mouseRotate == true)
	{
		if (mouseButton == GLUT_LEFT_BUTTON)
		{
			if ((x - xClick + xAux) > 360.0)
			{
				xAux = xAux - 360.0;
			}
			if ((x - xClick + xAux) < 0.0)
			{
				xAux = xAux + 360.0;
			}
			if ((y - yClick + yAux) > 360.0)
			{
				yAux = yAux - 360.0;
			}
			if ((y - yClick + yAux) < 0.0)
			{
				yAux = yAux + 360.0;
			}
			rotX = x - xClick + xAux;
			rotY = y - yClick + yAux;
			rotax = rotY;
			rotay = rotX;
			rotaz = ((0)*(cos(rotax * PI / 180.0))*(cos(rotay * PI / 180.0))) + ((rotY)*(cos(rotax * PI / 180.0))*(sin(rotay * PI / 180.0))) + ((rotX)*(sin(rotax * PI / 180.0))*(cos(rotay * PI / 180.0)));
			rotaz = (cos(rotax * PI / 180.0));
			rotaz = 0;
		}
	}
	else if (mouseZoom == true)
	{
		if (mouseButton == GLUT_RIGHT_BUTTON)
		{
			zoomZ = ((x - xClick) / 10.0) + xAux;
		}
	}
	else if (mousePan == true)
	{
		if (mouseButton == GLUT_MIDDLE_BUTTON)
		{
			panX = ((x - xClick) / 63.0) + xAux;
			panY = ((y - yClick) / (-63.0)) + yAux;
		}
	}
	glutPostRedisplay();
}

int main(GLint argc, GLchar **argv)
{
	// 1. Se crea una ventana y un contexto OpenGL usando GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	window = glutCreateWindow("Paint 3D");

	// 1.2 Se definen las funciones callback para el manejo de eventos
	glutReshapeFunc(resize);
	glutDisplayFunc(render);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeyboard);

	Lbuttons[0] = glutCreateSubWindow(window, 0, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Lbuttons[1] = glutCreateSubWindow(window, 0, 100, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Lbuttons[2] = glutCreateSubWindow(window, 0, 200, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Lbuttons[3] = glutCreateSubWindow(window, 0, 300, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Lbuttons[4] = glutCreateSubWindow(window, 0, 400, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Lbuttons[5] = glutCreateSubWindow(window, 0, 500, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Rbuttons[0] = glutCreateSubWindow(window, width - 100, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Rbuttons[1] = glutCreateSubWindow(window, width - 100, 100, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Rbuttons[2] = glutCreateSubWindow(window, width - 100, 200, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Rbuttons[3] = glutCreateSubWindow(window, width - 100, 300, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Rbuttons[4] = glutCreateSubWindow(window, width - 100, 400, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Rbuttons[5] = glutCreateSubWindow(window, width - 100, 500, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	GLfloat middle = width / 2;

	Tbuttons[0] = glutCreateSubWindow(window, middle - 250, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Tbuttons[1] = glutCreateSubWindow(window, middle - 150, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Tbuttons[2] = glutCreateSubWindow(window, middle - 50, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Tbuttons[3] = glutCreateSubWindow(window, middle + 50, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	Tbuttons[4] = glutCreateSubWindow(window, middle + 150, 0, 100, 100);
	glutDisplayFunc(buttonDisplay);
	glutMouseFunc(drawButton);

	// 2. Se direcciona a las funciones correctas del API de OpenGL
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW Error");
		return false;
	}

	// 3. Se inicializa el contexto de OpenGL y la geometría de la escena
	init();

	// 4. Se inicia el ciclo de escucha de eventos
	glutMainLoop();
	return 0;
}