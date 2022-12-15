/********************************************************************
CSCI 241 - Assignment 10 - Fall 2020

Name: Francisco Banda
Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   Implement a list ADT using a doubly-linked list. Using
template structure to represent a list node, and a template class
to represent the list. 
*********************************************************************/

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdexcept>

// Node structure 
// Defines a node describing a double linked list item
template < class T>
struct node
{
public:
	// Data members
	T item;

	node<T>* prev;
	node<T>* next;

	// Constructor
	node(const T& newItem = T(), node<T>* next = nullptr, node<T>* prev = nullptr)
	{
		this->item = newItem;
		this->next = next;
		this->prev = prev;
	}
	
};

template <class T>
class mylist
{
private:
	// Data members of class object
	node<T>* listHead;
	node<T>* listBack;
	size_t listSize;

public:
	// Constructor
	mylist()
	{
		listHead = nullptr;
		listBack = nullptr;
		listSize = 0;
	}

	// Copy constructor
	mylist(const mylist<T>& other)
	{
		// Initialize values to null
		listHead = nullptr;
		listBack = nullptr;
		listSize = 0;

		copyList(other);
		listSize = other.listSize;
	}

	// Destructor method: clear out the list items and free them
	~mylist()
	{
		clear();
	}

	// Override<< overload method: print out the list items
	friend std::ostream& operator<<(std::ostream& out, const mylist<T>& stkObj)
	{
		node<T>* curr = stkObj.listHead;
		while (curr != nullptr)
		{
			out << curr->item << " ";
			curr = curr->next;
		}

		return out;
	}

	// Operator= overload method, same as copy constructor
	mylist<T>& operator=(const mylist<T>& otherObj)
	{
		if (this != &otherObj)
		{
			clear();
			copyList(otherObj);
			listSize = otherObj.listSize;
		}

		return *this;
	}

	// Operator== overload method: compares each element of the two classes and return true only if they have both number of items, with the same values
	bool operator==(const mylist<T>& rhs) const
	{
		if (listSize != rhs.listSize)
			return false;

		node<T>* otherNode = rhs.listHead;
		node<T>* currNode = listHead;

		while (currNode)
		{
			if (currNode->item != otherNode->item)
				return false;

			currNode = currNode->next;
			otherNode = otherNode->next;
		}

		return true;
	}

	// Operator< overload method: compares two mylist classes lists using lexicographical comparison
	bool operator<(const mylist<T>& rhs) const
	{
		node<T>* otherNode = rhs.listHead;
		node<T>* currNode = listHead;

		while (otherNode && currNode)
		{
			if (currNode->item < otherNode->item)
				return true;
			else if (currNode->item > otherNode->item)
				return false;

			currNode = currNode->next;
			otherNode = otherNode->next;
		}

		return listSize < rhs.size();
	}

	// clear() method: clear all the items from the list and reset it
	void clear()
	{
		while (!empty())
			pop_back();
	}

	// size() method: return the number of elements in the list
	size_t size() const
	{
		return listSize;
	}

	// empty() method: return true if the list is empty, false otherwise
	bool empty() const
	{
		return listSize == 0;
	}

	// front() method: return the front element of the list for read-only purposes
	const T& front() const
	{
		if (listSize == 0)
			throw std::underflow_error("underflow exception on call to front()");

		return listHead->item;
	}

	// front() method: return the front element of the list for write purposes
	T& front()
	{
		if (listSize == 0)
			throw std::underflow_error("underflow exception on call to front()");

		return listHead->item;
	}

	// back() method: return the back element of the list for read-only purposes
	const T& back() const
	{
		if (listSize == 0)
			throw std::underflow_error("underflow exception on call to back()");

		return listBack->item;
	}

	// back() method: return the back element of the list for write purposes
	T& back()
	{
		if (listSize == 0)
			throw std::underflow_error("underflow exception on call to back()");

		return listBack->item;
	}

	// push_front() method: push a new T item onto the list as first item
	void push_front(const T& newItem)
	{
		node<T>* newNode = new node<T>(newItem, listHead);
	
		if (listSize == 0)
			listHead = listBack = newNode;
		else
		{
			listHead->prev = newNode;
			listHead = newNode;
		}

		listSize++;
	}

	// push_back() method: push a new T item onto the list as last item
	void push_back(const T& newItem)
	{
		// Create a new node
		node<T>* newNode = new node<T>(newItem, nullptr, listBack);

		if (listSize == 0)
			listBack = listHead = newNode;
		else
		{
			listBack->next = newNode;
			listBack = newNode;
		}

		listSize++;
	}

	// pop_front() method: remove first item of the list
	void pop_front()
	{
		if (listSize == 0)
			throw std::underflow_error("underflow exception on call to pop_front()");

		// Define the node to be deleted
		node<T>* tempNode = listHead;

		// The new top node will be the next one
		listHead = listHead->next;

		// Delete the previous top bode
		delete tempNode;

		// Previous node of current top should be null, if valid
		if (listHead)
			listHead->prev = nullptr;
		else
			listBack = nullptr;

		// Decrease size
		listSize--;
	}

	// pop_back() method: remove last item of the list
	void pop_back()
	{
		if (listSize == 0)
			throw std::underflow_error("underflow exception on call to pop_back()");

		node<T>* tempNode = listBack;
		listBack = listBack->prev;
		delete tempNode;

		if (listBack)
			listBack->next = nullptr;
		else
			listHead = nullptr;

		listSize--;
	}

	// copyList() method: copy over the list items of the passing parameter onto the current context one
	void copyList(const mylist<T>& otherObj)
	{
		node<T>* curr = otherObj.listHead;
		while (curr != nullptr)
		{
			push_back(curr->item);
			curr = curr->next;
		}
	}

};


#endif