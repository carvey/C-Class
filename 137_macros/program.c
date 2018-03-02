#include <stdio.h>
#include <string.h>
#include <math.h>
#include "program.h"

#ifdef RADIUS
	#define CIRCUMFERENCE(radius) 2*acos(-1)*radius
#else
	#define CIRCUMFERENCE(diam) acos(-1)*diam
#endif


// Don't alter the main function.  Modify the 'modify_me' function
int main(int argc, char *argv[])
{
    return modify_me(validate_input(argc, argv));
}

float modify_me(float x)
{
     float cir = CIRCUMFERENCE(x);
	 #ifdef RADIUS
	 	printf("The CIRCUMFERENCE based on a radius of %0.0f feet has a CIRCUMFERENCE of %0.2f feet.\n", x, cir);
     #else
     	printf("The CIRCUMFERENCE based on a diameter of %0.0f feet has a CIRCUMFERENCE of %0.2f feet.\n", x, cir);
     #endif

     return cir;
}
