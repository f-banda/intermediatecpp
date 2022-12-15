#include "circle.h"
#include <iostream>

// circle constructor - calls shape base constructor and set radius
circle::circle(const std::string _color, int _radius) : shape(_color)
{
	radius = _radius;
}

// print() override method - calls shape::print() base method and print radius and circle's area
const void circle::print()
{
	shape::print();
	std::cout << " circle, radius " << radius << ", area " << get_area() << std::endl;
}

// get_area() override method - returns the area of the described circle
const double circle::get_area()
{
	return (radius * radius) * 3.14f;
}