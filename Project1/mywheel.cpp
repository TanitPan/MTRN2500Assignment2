#include "mywheel.hpp"
#include <GL/glut.h>
#include <math.h>

mywheel::mywheel()
{
}

mywheel::mywheel(double radius, double depth, bool steering_, bool turning_)
{

	this->depth = depth;
	this->radius = radius;
	this->rolling = 0;

	//need more work to be done
	steering = steering_;
	turning = turning_;
	
}

void mywheel::draw() {

	glPushMatrix();
	cylindricalprism::draw();
	drawCross(radius, radius * 0.1, depth *1.1);
	glPopMatrix();

}	


void mywheel::setRolling(double _rolling)
{
	rolling = _rolling;
}

void mywheel::drawCross(float xl, float yl, float zl) {
	glPushMatrix();

	positionInGL();

	glTranslated(0, 0, depth/2);
	if (rolling != 0) {
		glRotated(-rolling, 0, 0, 1);
	}
	glColor3f(0.2, 0, 0.9);


	//Front Face
	glBegin(GL_QUADS);
	glVertex3f(-xl / 2.0, 0.0, -zl / 2.0);
	glVertex3f(-xl / 2.0, yl, -zl / 2.0);
	glVertex3f(xl / 2.0, yl, -zl / 2.0);
	glVertex3f(xl / 2.0, 0.0, -zl / 2.0);
	glEnd();

	//Back Face
	glBegin(GL_QUADS);
	glVertex3f(-xl / 2.0, 0.0, zl / 2.0);
	glVertex3f(-xl / 2.0, yl, zl / 2.0);
	glVertex3f(xl / 2.0, yl, zl / 2.0);
	glVertex3f(xl / 2.0, 0.0, zl / 2.0);
	glEnd();

	//Bottom Face
	glBegin(GL_QUADS);
	glVertex3f(-xl / 2.0, 0.0, zl / 2.0);
	glVertex3f(-xl / 2.0, 0.0, -zl / 2.0);
	glVertex3f(xl / 2.0, 0.0, -zl / 2.0);
	glVertex3f(xl / 2.0, 0.0, zl / 2.0);
	glEnd();

	//Top Face
	glBegin(GL_QUADS);
	glVertex3f(-xl / 2.0, yl, zl / 2.0);
	glVertex3f(-xl / 2.0, yl, -zl / 2.0);
	glVertex3f(xl / 2.0, yl, -zl / 2.0);
	glVertex3f(xl / 2.0, yl, zl / 2.0);
	glEnd();

	//Left Face
	glBegin(GL_QUADS);
	glVertex3f(-xl / 2.0, yl, -zl / 2.0);
	glVertex3f(-xl / 2.0, yl, zl / 2.0);
	glVertex3f(-xl / 2.0, 0.0, zl / 2.0);
	glVertex3f(-xl / 2.0, 0.0, -zl / 2.0);
	glEnd();

	//Right Face
	glBegin(GL_QUADS);
	glVertex3f(xl / 2.0, yl, -zl / 2.0);
	glVertex3f(xl / 2.0, yl, zl / 2.0);
	glVertex3f(xl / 2.0, 0.0, zl / 2.0);
	glVertex3f(xl / 2.0, 0.0, -zl / 2.0);
	glEnd();

	glFlush();
	glPopMatrix();
}
