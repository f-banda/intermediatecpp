#include "rectangle.h"
#include <iostream>

// rectangle constructor - calls shape base constructor and set height and width
rectangle::rectangle(const std::string& _color, int _height, int _width) : shape(_color)
{
	height = _height;
	width = _width;
}

// print() override method - calls shape::print() base method and print height, width and rectangle's area
const void rectangle::print()
{
	shape::print();
	std::cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << std::endl;
}

// get_area() override method - returns the area of the described rectangle 
const double rectangle::get_area()
{
	return width * height;
}