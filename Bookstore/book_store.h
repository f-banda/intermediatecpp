#ifndef _BOOK_STORE_H
#define _BOOK_STORE_H

#include "book.h"
#include <string>

class book_store
{
public:

	book_store();
	void read_book_data(std::string fileName);
	void process_orders(std::string fileName);
	void print();

private:

	book books[30];
	int counter;

};


#endif