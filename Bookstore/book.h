#ifndef _BOOK_H

#define _BOOK_H


class book
{
public:
	book();
	char* get_isbn();
	char* get_title();
	double get_price();
	int fulfill_order(int number);
	void print();


private:
	char ISBN[10 + 1];
	char title[40 + 1];
	double price;
	int stock;
};


#endif