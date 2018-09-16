#include "trapezoidalprism.hpp"
#include <math.h>
#include <GL/glut.h>


trapezoidalprism::trapezoidalprism(): Shape()
{
}

trapezoidalprism::trapezoidalprism(double alen, double blen, double height, double aoff, double depth)
{
	this->a = alen;
	this->b = blen;
	this->h = height;
	this->off = aoff;
	this->d = depth;
}


void trapezoidalprism::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();
	

	glBegin(GL_QUADS);

	//Front 
	glVertex3d(-a/2+off, h, -d / 2);
	glVertex3d(-a/2, 0, -d / 2);
	glVertex3d(a/2, 0, -d / 2);
	glVertex3d(-a / 2+off+b, h, -d / 2);
	glEnd();

	glBegin(GL_QUADS);

	// Back
	glVertex3d(-a/2 + off, h, d / 2);
	glVertex3d(-a/2, 0, d / 2);
	glVertex3d(a/2,0, d/2);
	glVertex3d(-a/2+off+b, h, d/2);
	glEnd();

	glBegin(GL_QUADS);
	// Top
	glVertex3d(-a/2+off, h, d / 2);
	glVertex3d(-a/2+off+b, h, d/2);
	glVertex3d(-a/2+off+b, h, -d / 2);
	glVertex3d(-a/2+off, h, -d/2);
	glEnd();

	glBegin(GL_QUADS);
	// Bottom
	glVertex3d(-a/2, 0, d /2);
	glVertex3d(-a/2, 0, -d / 2);
	glVertex3d(a/2, 0, -d / 2);
	glVertex3d(a/2, 0, d / 2);
	glEnd();

	glBegin(GL_QUADS);
	// Left
	glVertex3d(-a/2 + off, h, d/2);
	glVertex3d(-a/2, 0, d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(-a/2 +off, h, -d/2);
	glEnd();

	glBegin(GL_QUADS);
	// Right
	glVertex3d(a/2, 0, d/2); 
	glVertex3d(-a/2 + off + b, h, d/2);
	glVertex3d(-a/2 +off + b, h, -d/2);
	glVertex3d(a/2,0, -d/2);

	glEnd();

	glPopMatrix();
}

double trapezoidalprism::getX()
{
	return x;
}

double trapezoidalprism::getY()
{
	return y;
}

double trapezoidalprism::getZ()
{
	return z;
}
