#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"

class circle : public shape
{
private:
	int radius;

public:
	circle(std::string _color, int _radius);

	const void print();
	const double get_area();
};

#endif