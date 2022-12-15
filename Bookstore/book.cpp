#include "book.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstring>


book::book()
{
	strcpy(ISBN,  "None");
	strcpy(title, "None");

	price = 0.0;
	stock = 0;
}

char* book::get_isbn()
{
	return ISBN;
}

char* book::get_title()
{
	return title;
}

double book::get_price()
{
	return price;
}

int book::fulfill_order(int number)
{
	if (number <= 0)
		return 0;

	if (stock >= number)
	{
		stock -= number;
		return number;
	}

	int value = stock;
	stock = 0;

	return value;
}

void book::print()
{
	std::cout << std::setw(14) << std::left << ISBN;
	std::cout << std::setw(44) << std::left << title;
	std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << price;
	std::cout << std::setw(6) << std::right << stock;
	std::cout << std::endl;
}