#include "TriangularPrism.hpp"
#include <GL/glut.h>
#include <math.h>

triangular::triangular(): Shape()
{
}

triangular::triangular(double x, double y, double z, double theta) //:Shape(x, y, z)
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
	//glBegin(GL_QUADS);	
	
	//Front side
	glBegin(GL_TRIANGLES);      
	glVertex3d(a / 2, 0, -d / 2);								 
	glVertex3d(-a / 2 + b * cos(theta), b*sin(theta), -d / 2);
	glVertex3d(-a / 2, 0, -d / 2); 


	//Back side 
	glVertex3d(-a/2,0,d/2);
	glVertex3d(a/2,0,d/2);
	glVertex3d(-a/2+b*cos(theta),b*sin(theta),d/2);

		glEnd();

	glBegin(GL_QUADS);
	
	//Bottom face    
	
	glVertex3d(-a/2, 0, d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(a/2,0, -d/2);
	glVertex3d(a/2, 0, d/2);
		

	// Left side
	glVertex3d(-a/2, 0,d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(-a/2 + b*cos(theta),b*sin(theta),-d/2 );
	glVertex3d(-a/2 + b*cos(theta),b*sin(theta),d/2);

	// Right side
	glVertex3d(-a/2+b*cos(theta), b*sin(theta), d/2);
	glVertex3d(-a/2+b*cos(theta), b*sin(theta), -d / 2);
	glVertex3d(a/2,0,-d/2);
	glVertex3d(a/2,0,d/2);
	

	glEnd();

glPopMatrix();


}


