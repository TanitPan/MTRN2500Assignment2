#include "circle.hpp"
#include <GL/glut.h>
#include <math.h>
#include "Vehicle.hpp"
#include "math.h"
#include "myVehicle.hpp"
#define PI 3.14159265358979323846

circle::circle():Shape()
{

}

circle::circle(double radius, double depth, double wheel)
{
	this->radius = radius;
	this->depth = depth;
	this->wheel = wheel;

}

//circle::circle (double bRadius, double tRadius, double height, int slices, int stack, double InRadius, double OutRadius, int loop)
//{
//	this->bRadius = bRadius;
//	this->tRadius = tRadius; 
//	this->height = height;
//	this->slices = slices;
//	this->stack = stack;
//	this->InRadius = InRadius;
//	this->OutRadius = OutRadius;
//	this->loop = loop;
//
//}	



void circle::draw()
{
	double spinspeed;
	//glTranslated(x, y, z);
	
	glPushMatrix();
	positionInGL();
	setColorInGL();

	if (wheel != 0) {
		//spinspeed += (PI*turning) / radius;
		glRotatef(-steering, 0, 1, 0);
		//glRotatef(-spinspeed, 0, 0, 1);
	}

	//setPosition(0,0,0);

	//glColor3f(1,0,0);

	static GLUquadric *cylinder = gluNewQuadric();
	gluCylinder(cylinder, radius, radius, depth, 100, 10);
	gluDisk(cylinder, 0, radius, 100, 10 );
	glTranslated(0, 0, depth);
	gluDisk(cylinder, 0, radius, 100, 10);

	glPopMatrix();

	/*
	double p, q, theta = 0.0;
	glColor3f(red, green, blue);
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
	do
	{
		p = x + Radius * cos(theta);
		q = y + Radius * sin(theta);
		glVertex2f(p, q);
		theta += 0.005;
	} while (theta < 2 * 3.15);*/
	glEnd();
}
//
//void circle::move(double x, double y)
//{
//	Shape::move(x, y);
//}
