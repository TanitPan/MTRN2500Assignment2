#ifndef MTRN3500_MYWHEEL_H
#define MTRN3500_MYWHEEL_H
#include <iostream>
#include "Shape.hpp"
#include "circle.hpp"
#include "TriangularPrism.hpp"

class wheel : public circle,  public triangular
{
protected:
	
	bool steer;
	bool roll;

public: 

	
	wheel();
	wheel(double radius, double depth, double steering_, double rolling);
	void draw();

};
#endif