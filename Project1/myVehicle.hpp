
#ifndef MTRN3500_MYVEHICLE_H
#define MTRN3500_MYVEHICLE_H

#include <iostream>
#include "Shape.hpp"
#include "VectorMaths.hpp"
#include <vector>
#include "Vehicle.hpp"
#include "Messages.hpp"



class myVehicle : public Vehicle {
//	friend void remoteDriver(Vehicle * vehicle, double x, double z, double r, double speed_, double steering_);


public:
	//myVehicle();
	myVehicle();

	//myVehicle(int a, int b);
	//virtual ~Vehicle();

	//void update(double dt);
    //void update(double speed_, double steering_, double dt);

	virtual void draw();
	virtual ~myVehicle() {};
	static const int MAX_FORWARD_SPEED_MPS = 10;
	static const int MAX_BACKWARD_SPEED_MPS = -4;
	static const int MAX_LEFT_STEERING_DEGS = 15;
	static const int MAX_RIGHT_STEERING_DEGS = -15;
	static const int VEHICLE_BOUNDS = 3;

	double getSpeed() const { return speed; }
	double getSteering() const { return steering; }


//	void addShape(Shape * shape);

	//user define
	//void myVehicle();

protected:
	VehicleModel Model; // I added it
	double speed;     // m/s
	double steering;  // degrees
	double vehicleSpeed; // I added it
	std::vector<Shape *> shapes;
};

double clamp(double a, double n, double b);

#endif // for MTRN3500_VEHICLE_H

