#include "sml.h"
#include "simplesim.h"
#include <iostream>
#include <iomanip>

///
/// Load simplesim program language into memory
///
bool simplesim::load_program()
{ 
	int cur_mnemonic;
	int cur_index = 0;
	do
	{
		std::cin >> cur_mnemonic;

		if (cur_mnemonic != -99999)
		{
			if (cur_mnemonic < -9999 || cur_mnemonic > 9999)
			{
				std::cout << "*** ABEND: pgm load: invalid word ***" << std::endl << std::endl;

				return false;
			}


			if (cur_index < 100)
				memory[cur_index++] = cur_mnemonic;
			else
			{
				std::cout << "*** ABEND: pgm load: pgm too large ***" << std::endl << std::endl;
				return false;
			}
		}


	} while (cur_mnemonic != -99999);

	return true;
}

/// 
/// Core of simplesim virtual machine dispatcher
/// Contains all the logical operations
/// 
/// 
void simplesim::execute_program()
{
	bool done = false;
	while (!done)
	{
		if (!(instruction_counter >= 0 && instruction_counter <= 99))
		{
			std::cout << "*** ABEND: addressability error ***" << std::endl;
			break;
		}

		// instruction fetch
		instruction_register = memory[instruction_counter];
		operation_code = instruction_register / 100;
		operand = instruction_register % 100;

		// instruction execute
		switch (operation_code)
		{
		/// 
		/// Read operation
		/// Get in input a word and store it in operand
		/// 
		case READ:
			int read_value;
			std::cin >> read_value;

			if (read_value < -9999 || read_value > 9999)
			{
				std::cout << "*** ABEND: illegal input ***" << std::endl;
				return;
			}

			memory[operand] = read_value;
			std::cout << "READ: " << std::internal << std::setw(5) << std::setfill('0') << std::showpos << memory[operand] << std::noshowpos << std::setfill(' ') << std::endl;

			
			break;
		/// 
		/// Write operation
		/// Output to console word contained at memory[operand]
		/// 
		case WRITE:
			std::cout << std::internal << std::setw(5) << std::setfill('0') << std::showpos << memory[operand] << std::noshowpos << std::setfill(' ') << std::endl;
			break;

		/// 
		/// Store at memory[operand] the accumulator
		/// 
		case STORE:
			memory[operand] = accumulator;
			break;

			
		/// 
		/// Load into accumulator the word at memory[operand]
		/// 
		case LOAD:
			accumulator = memory[operand];
			break;
		
		/// 
		/// Logical operators (ADD/SUB/MUL/DIV)
		/// 
		case ADD:
		{
			int sum = accumulator + memory[operand];

			if (sum < -9999)
			{
				std::cout << "*** ABEND: underflow ***" << std::endl;
				return;
			}
			else if (sum > 9999)
			{
				std::cout << "*** ABEND: overflow ***" << std::endl;
				return;
			}

			accumulator = sum;
		}
		break;

		case SUBTRACT:
		{
			int diff = accumulator - memory[operand];

			if (diff < -9999)
			{
				std::cout << "*** ABEND: underflow ***" << std::endl;
				return;
			}
			else if (diff > 9999)
			{
				std::cout << "*** ABEND: overflow ***" << std::endl;
				return;
			}

			accumulator = diff;
		}
		break;

		case MULTIPLY:
		{
			int factor = accumulator * memory[operand];
			if (factor < -9999)
			{
				std::cout << "*** ABEND: underflow ***" << std::endl;
				return;
			}
			else if (factor > 9999)
			{
				std::cout << "*** ABEND: overflow ***" << std::endl;
				return;
			}

			accumulator = factor;
		}
		break;

		case DIVIDE:
		{
			if (memory[operand] == 0)
			{
				std::cout << "*** ABEND: attempted division by 0 ***" << std::endl;
				return;
			}

			int quot = accumulator / memory[operand];
			if (quot < -9999)
			{
				std::cout << "*** ABEND: underflow ***" << std::endl;
				return;
			}
			else if (quot > 9999)
			{
				std::cout << "*** ABEND: overflow ***" << std::endl;
				return;
			}

			accumulator = quot;
		}
		break;


		/// 
		/// Branch handlers
		/// 
		case BRANCH:
			instruction_counter = operand;
			break;

		case BRANCHZERO:
			if (accumulator == 0)
				instruction_counter = operand;
			else
				instruction_counter++;
			break;

		case BRANCHNEG:
			if (accumulator < 0)
				instruction_counter = operand;
			else
				instruction_counter++;
			break;

		case HALT:
			std::cout << "*** Simplesim execution terminated ***" << std::endl;
			done = true;
			break;

		default:
			std::cout << "*** ABEND: invalid opcode ***" << std::endl;
			return;
		}

		if (operation_code != BRANCH &&
			operation_code != BRANCHZERO &&
			operation_code != BRANCHNEG &&
			operation_code != HALT &&
			!done)
		{
			instruction_counter++;
		}

	}
	std::cout << std::endl;
}


/// 
/// Dump to console the simplesim context
/// 
void simplesim::dump()
{
	std::cout << "REGISTERS:" << std::endl;

	std::cout << "accumulator:            " << std::internal << std::setw(5) << std::setfill('0') << std::showpos << accumulator << std::setfill(' ') << std::noshowpos << std::endl;
	std::cout << "instruction_counter:    " << std::right << std::setfill('0') << std::setw(2) << instruction_counter << std::endl;
	std::cout << "instruction_register:   " << std::setfill('0') << std::setw(5) << std::internal << std::showpos << instruction_register << std::noshowpos << std::setfill(' ') << std::endl;
	std::cout << "operation_code:         " << std::setfill('0') << std::setw(2) << std::right << operation_code << std::setfill(' ') << std::endl;
	std::cout << "operand:                " << std::setfill('0') << std::setw(2) << std::right << operand << std::setfill(' ') << std::endl;

	std::cout << std::endl;
	std::cout << "MEMORY:" << std::endl;
	std::cout << "       0     1     2     3     4     5     6     7     8     9" << std::endl;

	for (int i = 0;
		//i < (sizeof(memory) / sizeof(int)) / 10;
		i < 10;
		i++)
	{
		std::cout << std::setw(2) << (i * 10) << " ";
		for (int j = 0;
		//	j < (sizeof(memory) / sizeof(int)) / 10;
			j < 10;
			j++)
		{
			std::cout << std::internal << std::setfill('0') << std::setw(5) << std::showpos << memory[i * 10 + j] << std::noshowpos << std::setfill(' ');
			//if (j + 1 < (sizeof(memory) / sizeof(int)) / 10)
			if(j + 1 < 10)
				std::cout << " ";
		}

		std::cout << std::endl;
	}
}