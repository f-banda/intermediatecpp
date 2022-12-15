// Header Guard Open

#ifndef SIMPLESIM_H
#define SIMPLESIM_H

class simplesim
{
private:
	int memory[100];
	int accumulator;
	int instruction_counter;
	int instruction_register;
	int operation_code;
	int operand;

public:
	simplesim()
	{
		for (int i = 0; i < 100; i++)
			memory[i] = 7777;

		accumulator = 0;
		instruction_counter = 0;
		instruction_register = 0;
		operation_code = 0;
		operand = 0;
	};

	bool load_program();
	void execute_program();
	void dump();
};


// Header Guard Close

#endif