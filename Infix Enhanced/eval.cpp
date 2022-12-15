#include <string>
#include <sstream>
#include "mystack.h"

using std::string;
using std::stringstream;

/**
   bool is_number(std::string s)
 * Given a std::string, check if all its characters are digits(numbers)
 ********************************************************************/
 
bool is_number(std::string s)
{
    for (size_t i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;

    return true;
}

/**
   bool is_number(std::string s)
 * Process operators from postfix string described in excercise and push results on the passed reference stack object
 ********************************************************************/
 
void process_operator(int op, mystack &stack)
{
    int right_operand, left_operand;

    switch (op)
    {
    case '~':
        // Get the right operand from stack
        right_operand = stack.top();
        stack.pop();

        // Push the result
        stack.push(right_operand * -1);
        break;

    case '^':
    {
        // Get the operands from stack
        right_operand = stack.top();
        stack.pop();

        left_operand = stack.top();
        stack.pop();

        // Perform the power operation
        int result = 1;

        for (int i = 0;
            i < right_operand;
            i++)
            result *= left_operand;

        // And push result onto stack
        stack.push(result);
    }
    break;

    case '+':
        // Get the operands from stack
        right_operand = stack.top();
        stack.pop();
        left_operand = stack.top();
        stack.pop();
		
		// Perform the addition and push result onto stack

        stack.push(left_operand + right_operand);
        break;

    case '-':
        // Get the operands from stack
        right_operand = stack.top();
        stack.pop();
        left_operand = stack.top();
        stack.pop();
		
		// Perform the subtraction and push result onto stack

        stack.push(left_operand - right_operand);
        break;

    case '*':
        // Get the operands from stack
        right_operand = stack.top();
        stack.pop();
        left_operand = stack.top();
        stack.pop();
		
		// Perform the multiplication and push result onto stack

        stack.push(left_operand * right_operand);
        break;

    case '/':
        // Get the operands from stack
        right_operand = stack.top();
        stack.pop();
        left_operand = stack.top();
        stack.pop();
		
		// If the right operand is 0, tell us that division by 0 is impossible
        if (right_operand == 0)
        {
            printf("*** Division by 0 ***\n");
            stack.push(0);
            break;
        }
		
		// Perform the division and push result onto stack

        stack.push(left_operand / right_operand);
        break;

    default:
        break;
    }
}

/**
   int evaluate(const string& postfix)
 * Process the postfix string given in input following the logic described in the excercise
 ********************************************************************/
 
int evaluate(const string& postfix)
{
    string op;
    mystack eval_stack;
    stringstream ss(postfix); 

    while (ss >> op)
    {
        // Check if the string token is a number
        if (is_number(op))
        {
            int char_int = atoi(op.c_str());
            eval_stack.push(char_int);
            continue;
        }

        // Convert and push onto stack any letter (a-z) to it's correspondent alphabet index
        if (islower(op[0]))
        {
            int char_int = op[0] - 'a';
            eval_stack.push(char_int);
            continue;
        }
   
        // Process operator, if it's an operator
        process_operator(op[0], eval_stack);
    }

    return eval_stack.top();
}
