#include "TriangularPrism.hpp"
#include <GL/glut.h>
#include <math.h>

triangular::triangular(): Shape()
{
}

triangular::triangular(double x, double y, double z, double theta) 
{
	this->a = x;
	this-> b = y;
	this-> d= z;
	this->theta = theta;
}


void triangular::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();
	
	//Front side
	glBegin(GL_TRIANGLES);      
	glVertex3d(a / 2, 0, -d / 2);								 
	glVertex3d(-a / 2 + b * cos(theta), b*sin(theta), -d / 2);
	glVertex3d(-a / 2, 0, -d / 2); 
	glEnd();

	//Back side 
	glBegin(GL_TRIANGLES);
	glVertex3d(-a/2,0,d/2);
	glVertex3d(a/2,0,d/2);
	glVertex3d(-a/2+b*cos(theta),b*sin(theta),d/2);

	glEnd();

	
	
	//Bottom face    
	glBegin(GL_QUADS);
	glVertex3d(-a/2, 0, d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(a/2,0, -d/2);
	glVertex3d(a/2, 0, d/2);
	glEnd();

	// Left side
	glBegin(GL_QUADS);
	glVertex3d(-a/2, 0,d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(-a/2 + b*cos(theta),b*sin(theta),-d/2 );
	glVertex3d(-a/2 + b*cos(theta),b*sin(theta),d/2);
	glEnd();

	// Right side
	glBegin(GL_QUADS);
	glVertex3d(-a/2+b*cos(theta), b*sin(theta), d/2);
	glVertex3d(-a/2+b*cos(theta), b*sin(theta), -d / 2);
	glVertex3d(a/2,0,-d/2);
	glVertex3d(a/2,0,d/2);
	

	glEnd();

glPopMatrix();


}


