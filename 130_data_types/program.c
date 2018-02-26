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
   /* You must fill-in two 'if' statements and provide 8 additional statements
    * for a total of 10 statements.  Your program is graded by another program 
    * that feeds it 10 random input values and evaluates the output so you MUST 
    * ensure all 10 statements are complete and accurate!  */


   /* Determine if x is even (vs odd) by filling in this 'if' statement.*/
    if(   1   )  // if even
    { 
        // If even, change the value of x by right shifting its bits 3 places
	

	// Change the value again. Convert x to the 1's compliment of itself	
         
    }
    else  // x is odd
    {
	// If odd, change the value of x by xor'ing it with the number 777
	

	// Next change the value of x by left shifting its bits 1 place
	
    }

    /* Check again to see if x is even */
    if(   1   )  // if even
    {
	char letter = 'h'; // Do not change
        int number;        // Do not change - you will use this below

	/* Cast 'letter' (above) from a character to an integer and assign the 
	 * result to 'number' (also above). */ 
	

	/* Change the value of x by adding 'number' to it. */
        

   	// DO NOT REMOVE OR ALTER THIS PRINT STATEMENT 
   	printf("\n%d\n\n",x);	
    }
    else // x is odd
    {
	size_t size = 0;  // This is used below

	/* Determine the size (in bytes) of x and assign that result to the 
	 * 'size' variable allocated above. */
	size = 

	/* Change the value of x by bit-wise AND'ing it with the value 
	 * assigned to 'size'. */
	

   	// DO NOT REMOVE OR ALTER THIS PRINT STATEMENT 
   	printf("\n%d\n\n",x);	
    }
    return 0;
}
