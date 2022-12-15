#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "shape.h"

class triangle : public shape
{
private:
	int height;
	int base;

public:
	triangle(const std::string& _color, int _height, int _base);
	const void print();
	const double get_area();
};

#endif