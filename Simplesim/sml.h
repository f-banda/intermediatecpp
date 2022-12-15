// Header Guard Open

#ifndef SML_H
#define SML_H

// Input / Output Operations

#define READ 11 // Read a word into a specific memory location
#define WRITE 12 // Print a word from a specific memory location

// Store / Load Operations

#define STORE 21 // Store the word in the accumulator into a specific memory location
#define LOAD 22 // Load a word from a specific memory location into the accumulator

// Arithmetic Operations

#define ADD 31 // Add a word in a specific memory location to the word in the accumulator (leave result in accumulator)
#define SUBTRACT 32	// Subtract a word in a specific memory location from the word in the accumulator (leave result in accumulator)
#define MULTIPLY 33 // Multiply a word in a specific memory location by the word in the accumulator (leave result in accumulator)
#define DIVIDE 34 // Divide a word in a specific memory location into the word in the accumulator (leave result in accumulator)

// Transfer of Control Operations

#define BRANCH 41 // Branch to a specific memory location.
#define BRANCHZERO 42 // Branch to a specific memory location if the accumulator is zero.
#define BRANCHNEG 43 // Branch to a specific memory location if the accumulator is negative.
#define HALT 44 // Halt aka the program has completed its task.

// Header Guard Close

#endif