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

#include "remotevehicle.hpp"
#include "mywheel.hpp"



Shape* shp;
remotevehicle::remotevehicle() 
{
}

remotevehicle::remotevehicle(VehicleModel Model)
{
	
	shapes.clear();

	for (std::vector<ShapeInit>::iterator iter = Model.shapes.begin(); iter != Model.shapes.end(); ++iter) {
		switch (iter->type) {
		case CYLINDER:

			shp = new cylindricalprism(iter->params.cyl.radius, iter->params.cyl.depth, iter->params.cyl.isSteering, iter->params.cyl.isRolling);
			/*if (iter->params.cyl.isSteering == 1) {

				shp->setRotation(getSteering());
			}
			if (iter->params.cyl.isRolling == 1) {
				shp->setTurning(getSpeed());
			}*/
			break;
		case RECTANGULAR_PRISM:
			shp = new rectangularprism(iter->params.rect.xlen, iter->params.rect.ylen, iter->params.rect.zlen);

			break;
		case TRIANGULAR_PRISM:
			shp = new triangular(iter->params.tri.alen, iter->params.tri.blen, iter->params.tri.depth, -iter->params.tri.angle);

			break;
		case TRAPEZOIDAL_PRISM:
			shp = new trapezoidalprism(iter->params.trap.alen, iter->params.trap.blen, iter->params.trap.height, iter->params.trap.aoff, iter->params.trap.depth);
			break;
		}
		shp->setColor(iter->rgb[0], iter->rgb[1], iter->rgb[2]);
		shp->setPosition(iter->xyz[0], iter->xyz[1], iter->xyz[2]);
		//shp->setRotation(iter->rotation);
		addShape(shp);

	}


}

void remotevehicle::draw()
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

			
		}

		(*iter)->draw();
	}

	glPopMatrix();
	
}
