#ifndef MTRN3500_REMOTEVEHICLE_H
#define MTRN3500_REMOTEVEHICLE_H

#include <iostream>
#include "Shape.hpp"
#include "VectorMaths.hpp"
#include <vector>
#include "Vehicle.hpp"
#include "Messages.hpp"



class remotevehicle : public Vehicle {

protected:



public:
remotevehicle();
remotevehicle(VehicleModel Model);


virtual void draw();
virtual ~remotevehicle() {};
static const int MAX_FORWARD_SPEED_MPS = 10;
static const int MAX_BACKWARD_SPEED_MPS = -4;
static const int MAX_LEFT_STEERING_DEGS = 15;
static const int MAX_RIGHT_STEERING_DEGS = -15;
static const int VEHICLE_BOUNDS = 3;

double getSpeed() const { return speed; }
double getSteering() const { return steering; }


}
#endif