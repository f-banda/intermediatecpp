#include "shape.h"
#include <iostream>

// shape base constructor
shape::shape(const std::string& _color) 
{
	color = _color;
}

// shape base destructor
shape::~shape()
{

}

// print() base method
const void shape::print()
{
	std::cout << color;
}