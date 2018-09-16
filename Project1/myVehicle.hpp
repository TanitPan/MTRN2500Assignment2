
#ifndef MTRN3500_MYVEHICLE_H
#define MTRN3500_MYVEHICLE_H

#include <iostream>
#include "Shape.hpp"
#include "VectorMaths.hpp"
#include <vector>
#include "Vehicle.hpp"
#include "Messages.hpp"



class myVehicle : public Vehicle {

public:
	myVehicle();
	virtual void draw();
	virtual ~myVehicle() {};
	static const int MAX_FORWARD_SPEED_MPS = 10;
	static const int MAX_BACKWARD_SPEED_MPS = -4;
	static const int MAX_LEFT_STEERING_DEGS = 15;
	static const int MAX_RIGHT_STEERING_DEGS = -15;
	static const int VEHICLE_BOUNDS = 3;

protected:

	double speed;     // m/s
	double steering;  // degrees
	std::vector<Shape *> shapes;
};

double clamp(double a, double n, double b);

#endif 

