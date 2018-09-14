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
VehicleModel Model;


myVehicle::myVehicle()
{ 
	Shape* shp;
	
	shp = new rectangularprism(3, 1, 2);
	shp->setColor(0, 0, 1);
	shp->setPosition(0, 0.4, 0);
	shapes.push_back(shp);

	shp = new mywheel(0.4, 0.1, 1, 1); //FL wheel
	shp->setPosition(1.1, 0.4, 1.05);
	shp->setColor(1, 0.603, 0.831);
	shapes.push_back(shp);

	shp = new mywheel(0.4, 0.1, 1, 1); //FR wheel
	shp->setPosition(1.1, 0.4, -1.05);
	shp->setColor(1, 0.603, 0.831);
	shapes.push_back(shp);

	shp = new mywheel(0.8, 0.1, 0, 1); //BL wheel
	shp->setPosition(-1.1, 0.8, 1.05);
	shp->setColor(1, 0.603, 0.831);
	shapes.push_back(shp);

	shp = new mywheel(0.8, 0.1, 0, 1); //BR wheel
	shp->setPosition(-1.1, 0.8, -1.05);
	shp->setColor(1, 0.603, 0.831);
	shapes.push_back(shp);

	shp = new triangular(1, 2, -0.5, -90);
	shp->setPosition(0, 1.4, 0);
	shp->setColor(1,1,0);
	//shp->setRotation(90);
	shapes.push_back(shp);

	shp = new triangular(1, 2, -0.5, -90);
	shp->setPosition(0, 1.4, -1);
	shp->setColor(1, 1, 0);
	//shp->setRotation(90);
	shapes.push_back(shp);

	shp = new trapezoidalprism(2, 1.5, 0.5, 0.05, 2);
	shp->setPosition(0, 1.4, 0);
	shp->setColor(1,0,1);
	shapes.push_back(shp);

}



void myVehicle::draw()
{ 
	glPushMatrix();
	positionInGL();
	setColorInGL();
	for (std::vector<Shape*>::iterator iter = shapes.begin(); iter != shapes.end(); ++iter) {
		mywheel*cylinder = dynamic_cast<mywheel*>(*iter);
		if (cylinder != nullptr) {
			if (cylinder->getSteering() == 1) {
				(*iter)->setRotation(getSteering());
			}
			/*if ((*iter)->params.cyl.isRolling == 1) {
				shp->setTurning(getSpeed());
			}
				(*iter)->setRotation(getSteering());
*/
			if (cylinder->getTurning() == 1) {
				double current = cylinder->getRolling();
				current += getSpeed()*3.141 / cylinder->getRadius();
				cylinder->setRolling(current);
			}

			//}
		}

		(*iter)->draw();
	}

	glPopMatrix();
	


/*	shape* shp = new cylindricalprism(5, 10);

shp->setrotation(vehicle :: steering);

shp->setposition(0, 5, -10 / 2);
addshape(shp);
shape* shp1 = new trapezoidalprism(7,5,4,4,1);

//shp1->setrotation(1);
//shp1->setposition(0, 5, -10 / 2);
//addshape(shp1);
}
*/
	//Shape* shp;
	////shapes.clear();

	//for (std::vector<ShapeInit>::iterator iter = Model.shapes.begin(); iter != Model.shapes.end(); ++iter) {
	//	switch (iter->type) {
	//		case CYLINDER:
	//			shp = new cylindricalprism(iter->params.cyl.radius, iter->params.cyl.depth, iter->params.cyl.isSteering);
	//			if (iter->params.cyl.isSteering == 1) {
	//				shp->setRotation(getSteering());
	//			}
	//			if (iter->params.cyl.isRolling == 1) {
	//				shp->setTurning(getSpeed());
	//			}
	//		break;
	//	case RECTANGULAR_PRISM:
	//		shp = new rectangularprism(iter->params.rect.xlen, iter->params.rect.ylen, iter->params.rect.zlen);
	//		
	//		break;
	//		case TRIANGULAR_PRISM:
	//			shp = new triangular(iter->params.tri.alen, iter->params.tri.blen, iter->params.tri.depth, iter->params.tri.angle);

	//			break;
	//		case TRAPEZOIDAL_PRISM:
	//			shp = new trapezoidalprism(iter->params.trap.alen, iter->params.trap.blen, iter->params.trap.height, iter->params.trap.aoff, iter->params.trap.depth);
	//			break;
	//		}
	//		shp->setColor(iter->rgb[0], iter->rgb[1], iter->rgb[2]);
	//		shp->setPosition(iter->xyz[0], iter->xyz[1], iter->xyz[2]);
	//		//std::cout << iter->params.rect.xlen << std::endl;
	//		addShape(shp);
	//		
	//	}
	//	
	//
	//for (auto iter = shapes.begin(); iter != shapes.end(); ++iter) {
	//	
	//		glPushMatrix();
	//		positionInGL();

	//		//draw in local frame
	//		(*iter)->draw();
	//		//move back to global frame of reference
	//		////cout << "speed is" << vehicleSpeed << endl;
	//		glPopMatrix();

	//	}

}