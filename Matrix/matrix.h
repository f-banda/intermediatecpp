/********************************************************************
CSCI 241 - Assignment 6 - Fall 2020

Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   Compute the detirminant of a matrix. Perform mathematics
on a rectangular array of integers (elements). This assignment mainly
introduces the concept of operator overloading and the friend keyword.
*********************************************************************/

#ifndef _MATRIX_H_
#define _MATRIX_H_


#include <iostream>


class matrix
{

public:
	matrix();
	matrix(int arr[2][2]);
	int determinant() const;
	matrix operator+ (const matrix& T2) const;
	matrix operator*(const int T2) const;
	matrix operator*(const matrix& T2) const;
	bool operator==(const matrix& T2) const;
	bool operator!=(const matrix& T2) const;

private:
	int matrix_arr[2][2];

	friend std::ostream& operator<<(std::ostream& os, const matrix& T1);
	friend matrix operator*(int multiplier, const matrix& T2);
};

#endif