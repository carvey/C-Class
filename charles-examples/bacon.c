#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myFunc() {

	char buf[64] = { 0 };

	if (fgets(buf, 64, stdin) != NULL) {

		char *token = strtok(buf, " ");
		if (strcmp(token, "BACON") == 0) {
			fprintf(stderr, "Match: %s\n", buf);
		} else {
			fprintf(stdout, "No Match: %s\n", buf);
		}
	}
	
}

int
main(int argc, char *argv[])
{
	myFunc();
	exit(EXIT_SUCCESS);
}

