#include "rectangularprism.hpp"
#include <GL/glut.h>
#include <math.h>

rectangularprism::rectangularprism() : Shape()
{

}

//rectangularprism::rectangularprism(double x, double y, double z);// , double rotation, double red_, double green_, double blue_) //: Shape(x, y, z, rotation)
//{
//	
//	//setColor(red_, green_, blue_);
//	this -> lx = x;
//	this->ly = y;
//	this->lz = z;
//	/*this-> red = red_;
//	this->green = green_;
//	this->blue = blue_;
//	this->rotation = rotation;*/
//
//
//}

rectangularprism::rectangularprism(double x, double y, double z)
{
	this->lx = x;
	this->ly = y;
	this->lz = z;
}

void rectangularprism::draw()
{

	

	
glPushMatrix();

	glColor3f(red, green, blue);
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);

	//positionInGL();
	//setColorInGL();
	//glColor3f(red, 0 ,blue);
	//glLoadIdentity();
	//glTranslated(x, y, z);
	//setColor(0,0,1);
	//glColor3f(1, 0, 0);
	
	glBegin(GL_QUADS);                
  //top


	glVertex3d(-getX() / 2, getY(), getZ() / 2);
	glVertex3d(-getX() / 2, getY(), -getZ() / 2);
	glVertex3d(getX() / 2, getY(), -getZ() / 2);
	glVertex3d(getX() / 2, getY(), getZ() / 2);
	

	// Bottom face
	glVertex3d(-getX() / 2, 0, getZ() / 2);
	glVertex3d(getX() / 2, 0, getZ() / 2);
	glVertex3d(getX() / 2, 0, -getZ() / 2);
	glVertex3d(-getX() / 2, 0, -getZ() / 2);

	
	
	// Front face 
	glVertex3d(getX() / 2, getY(), -getZ() / 2);
	glVertex3d(-getX() / 2, getY(), -getZ() / 2);
	glVertex3d(-getX() / 2, 0, -getZ() / 2);
	glVertex3d(getX() / 2, 0,- getZ() / 2);
	

	
	// Back face 
	glVertex3d(-getX() / 2, 0, getZ() / 2);
	glVertex3d(-getX() / 2, getY(), getZ() / 2);
	glVertex3d(getX() / 2, getY(), getZ() / 2);
	glVertex3d(getX() / 2, 0, getZ() / 2);
	

	// Left face 
	glVertex3d(-getX() / 2, getY(), -getZ() / 2);
	glVertex3d(-getX() / 2, getY(), getZ() / 2);
	glVertex3d(-getX() / 2, 0, getZ() / 2);
	glVertex3d(-getX() / 2, 0, -getZ() / 2);
	//glEnd();

//	glBegin(GL_QUADS);
	// Right face (x = 1.0f)
	//glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3d(getX() / 2, 0, getZ() / 2);
	glVertex3d(getX() / 2, getY(), getZ() / 2);
	glVertex3d(getX() / 2, getY(), -getZ() / 2);
	glVertex3d(getX() / 2, 0, -getZ() / 2);
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
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

//
//void rectangularprism::setX(double x_) {
//	x = x_;
//}
//
//void rectangularprism::setY(double y_) {
//	y = y_;
//}
//
//void rectangularprism::setZ(double z_) {
//	z = z_;
//}
//double rectangularprism::getRotation()
//{
//	return rotation;
//}
//
//void rectangularprism::setRotation(double rotation_)
//{
//	rotation = rotation_;
//}


