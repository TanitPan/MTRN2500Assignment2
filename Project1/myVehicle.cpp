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
//VehicleModel Model;

//using namespace std;
myVehicle::myVehicle()
{ 
	Shape* shp;
	

	shp = new rectangularprism(3, 1, 2);
	shp->setColor(0, 0, 1);
	shp->setPosition(0, 0.4, 0);
	shapes.push_back(shp);

	shp = new cylindricalprism(0.4, 0.1, 1); //FL wheel
	shp->setPosition(1.05, 0.4, 1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new cylindricalprism(0.4, 0.1, 1); //FR wheel
	shp->setPosition(1.05, 0.4, -1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new cylindricalprism(0.8, 0.1, 1); //BL wheel
	shp->setPosition(-1.05, 0.8, 1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	shp = new cylindricalprism(0.8, 0.1, 1); //BR wheel
	shp->setPosition(-1.05, 0.8, -1.05);
	shp->setColor(0, 1, 0);
	shapes.push_back(shp);

	//shp = new triangular(1, 2, -0.5, -90);
	//shp->setPosition(0, 1.4, 0);
	//shp->setColor(1,1,0);
	//shp->setRotation(90);
	//shapes.push_back(shp);

	//shp = new triangular(1, 2, -0.5, -90);
	//shp->setPosition(0, 1.4, -1);
	//shp->setColor(1, 1, 0);
	//shp->setRotation(90);
	//shapes.push_back(shp);

	shp = new trapezoidalprism(2, 1.5, 0.5, 0.05, 2);
	shp->setPosition(0, 1.4, 0);
	shp->setColor(1,0,1);
	shapes.push_back(shp);

//ShapeInit part;
//Model.remoteID = 0;
////Part number 1
//part.type = RECTANGULAR_PRISM;
//part.params.rect.xlen = 12.0;
//part.params.rect.ylen = 3.0;
//part.params.rect.zlen = 3.0;
//part.rgb[0] = 1.0;
//part.rgb[1] = 1.0;
//part.rgb[2] = 0.0;
//part.rotation = 0.0;
//part.xyz[0] = 0.0;
//part.xyz[1] = 0.0;
//part.xyz[2] = 0.0;
//Model.shapes.push_back(part);
////Part number 2
//part.type = TRIANGULAR_PRISM;
//part.params.tri.alen = 12.0;
//part.params.tri.blen = 3.0;
//part.params.tri.angle = 60.0;
//part.params.tri.depth = 3.0;
//part.rgb[0] = 1.0;
//part.rgb[1] = 1.0;
//part.rgb[2] = 1.0;
//part.rotation = 0.0;
//part.xyz[0] = 0.0;
//part.xyz[1] = 4.0;
//part.xyz[2] = 0.0;
//Model.shapes.push_back(part);
////Part number 3
//part.type = CYLINDER;
//part.params.cyl.radius = 30.0;
//part.params.cyl.depth = 1.0;
//part.params.cyl.isRolling = 1;
//part.params.cyl.isSteering = 1;
//part.rgb[0] = 1.0;
//part.rgb[1] = 0.0;
//part.rgb[2] = 0.0;
//part.rotation = 0.0;
//part.xyz[0] = 0.0;
//part.xyz[1] = 10.0;
//part.xyz[2] = 0.0;
//Model.shapes.push_back(part);
////Part Number 4
//part.type = CYLINDER;
//part.params.cyl.radius = 3.0;
//part.params.cyl.depth = 1.0;
//part.params.cyl.isRolling = 0;
//part.params.cyl.isSteering = 0;
//part.rgb[0] = 1.0;
//part.rgb[1] = 0.0;
//part.rgb[2] = 0.0;
//part.rotation = 0.0;
//part.xyz[0] = 0.0;
//part.xyz[1] = 15.0;
//part.xyz[2] = 0.0;
//Model.shapes.push_back(part);
////Part 5
//part.type = TRAPEZOIDAL_PRISM;
//part.params.trap.alen = 7;
//part.params.trap.blen = 5;
//part.params.trap.height = 4;
//part.params.trap.aoff = 0;
//part.params.trap.depth = 4;
//part.rgb[0] = 1.0;
//part.rgb[1] = 0.0;
//part.rgb[2] = 0.0;
//part.rotation = 0.0;
//part.xyz[0] = 0.0;
//part.xyz[1] = 25.0;
//part.xyz[2] = 0.0;
//Model.shapes.push_back(part);

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
	//std::cout <<x <<"  " << y << "  " <<z << std::endl;
	/*
	//setPosition(-20,0,0);
	glPushMatrix();
	positionInGL();
	
		glTranslated(0, 0.4, 0);
		glColor3d(0, 0.6, 0);
		rectangularprism R(3, 1.0, 2);
		R.draw();
		//glTranslated(0, -0.4, 0);
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(1.1, 0.4, 1.1);
		glColor3f(1, 0, 0); 
		cylindricalprism SWheel(0.4, 0.1, 1);
		SWheel.draw();
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(1.1, 0.4, -1.1);
		glColor3f(1, 0, 0);
		SWheel.draw();
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(-1.1, 0.8, 1.1);
		glColor3f(0, 0, 1);
		cylindricalprism LWheel(0.8, 0.1, 1);
		LWheel.draw();
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(-1.1, 0.8, -1.1);
		glColor3f(0, 0, 1);
		LWheel.draw();
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(0, 1.4, 0);
		trapezoidalprism Trap(3, 1, 1, 0.785, 0, 0, 1);
		Trap.draw();
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(0, 1.4, -1);
		glRotated(90, 1, 0, 0);
		glColor3d(1, 1, 1);
		triangular triangle(1, 2, -0.5, -90);
		triangle.draw();
		glPopMatrix();

		glPushMatrix();
		positionInGL();
		glTranslated(0, 1.4, 1);
		glRotated(-90, 1, 0, 0);
		glColor3d(1, 1, 1);
		triangle.draw();
		glPopMatrix();
		*/
		//glLoadIdentity


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
	//shapes.clear();

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
	//			shp = new tp(iter->params.trap.alen, iter->params.trap.blen, iter->params.trap.height, iter->params.trap.aoff, iter->params.trap.depth);
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