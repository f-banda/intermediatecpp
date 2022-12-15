#include "mystack.h"
#include <string.h>

/**
 * mystack::mystack()
 * Private routine that allows us to create a linked list stack copy from another one
 * Returns the head pointer of the new linked list
 ********************************************************************/

node* mystack::copy_stack_nodes(node* head)
{
	// Allocate new stack head
	node* stack_head = new node(head->value);

	// For each nodes, allocate a new one
	node* new_list_stack_node = stack_head;
	node* prev_list_stack_node = head->next;

    // Create and copy over each node value
	while (prev_list_stack_node != nullptr)
	{
		node* new_node = new node(prev_list_stack_node->value);
		new_list_stack_node->next = new_node;
		new_list_stack_node = new_node;
		prev_list_stack_node = prev_list_stack_node->next;
	}

	return stack_head;
}

/**
 * mystack::mystack()
 * Class constructor: Initialize the private members
 ********************************************************************/

mystack::mystack()
{
	stack_head = nullptr;
	stack_size = 0;
}

/**
 * mystack::mystack(const mystack& x)
 * Class constructor: Build a mystack object based on the passed mystack parameter
 ********************************************************************/

mystack::mystack(const mystack& x)
{
	if (x.stack_size)
	{
		// Create a new linked list with the same elements of the passed one
		this->stack_head = copy_stack_nodes(x.stack_head);
		this->stack_size = x.stack_size;
	}
	else
	{
		this->stack_head = nullptr;
		this->stack_size = 0;
	}
}

/**
 * mystack::~mystack()
 * Class destructor: calls clear wrapper
 ********************************************************************/

mystack::~mystack()
{
	clear();
}

/**
 * mystack& mystack::operator=(const mystack& x)
 * Overload that based on the passed operator, return a new object mystack with a new stack linked list
 ********************************************************************/

mystack& mystack::operator=(const mystack& x)
{
	if (x.stack_size)
	{
		this->stack_head = copy_stack_nodes(x.stack_head);
		this->stack_size = x.stack_size;
	}
	else
	{
		this->stack_head = nullptr;
		this->stack_size = 0;
	}
	
	return *this;
}

/**
 * size_t mystack::size() const
 * Returns the number of elements pushed onto the stack
 ********************************************************************/

size_t mystack::size() const
{
	return stack_size;
}

/**
 * bool mystack::empty() const
 * Returns whether the mystack object has elements pushed or not
 * Returns true if there are no stack elements, false otherwise
 ********************************************************************/

bool mystack::empty() const
{
	return stack_size == 0;
}

/**
 * void mystack::clear()
 * Reset the number of stack elements present in the array and free the stack linked list
 ********************************************************************/
void mystack::clear() 
{
	// Free all the node presents
	node* curr_node = stack_head;
	while (curr_node != nullptr)
	{
		node* next_node = curr_node->next;
		delete curr_node;
		curr_node = next_node;
	}

	// Set stack head to nullptr and stack size to 0
	stack_head = nullptr;
	stack_size = 0;
}


/**
   const char& mystack::top() const
 * Return the stack top element from the stack pointer
 ********************************************************************/

const int& mystack::top() const
{
	return this->stack_head->value;
}

/**
   void mystack::push(char value)
 * Push into the stack pointer an integer element
 ********************************************************************/

void mystack::push(int value)
{
	stack_head = new node(value, stack_head);
	stack_size++;
}

/**
   void mystack::pop()
 * Pop an element from the stack pointer by decreasing the stack size private member and free the top element node
 ********************************************************************/

void mystack::pop()
{
	if (this->stack_size == 0)
		return;

	node* temp_head = stack_head;
	stack_head = stack_head->next;
	delete temp_head;

	this->stack_size--;
}
