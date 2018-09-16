#ifndef MTRN3500_TRAPEZOIDALPRISM_H
#define MTRN3500_TRAPEZOIDALPRISM_H

#include <iostream>
#include "Shape.hpp"
//#include <GL/glut.h>

class trapezoidalprism :public Shape
{
protected:          
	  
	double a, b;
	double d;
	double h;
	double off;
public:
	trapezoidalprism();
	trapezoidalprism(double alen, double blen, double height, double off, double d);

	
	void draw();

	double getX();
	double getY();
	double getZ();

};
#endif