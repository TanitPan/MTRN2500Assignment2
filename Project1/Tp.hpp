#ifndef MTRN3500_TP_H
#define MTRN3500_TP_H

#include <iostream>
#include "Shape.hpp"


class tp :public Shape
{
protected:
	double x, y, z;               // position
	double rotation;              // heading of the object in the horizontal plane (degrees)
	float red, green, blue;       // colour of object
	double a, b;
	double d;
	double h;
	double off;
public:
	tp();
	tp(double x, double y, double z, double off, double d);

	//virtual void draw() = 0;
	void draw();

	double getX();
	double getY();
	double getZ();

	//void setX(double x_);
	//void setY(double y_);
	//void setZ(double z_);
	/*double getRotation();
	void setRotation(double rotation_);*/

};

#endif