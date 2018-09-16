#include "rectangularprism.hpp"
#include <GL/glut.h>
#include <math.h>

rectangularprism::rectangularprism() : Shape()
{

}


rectangularprism::rectangularprism(double xl, double yl, double zl)
{
	this->lx = xl;
	this->ly = yl;
	this->lz = zl;
}

void rectangularprism::draw()
{

	

	
glPushMatrix();
	
	positionInGL();
	setColorInGL();
	
	glBegin(GL_QUADS);           

	//top
	glVertex3d(-getX() / 2, getY(), getZ() / 2);
	glVertex3d(-getX() / 2, getY(), -getZ() / 2);
	glVertex3d(getX() / 2, getY(), -getZ() / 2);
	glVertex3d(getX() / 2, getY(), getZ() / 2);
	glEnd();

	glBegin(GL_QUADS);
	// Bottom face
	glVertex3d(-getX() / 2, 0, getZ() / 2);
	glVertex3d(getX() / 2, 0, getZ() / 2);
	glVertex3d(getX() / 2, 0, -getZ() / 2);
	glVertex3d(-getX() / 2, 0, -getZ() / 2);
	glEnd();
	
	glBegin(GL_QUADS);
	// Front face 
	glVertex3d(getX() / 2, getY(), -getZ() / 2);
	glVertex3d(-getX() / 2, getY(), -getZ() / 2);
	glVertex3d(-getX() / 2, 0, -getZ() / 2);
	glVertex3d(getX() / 2, 0,- getZ() / 2);
	glEnd();

	glBegin(GL_QUADS);
	// Back face 
	glVertex3d(-getX() / 2, 0, getZ() / 2);
	glVertex3d(-getX() / 2, getY(), getZ() / 2);
	glVertex3d(getX() / 2, getY(), getZ() / 2);
	glVertex3d(getX() / 2, 0, getZ() / 2);
	glEnd();
	
	glBegin(GL_QUADS);
	// Left face 
	glVertex3d(-getX() / 2, getY(), -getZ() / 2);
	glVertex3d(-getX() / 2, getY(), getZ() / 2);
	glVertex3d(-getX() / 2, 0, getZ() / 2);
	glVertex3d(-getX() / 2, 0, -getZ() / 2);
	glEnd();

	glBegin(GL_QUADS);
	// Right face
	glVertex3d(getX() / 2, 0, getZ() / 2);
	glVertex3d(getX() / 2, getY(), getZ() / 2);
	glVertex3d(getX() / 2, getY(), -getZ() / 2);
	glVertex3d(getX() / 2, 0, -getZ() / 2);
	glEnd();
	glPopMatrix();
	
}


double rectangularprism::getX() {
	return lx;
 }

double rectangularprism::getY() {
	return ly;
}

double rectangularprism::getZ() {
	return lz;
}
