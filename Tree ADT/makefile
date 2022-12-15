#
# PROGRAM:    Assignment 12
# PROGRAMMER: Francisco Banda
# LOGON ID:   z1912220
# DATE DUE:   Dec. 2
#

# Compiler variables
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file

assign12: assign12.o
	g++ $(CXXFLAGS) -o assign12 assign12.o

# Rules to compile source code files to object code
assign12.o: assign12.cpp shape.cpp shape.h circle.cpp circle.h rectangle.cpp rectangle.h triangle.cpp triangle.h
# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 *.o
