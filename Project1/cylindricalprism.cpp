#include "cylindricalprism.hpp"
#include <math.h>
#include <GL/glut.h>
#include "Vehicle.hpp"
#include "myVehicle.hpp"

#define PI 3.14159265358979323846

cylindricalprism::cylindricalprism():Shape()
{

}

cylindricalprism::cylindricalprism(double radius, double depth, bool steer_, bool roll_)
{
	this->radius = radius;
	this->depth = depth;
	this->steering = steer_;
	this->rolling = roll_;
}

void cylindricalprism::draw()
{	
	glPushMatrix();
	positionInGL();
	setColorInGL();

	glTranslated(0, radius, 0);
	static GLUquadric *cylinder = gluNewQuadric();
	gluCylinder(cylinder, radius, radius, depth, 100, 10);
	gluDisk(cylinder, 0, radius, 100, 10 );
	glTranslated(0, 0, depth);
	gluDisk(cylinder, 0, radius, 100, 10);
	glPopMatrix();

	glEnd();
}

