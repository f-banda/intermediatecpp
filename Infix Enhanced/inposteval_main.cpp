//*******************************************************************
//
//  inposteval_main.cpp
//  CSCI 241 Assignment 8
//
//  Created by name z1912220
//
//*******************************************************************

/********************************************************************
CSCI 241 - Assignment 8 - Fall 2020

Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   This program, by logic, will take the processed string
and perform operations (+, -, *, ~, ^). This program will use mystack
with the convert function from the previous assignment.
*********************************************************************/

#include <iostream>
#include <string>
#include "eval.h"
#include "inpost.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

/**
 * Reads a series of infix strings from standard input. Each string
 * is converted to postfix, printed, evaluated to find the result,
 * and then the result is printed.
 *
 * @return Returns 0 upon successful completion.
 ********************************************************************/
int main()
{
    string infix;
    string postfix;
    
    while (getline(cin, infix))
    {
        cout << "  infix: " << infix << endl;
        postfix = convert(infix);
        cout << "postfix: " << postfix << endl;
        int result = evaluate(postfix);
        cout << "  value: " << result << endl << endl;
    }

    return 0;
}
