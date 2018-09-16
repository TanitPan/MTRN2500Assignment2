#pragma once

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif

#include "myVehicle.hpp"
#include <windows.h>
#include "rectangularprism.hpp"
#include "cylindricalprism.hpp"
#include "TriangularPrism.hpp"
#include "trapezoidalprism.hpp"
#include <vector>
#include "Messages.hpp"
#include <iostream>
#include "Vehicle.hpp"
#include "Shape.hpp"
#include "mywheel.hpp"
#define PI 3.14159265358979323846


myVehicle::myVehicle()
{ 
	Shape* shp;
	
	shp = new rectangularprism(3, 1, 2);
	shp->setColor(1, 0, 0);
	shp->setPosition(0, 0.4, 0);
	shapes.push_back(shp);


	shp = new mywheel(0.4, 0.1, 1,1); //FL wheel
	shp->setPosition(1.05, 0, 1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new mywheel(0.4, 0.1, 1, 1); //FR wheel
	shp->setPosition(1.05, 0, -1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new mywheel(0.8, 0.1,0, 1); //BL wheel
	shp->setPosition(-1.05, 0, 1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new mywheel(0.8, 0.1, 0, 1); //BR wheel
	shp->setPosition(-1.05, 0, -1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new triangular(0.5, 0.5, 2, 90*PI/180);
	shp->setPosition(1.75, 0.4, 0);
	shp->setColor(1,1,0);
	shp->setRotation(0);
	shapes.push_back(shp);

	/*shp = new triangular(1, 2, -0.5, 90*PI/180);
	shp->setPosition(0, 1.4, -1);
	shp->setColor(1, 1, 0);
	shp->setRotation(90);
	shapes.push_back(shp);*/

	shp = new trapezoidalprism(2, 1.5, 0.5, 0.05, 2);
	shp->setPosition(0, 1.4, 0);
	shp->setColor(1,0,1);
	shapes.push_back(shp);

}


void myVehicle::draw()
{ 
	
	for (std::vector<Shape*>::iterator iter = shapes.begin(); iter != shapes.end(); ++iter) {

	glPushMatrix();
	setColorInGL();
	positionInGL();

		mywheel*cylinder = dynamic_cast<mywheel*>(*iter);
		if (cylinder != NULL) {
			if (cylinder->getSteering() == 1) {
				(*iter)->setRotation(getSteering());
			}
			if (cylinder->getTurning() == 1) {
				double current = cylinder->getRolling();
				current += getSpeed()*3.141 / cylinder->getRadius();
				cylinder->setRolling(current);
			}
		}

		(*iter)->draw();
	glPopMatrix();
	}
	
}