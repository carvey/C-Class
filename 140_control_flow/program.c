// There's a missing #include
#include <stdio.h>
#include <string.h>
#include "program.h"


// Don't alter the main function.  Modify the 'modify_me' function
int main(int argc, char *argv[])
{
    return modify_me(validate_input(argc, argv));
}

double modify_me(int x)
{
    /* Write a block of code below that meets the exercise requirements.
     * The user supplied input is the input parameter (x) to this function. */ 


		if (x % 3 == 0 && x % 5 == 0) {
			printf("fizzbuzz\n");
		}

		else if (x % 3 == 0) {
			printf("fizz\n");
		}

		else if (x % 5 == 0) {
			printf("buzz\n");
		}
		else {
			printf("%d\n", x);
		} 
	


   // Leave this return statement
   return 0;
}
