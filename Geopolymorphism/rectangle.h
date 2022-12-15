#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
private:
	int height;
	int width;

public:
	rectangle(const std::string& _color, int _height, int _width);

	const void print();

	const double get_area();
};

#endif