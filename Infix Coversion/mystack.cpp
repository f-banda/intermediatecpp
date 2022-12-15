/********************************************************************
CSCI 241 - Assignment 7 - Fall 2020

Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   This assignment will convert an infix expression to an 
equivalent postfix expression, which is supplied and will call a 
conversion function.
*********************************************************************/

#include "mystack.h"
#include <string.h>

/**
 * mystack::mystack()
 * Class constructor: Initialize the private members
 ********************************************************************/

mystack::mystack()
{
	stack_pointer = nullptr;
	stack_capacity = 0;
	stack_elements = 0;
}

/**
 * mystack::mystack(const mystack& x)
 * Class constructor: Build a mystack object based on the passed mystack parameter
 ********************************************************************/

mystack::mystack(const mystack& x)
{
	if (x.stack_capacity)
		this->stack_pointer = x.stack_pointer;
	else
		this->stack_pointer = nullptr;

	this->stack_elements = x.stack_elements;
	this->stack_capacity = x.stack_capacity;
}

/**
 * mystack::~mystack()
 * Class destructor: Free the allocated stack pointer
 ********************************************************************/

mystack::~mystack()
{
	if (this->stack_pointer)
		delete[] stack_pointer;
}

/**
 * mystack& mystack::operator=(const mystack& x)
 * Overload that return a new object mystack containing operator values
 ********************************************************************/

mystack& mystack::operator=(const mystack& x)
{
	if (x.stack_capacity)
		this->stack_pointer = x.stack_pointer;
	else
		this->stack_pointer = nullptr;

	this->stack_elements = x.stack_elements;
	this->stack_capacity = x.stack_capacity;
	
	return *this;
}

/**
 * size_t mystack::capacity() const
 * Returns the capacity of the allocated stack pointer
 ********************************************************************/

size_t mystack::capacity() const
{
	return stack_capacity;
}

/**
 * size_t mystack::size() const
 * Returns the number of elements pushed onto the stack
 ********************************************************************/

size_t mystack::size() const
{
	return stack_elements;
}

/**
 * bool mystack::empty() const
 * Returns whether the mystack object has elements pushed or not
 * Returns true if stack elements is 0, false otherwise
 ********************************************************************/

bool mystack::empty() const
{
	return stack_elements == 0;
}

/**
 * void mystack::clear()
 * Reset the number of stack elements present in the array
 ********************************************************************/
void mystack::clear() 
{
	stack_elements = 0;
}

/**
   void mystack::reserve(size_t n)
 * Reserve a number of elements in the stack pointer ready to be used by push method
 ********************************************************************/

void mystack::reserve(size_t n)
{
	// if the number of elements to be reserved are less then or equal to actual stack capacity, return
	if (n <= stack_capacity)
		return;

	// allocate new stack pointer
	char* new_stack_ptr = new char[n];

	// copy over previous stack pointer content
	memcpy(new_stack_ptr, stack_pointer, stack_capacity);

	// delete the previous stack pointer
	delete[] this->stack_pointer;

	// assign new stack pointer and capacity
	stack_pointer = new_stack_ptr;
	stack_capacity = n;
}

/**
   const char& mystack::top() const
 * Return the stack top element from the stack pointer
 ********************************************************************/

const char& mystack::top() const
{
	return this->stack_pointer[this->stack_elements - 1];
}

/**
   void mystack::push(char value)
 * Push into the stack pointer a char element
 ********************************************************************/

void mystack::push(char value)
{
	if (this->stack_capacity == this->stack_elements)
	{
		if (this->stack_capacity == 0)
			this->reserve(1);
		else
			this->reserve(this->stack_capacity * 2);
	}

	this->stack_pointer[this->stack_elements] = value;
	this->stack_elements++;
}

/**
   void mystack::pop()
 * Pop an element from the stack pointer by decreasing the stack elements private member
 ********************************************************************/

void mystack::pop()
{
	if (this->stack_elements == 0)
		return;

	this->stack_elements--;
}
