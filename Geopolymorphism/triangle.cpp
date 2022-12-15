#include "triangle.h"
#include <iostream>

// triangle constructor - calls shape base constructor and sets height and base
triangle::triangle(const std::string& _color, int _height, int _base) : shape(_color)
{
	height = _height;
	base = _base;
}

// print() override method - calls shape::print() base method and print height, base and triangle's area
const void triangle::print()
{
	shape::print();
	std::cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << std::endl;
}

// get_area() override method - returns the area of the described triangle 
const double triangle::get_area()
{
	return (base * height) / 2;
}