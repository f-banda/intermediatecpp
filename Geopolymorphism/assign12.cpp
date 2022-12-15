/********************************************************************
CSCI 241 - Assignment 12 - Fall 2020

Name: Francisco Banda
Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   Create a series of classes to represent simple geometric
shapes and a program to test the classes. Covers inheritance and
subtype polymorphism.
*********************************************************************/

#include <iostream>
#include <vector>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

int main()
{
    // create a pair of dynamic objects for each shape class
    circle* circle1 = new circle("red", 2);
    circle* circle2 = new circle("blue", 3);

    rectangle* rectangle1 = new rectangle("black", 2, 1);
    rectangle* rectangle2 = new rectangle("purple", 3, 2);

    triangle* triangle1 = new triangle("white", 4, 7);
    triangle* triangle2 = new triangle("yellow", 10, 15);

    // add each of the dynamic objects to a vector
    std::vector<shape*> shapes;
    shapes.push_back(circle1);
    shapes.push_back(circle2);
    shapes.push_back(rectangle1);
    shapes.push_back(rectangle2);
    shapes.push_back(triangle1);
    shapes.push_back(triangle2);

    // print all the shapes
    std::cout << "Printing all shapes..." << std::endl << std::endl;

   
    for (shape* curr_shape : shapes)
        curr_shape->print();

    std::cout << std::endl;

    // print only the circles

    std::cout << "Printing only circles..." << std::endl << std::endl;

    for (shape* curr_shape : shapes)
    {
        circle* curr_circle = dynamic_cast<circle*>(curr_shape);

        if (curr_circle)
            curr_circle->print();
    }

    // delete the created objects
    for (shape* curr_shape : shapes)
        delete curr_shape;

    return 0;
}
