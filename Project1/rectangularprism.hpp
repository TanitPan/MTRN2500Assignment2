#ifndef MTRN3500_RECTANGULARPRISM_H
#define MTRN3500_RECTANGULARPRISM_H

#include <iostream>
#include "Shape.hpp"


class rectangularprism :public Shape
{
protected:
	double lx, ly, lz;		// dimension length

public:
	rectangularprism();
	rectangularprism(double xl, double yl, double zl);	
	void draw();
	double getX();
	double getY();
	double getZ();

};

#endif