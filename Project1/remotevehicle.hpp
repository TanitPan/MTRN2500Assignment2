#ifndef MTRN3500_REMOTEVEHICLE_H
#define MTRN3500_REMOTEVEHICLE_H

#include <iostream>
#include "Shape.hpp"
#include "VectorMaths.hpp"
#include <vector>
#include "Messages.hpp"
#include "Vehicle.hpp"
#include <GL/glut.h>

class remotevehicle : public Vehicle 
{

public:
remotevehicle();
remotevehicle(VehicleModel Model);
void draw();

};
#endif