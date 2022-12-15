#ifndef _MYSTACK_H
#define _MYSTACK_H

#include <cstddef>

// Struct describing a stack node in a linked list
struct node
{
	node* next;
	int value;

	node(int value, node* next = nullptr)
	{
		this->value = value;
		this->next = next;
	}
};

class mystack
{
	// private members
private:
	node* stack_head;
	size_t stack_size;
	node* copy_stack_nodes(node* head);

// public methods
public:
	mystack();
	mystack(const mystack& x);
	~mystack();

	mystack& operator=(const mystack& x);

	size_t size() const;
	bool empty() const;
	void clear();

	const int& top() const;
	void push(int value);
	void pop();
};

#endif