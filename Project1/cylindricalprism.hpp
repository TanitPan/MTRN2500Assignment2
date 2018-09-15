#ifndef MTRN3500_CYLINDRICALPRISM_H
#define MTRN3500_CYLINDRICALPRISM_H
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "myVehicle.hpp"

class cylindricalprism : public Shape //cylinder inherits everything from shape class.
{
protected:
	//double Radius;
	//GLUquadric *cyclinder;
	double InRadius;
	double OutRadius;
	int slices;
	int loop;
	double bRadius;
	double tRadius;
	double height;
	int stack;
	double radius;
	
	double depth;


public:
	double wheel;
	cylindricalprism();
	//cylinder(double bRadius, double tRadius, double height, int slices, int stack, double InRadius, double OutRadius, int loop);
	cylindricalprism(double radius, double depth, bool steer_, bool roll_);
	/*double getRadius();
	void setRadius(double radius);*/
	virtual void draw();
	bool steering;
	bool rolling;
	//bool getSteering() { return steering; } //not needed
	double getRadius() { return radius; }
	//void move(double x, double y); //inherited move is sufficient - see definition
//	bool steering;
//	bool rolling; 
};

#endif