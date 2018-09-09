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

//triangular::triangular(double x, double y, double z, double theta, double red_, double green_, double blue_): Shape(x, y, z)
//{	
//	
//	this-> a= x;
//	this-> b = y;
//	this-> d= z;
//	this->theta = theta;
//	/*this->x = x;
//	this->y = y;
//	this->z = z;*/
//	this->red = red_;
//	this->green = green_;
//	this->blue = blue_;
////	this->rotation = rotation;
//
//
//}

void triangular::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();
	//glBegin(GL_QUADS);	
	
	//Front side
	glBegin(GL_TRIANGLES);      
	 // Begin drawing the color cube with 6 quads
	glVertex3d(a / 2, 0, -d / 2);								  //top
	glVertex3d(a / 2 - b * cos(theta), b*sin(theta), -d / 2);
	glVertex3d(-a / 2, 0, -d / 2); 


	//Back side 
	glVertex3d(-a/2,0,d/2);
	glVertex3d(a/2,0,d/2);
	glVertex3d(a/2-b*cos(theta),b*sin(theta),d/2);

		glEnd();

	glBegin(GL_QUADS);
	
	//Bottom face    
	
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3d(-a/2, 0, d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(a/2,0, -d/2);
	glVertex3d(a/2, 0, d/2);
		

	// Left side
	glVertex3d(-a/2, 0,d/2);
	glVertex3d(-a/2, 0, -d/2);
	glVertex3d(a/2 -b*cos(theta),b*sin(theta),-d/2 );
	glVertex3d(a/2-b*cos(theta),b*sin(theta),d/2);

	// Right side
	glVertex3d(a/2-b*cos(theta), b*sin(theta), d/2);
	glVertex3d(a/2-b*cos(theta), b*sin(theta), -d / 2);
	glVertex3d(a/2,0,-d/2);
	glVertex3d(a/2,0,d/2);
	

	glEnd();

glPopMatrix();


}


//double triangular::getX() {
//	return x;
//}
//
//double triangular::getY() {
//	return y;
//}
//
//double triangular::getZ() {
//	return z;
//}


//
//void triangular::setX(double x_) {
//	x = x_;
//}
//
//void triangular::setY(double y_) {
//	y = y_;
//}
//
//void triangular::setZ(double z_) {
//	z = z_;
//}