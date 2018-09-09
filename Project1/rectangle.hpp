#ifndef MTRN3500_RECTANGLE_H
#define MTRN3500_RECTANGLE_H

#include <iostream>
#include "Shape.hpp"


class rectangle :public Shape
{
protected:
	double lx, ly, lz;               // dimension length
	//double rotation;              // heading of the object in the horizontal plane (degrees)
	//float red, green, blue;       // colour of object


public:
	rectangle();
	rectangle(double x, double y, double z);//, double rotation, double r, double g, double b);
	//virtual void draw() = 0;
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