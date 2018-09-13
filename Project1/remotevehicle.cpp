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
#include "rectangle.hpp"
#include "circle.hpp"
#include "TriangularPrism.hpp"
#include "Tp.hpp"
#include <vector>
#include "Messages.hpp"
#include <iostream>
#include "Vehicle.hpp"
#include "Shape.hpp"

#include "remotevehicle.hpp"



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
			shp = new circle(iter->params.cyl.radius, iter->params.cyl.depth, iter->params.cyl.isSteering);
			if (iter->params.cyl.isSteering == 1) {
				shp->setRotation(getSteering());
			}
			if (iter->params.cyl.isRolling == 1) {
				shp->setTurning(getSpeed());
			}
			break;
		case RECTANGULAR_PRISM:
			shp = new rectangle(iter->params.rect.xlen, iter->params.rect.ylen, iter->params.rect.zlen);

			break;
		case TRIANGULAR_PRISM:
			shp = new triangular(iter->params.tri.alen, iter->params.tri.blen, iter->params.tri.depth, iter->params.tri.angle);

			break;
		case TRAPEZOIDAL_PRISM:
			shp = new tp(iter->params.trap.alen, iter->params.trap.blen, iter->params.trap.height, iter->params.trap.aoff, iter->params.trap.depth);
			break;
		}
		shp->setColor(iter->rgb[0], iter->rgb[1], iter->rgb[2]);
		shp->setPosition(iter->xyz[0], iter->xyz[1], iter->xyz[2]);
		shp->setRotation(iter->rotation);
		//std::cout << iter->params.rect.xlen << std::endl;
		addShape(shp);

	}


}

void remotevehicle::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();
	for (std::vector<Shape*>::iterator iter = shapes.begin(); iter != shapes.end(); ++iter) {
		/*circle*cylinder = dynamic_cast<circle*>(*iter);
		if (cylinder != nullptr) {

		(*iter)->setRotation(getSteering());*/


		(*iter)->draw();
		//}

	}
	glPopMatrix();
}
