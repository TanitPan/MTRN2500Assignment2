#ifndef MTRN3500_MYWHEEL_H
#define MTRN3500_MYWHEEL_H

#include <iostream>
#include "Shape.hpp"
#include "cylindricalprism.hpp"
#include "TriangularPrism.hpp"


class mywheel : public cylindricalprism 
{

protected:
	bool steering;
	bool turning;
	double rolling;
public:
	mywheel();
	mywheel(double radius, double depth, bool steer_, bool turn_);
	bool getSteering() { return steering; }
	bool getTurning() { return turning; }
	void draw();
	void setRolling(double _rolling);
	double getRolling() { return rolling; }
	 void drawCross(float xl, float yl, float zl);
};

#endif