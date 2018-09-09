#ifndef MTRN3500_CIRCLE_H
#define MTRN3500_CIRCLE_H
#include <iostream>
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "myVehicle.hpp"

class circle : public Shape //circle inherits everything from shape class.
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
	double wheel;
	double depth;


public:
	
	circle();
	//circle(double bRadius, double tRadius, double height, int slices, int stack, double InRadius, double OutRadius, int loop);
	circle(double radius, double depth, double wheel);
	/*double getRadius();
	void setRadius(double radius);*/
	virtual void draw();
	bool steering;
	bool rolling;
	//void move(double x, double y); //inherited move is sufficient - see definition
//	bool steering;
//	bool rolling; 
};

#endif