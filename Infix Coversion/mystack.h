#ifndef _MYSTACK_H
#define _MYSTACK_H

#include <stddef.h>

class mystack
{
	// private members
private:
	char* stack_pointer;
	size_t stack_capacity;
	size_t stack_elements;

	// public methods
public:
	mystack();
	mystack(const mystack& x);
	~mystack();

	mystack& operator=(const mystack& x);

	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	void clear();

	void reserve(size_t n);
	const char& top() const;
	void push(char value);
	void pop();
};

#endif