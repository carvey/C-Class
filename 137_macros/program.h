#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

long validate_input(int, char**);
float modify_me(float);
void usage(char*);

long validate_input(int argc, char* argv[])
{
    if(argc != 2 || !isdigit(*argv[1]))
    {
	    usage(argv[0]);
	    exit(1);
    }

    return atof(argv[1]);
}

void usage(char* filename)
{
#ifdef RADIUS
    printf("\nUsage: %s <radius>\n\n", filename);
#else
    printf("\nUsage: %s <diameter>\n\n", filename);
#endif
}

