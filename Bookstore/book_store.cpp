#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "book_store.h"

book_store::book_store()
{
	counter = 0;
}

void book_store::read_book_data(std::string fileName)
{
	// open book store
	std::ifstream file(fileName, std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "Couldn't open the file " << fileName << std::endl;
		return;
	}


	// read it
	file.read((char*)&books[0], sizeof(book_store));

	if (file.gcount() < (int)sizeof(book_store))
	{
		std::cout << "Error: not enough data in order to read a book store" << std::endl;
		return;
	}

	// close the file
	file.close();

	// sort the books by ISBN using bubblesort
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = i + 1; j < counter; j++)
		{
			if (strcmp(books[i].get_isbn(), books[j].get_isbn()) > 0)
			{
				book temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

void book_store::process_orders(std::string fileName)
{
	std::ifstream file(fileName);
	if (!file.good())
	{
		std::cout << "Couldn't open process order file " << fileName << std::endl;
		return;
	}

	std::cout << "Order Listing" << std::endl;

	int order_number;
	char ISBN[40 + 1];
	int order_quantity;
	while (file >> order_number)
	{
		file >> ISBN;
		file >> order_quantity;

	
		bool book_found = false;

		// search the book
		for (int i = 0; i < counter; i++)
		{
			if (!strcmp(books[i].get_isbn(), ISBN))
			{
				// found, process the order
				int books_shipped = books[i].fulfill_order(order_quantity);

				// calculate books price
				double books_price = books_shipped * books[i].get_price();

				// signal the book as found
				book_found = true;

				// print report
				std::cout << "Order #" << order_number << ": ISBN " << ISBN << ", " << books_shipped << " of " << order_quantity << " shipped, order total " << books_price << std::endl;
				break;
			}
		}

		//Order #101005: error - ISBN 0612542520 does not exist

		if (!book_found)
			std::cout << "Order #" << order_number << ": error - ISBN " << ISBN << " does not exist" << std::endl;
		
	}


	file.close();

	std::cout << std::endl;
}

void book_store::print()
{
	std::cout << "Book Inventory Listing" << std::endl << std::endl;


	std::cout << std::setw(14) << std::left << "ISBN" << std::setw(44) << std::left << "Title" << std::setw(5) << std::right << "Price" << std::setw(6) << std::right << "Qty." << std::endl << std::endl;

	for (int i = 0; i < counter; i++)
		books[i].print();

	std::cout << std::endl;
}