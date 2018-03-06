/*******************************************************************************
*  FILE NAME : 120_struct.c
*  AUTHOR : Jason Enochs 
*  CREATION DATE : 12-Feb-2018
*  LAST MODIFIED : 12-Feb-2018
*  DESCRIPTION : Example showing how to assign members of a struct
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// make a struct called myStruct
struct myStruct
{   
    char p1[19];
    unsigned int p2;
    float p3;
    int p4[6]; 
    unsigned int p5;
};

int main(void)
{
	// make an array of size 4
    int array[4] = {2,3,8,14};
    // declare a struct of type myStruct and call it s1.
    // Dynamically allocate it's size
    struct myStruct* s1 = (struct myStruct*)malloc(sizeof(struct myStruct));    
    // set the values of s1 (p1, p2, p3, p4, and p5)
    strcpy(s1->p1, "buggs_bunny");
    s1->p2 = 0xdeafdeaf;
    s1->p3 = 1910.0777;
    memcpy(s1->p4, array, sizeof(array));
    s1->p5 = 0xFFFFFFFF; 

    // you could make another struct of myStruct down here as well. EX:
    // struct myStruct* s2 = (struct myStruct*)malloc(sizeof(struct myStruct));
    // then you would set the values of s2 just like above
    
    return 0; 
}

