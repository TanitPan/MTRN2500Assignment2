#ifndef MTRN3500_RECTANGULARPRISM_H
#define MTRN3500_RECTANGULARPRISM_H

#include <iostream>
#include "Shape.hpp"


class rectangularprism :public Shape
{
protected:
	double lx, ly, lz;               // dimension length
	//double rotation;              // heading of the object in the horizontal plane (degrees)
	//float red, green, blue;       // colour of object


public:
	rectangularprism();
	rectangularprism(double xl, double yl, double zl);//, double rotation, double r, double g, double b);
	
	virtual void draw();
	double getX();
	double getY();
	double getZ();
	/*void setX(double x_);
	void setY(double y_);
	void setZ(double z_);*/
	//double getRotation();
	//void setRotation(double rotation_);

};

#endif