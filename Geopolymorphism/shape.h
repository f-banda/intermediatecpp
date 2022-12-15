#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>

class shape
{
private:
	std::string color;

public:
	// constructor
	shape(const std::string& _color);

	// destructor
	virtual ~shape();
	
	
	virtual const void print();
	virtual const double get_area() = 0;
};

#endif