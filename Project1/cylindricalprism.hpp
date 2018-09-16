#ifndef MTRN3500_CYLINDRICALPRISM_H
#define MTRN3500_CYLINDRICALPRISM_H
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "myVehicle.hpp"

class cylindricalprism : public Shape  // cylindrical inherit from Shape
{
protected:
	
	double radius;
	double depth;

public:
	
	bool steering;
	bool rolling;
	double wheel;
	double getRadius() { return radius; } // use to get radius for dynamic cast in myVehicle
	cylindricalprism();
	cylindricalprism(double radius, double depth, bool steer_, bool roll_);
    void draw();
};
#endif