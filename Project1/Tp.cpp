#include "Tp.hpp"
#include <GL/glut.h>
#include <math.h>

tp::tp():Shape()
{
}

tp::tp(double x, double y, double z, double off, double d)
{
	this->a = x;
	this->b = y;
	this->h = z;
	this->off = off;
	this->d = d;
}

//tp::tp(double x, double y, double z, double off, double d);
//{
//	this->a = x;
//	this->b = y;
//	this->h = z;
//	this->off = off;
//	this->d = d;
//	/*this->x = x;
//	this->y = y;
//	this->z = z;*/
//	this->red = red_;
//	this->green = green_;
//	this->blue = blue_;
//	//	this->rotation = rotation;
//
//}

void tp::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();
	

	glBegin(GL_QUADS);

	//Front 

	//glColor3f(0.0f, 1.0f, 0.0f);
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
	//glVertex3d(-a/2 + off, h, d / 2);
	//glVertex3d(-a/2 , 0, d / 2);
	//glVertex3d(-a/2 +off, h, -d / 2);
	//glVertex3d(-a/2, 0, -d / 2);
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

double tp::getX()
{
	return x;
}

double tp::getY()
{
	return y;
}

double tp::getZ()
{
	return z;
}
