#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// this is short for 'unsigned int' (just so you know in case they use it this way)
	unsigned num = 5;

	// this syntax will check if the i'th bit of num is turned on. It does this by doing an 
	// array of 8 iterations and seeing which bits are turned on
	// Examples: 
	// 	1) for i = 5 the binary is 00000101. The statement 1<<0 will make
	// 	   the binary 00000001. When these binary statements are & (and-ed) together,
	// 	   the expression evaluates to true and the printf is called
	// 	2) for i = 5 again, the binary is (still) 00000101. The statement 1<<2 will make
	// 	   the binary 00000100. When you & these together, you get a true statement.
	for (int i = 0; i < 8; i++) {
		if (num & (1<<i)) {
			printf("%d: Bit %d is turned on!\n", num, i);
		}
	}
	return 0;
}

/*
sort
don't contaminate buffer
swap
fix code
getopt 
bit flip
dynamically allocated structure
*/
