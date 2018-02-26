#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

int isalphachar(char *string);
int isvalid(char *string);
int query_user_data(char *name);

/*
 * error key:
 * 1: success
 * 2: number in input
 * 3: wrong username entered
 */ 

int main() {

	size_t size = 17;
	char name[size]; 

	printf("I’ve spun your straw into gold now guess my name: \n");         
	while(query_user_data(name) == EXIT_FAILURE)
		query_user_data(name);

	while (!isvalid(name)) {
		query_user_data(name);
	}
	printf("Who told you!\n");

	return 0;
}

int isalphachar(char *string)
{
    int status = 1;

    if(strlen(string) < 1) 
        return 0;

    for(unsigned long i = 0; i <= strlen(string) -1; i++) // #7
    {
		if(!isalpha(string[i])) {
			printf("Invalid input, try again!\n");	
			status = 0;
			return status;
		}
	}

    return status;
}

int isvalid(char *string) {
	// answer will check for RumpelsTiltskinagain
	int status = 1;

	for (int i = 0; i < 15; i++)
	{
		string[i] = tolower(string[i]);
	}
	if (strcmp(string, "rumpelstiltskin") != 0) {
		status = 0;
		printf("Wrong, try again!\n");
		return status;
	}

	return status;
}

int query_user_data(char *name)
{
    do             
    {
		scanf("%15s", name);

	} while(!isalphachar(name));                     
	return(EXIT_SUCCESS);
}

