#include "mywheel.hpp"
#include <GL/glut.h>
#include <math.h>

wheel::wheel()
{
}

wheel::wheel(double radius, double depth, double steering_, double rolling)
{

	this->depth = depth;
	this->radius = radius;
	
	
}

void wheel::draw() {

	/*glPushMatrix();
	circle::draw();
	triangular A(1.2*radius, 1.2*radius, height, theta);
	A.setPosition(x,y+radius/2,z);
	A.setColor(0.5,1,0.87);
	A.setRotation(rotation);
	A.draw();
	glPopMatrix();*/
}	