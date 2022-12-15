/********************************************************************
CSCI 241 - Assignment 5 - Fall 2020

Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   A program that will input a data and output a collection
or inventory of books. It will also create a transaction list by
listing its price and quantity. Information listed will also consist
of ISBN and title.
*********************************************************************/

#include "book_store.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstring>


int main() 
{
	book_store store;

	// read books
	store.read_book_data("bookdata");

	// print them out
	store.print();

	// process orders
	store.process_orders("orders.txt");

	// print again the book store
	store.print();

	return 0;
}