#ifndef MTRN3500_TRIANGULARPRISM_H
#define MTRN3500_TRIANGULARPRISM_H

#include <iostream>
#include "Shape.hpp"


class triangular:public Shape
{
protected:
	double x, y, z;               // position
	double rotation;              // heading of the object in the horizontal plane (degrees)
	float red, green, blue;       // colour of object
	double a, b;
	double d;
	double theta;


public:
	triangular();
	triangular(double x, double y, double z, double theta);

	
	void draw();

	
};

#endif