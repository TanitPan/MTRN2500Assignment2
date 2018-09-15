#include "cylindricalprism.hpp"
#include <GL/glut.h>
#include <math.h>
#include "Vehicle.hpp"
#include "math.h"
#include "myVehicle.hpp"
#define PI 3.14159265358979323846

cylindricalprism::cylindricalprism():Shape()
{

}

cylindricalprism::cylindricalprism(double radius, double depth, bool steer_, bool roll_)
{
	this->radius = radius;
	this->depth = depth;
	//this->wheel = wheel;
	this->steering = steer_;
	this->rolling = roll_;

}


double spinspeed;

void cylindricalprism::draw()
{
	
	//glTranslated(x, y, z);
	
	glPushMatrix();
	positionInGL();
	setColorInGL();

	if (wheel != 0) {
		//spinspeed += (PI*turning) / radius;
		glRotatef(-rotation, 0, 1, 0);
		std::cout << rotation << std::endl;
		//glRotatef(-spinspeed, 0, 0, 1);
	}

	

	static GLUquadric *cylinder = gluNewQuadric();
	gluCylinder(cylinder, radius, radius, depth, 100, 10);
	gluDisk(cylinder, 0, radius, 100, 10 );
	glTranslated(0, 0, depth);
	gluDisk(cylinder, 0, radius, 100, 10);

	glPopMatrix();

	
	glEnd();
}
//
//void cylindricalprism::move(double x, double y)
//{
//	Shape::move(x, y);
//}
