#include "inpost.h"
#include "mystack.h"

/**
 * bool is_operator(char c, int &precedence)
 * Returns true if the character is an operator and specify in the precedence reference parameter its priority, false otherwise
 ********************************************************************/

bool is_operator(char c, int &precedence)
{
	switch (c)
	{
	case '~':
		precedence = 1;
		return true;

	case '^':
		precedence = 2;
		return true;

	case '*':
		precedence = 3;
		return true;

	case '/':
		precedence = 4;
		return true;

	case '+':
		precedence = 5;
		return true;

	case '-':
		precedence = 6;
		return true;
	}

	return false;
}

/**
 * std::string convert(const std::string& infix)
 * Process a string "infix" according to the excercise needs
 ********************************************************************/

std::string convert(const std::string& infix)
{
	std::string postfix;
	mystack opstack;
	bool is_previous_char_operand = false;

	for (size_t i = 0; i < infix.length(); i++)
	{
		// skip whitespaces
		if (isspace(infix[i]))
			continue;

		// if it's an operand, add it to postfix string and continue
		if (isdigit(infix[i]) || islower(infix[i]))
		{
			// if the postfix string contains any character and previous character wasn't a digit, append a space
			if (postfix.length() && !is_previous_char_operand)
				postfix += ' ';

			// append the current operand
			postfix += infix[i];

			// set the boolean describing that the previous character was an operand
			is_previous_char_operand = true;
			continue;
		}
		
		// the processing character is not an operand, set the according boolean to false
		is_previous_char_operand = false;

		// if it's a left parenthesis, push it to the opstack stack object
		if (infix[i] == '(')
		{
			opstack.push(infix[i]);
			continue;
		}

		// if it's a right parenthesis, pop all the items from opstack until the correspondent left parenthesis is found
		if (infix[i] == ')')
		{
			while (opstack.top() != '(')
			{
				// if there was anything appended before (operator or operand doesn't matter), add a space
				if (postfix.length())
					postfix += ' ';

				// append current operand
				postfix += opstack.top();

				// pop it from stack
				opstack.pop();
			}

			// pop the left parenthesis aswell
			opstack.pop();

			continue;
		}

		int cur_op_precedence_index,
			stack_op_precedence_index;

		// check if current character is an operator and if yes get its precedence index
		if (is_operator(infix[i], cur_op_precedence_index))
		{
			// if its an operator, pop into postfix all operators until either the stack is empty or the popped operator has a lower priority id
			while (!opstack.empty())
			{
				char op_from_stack = opstack.top();
				if (is_operator(op_from_stack, stack_op_precedence_index) &&
					stack_op_precedence_index <= cur_op_precedence_index)
				{
					// if there was anything appended before (operator or operand doesn't matter), add a space
					if (postfix.length())
						postfix += ' ';

					postfix += op_from_stack;
					opstack.pop();
				}
				else
					break;
			}

			// push current processed operator
			opstack.push(infix[i]);
		}
	}

	// append remaining operators 
	while (!opstack.empty())
	{
		if (postfix.length())
			postfix += ' ';

		postfix += opstack.top();
		opstack.pop();
	}

	return postfix;
}