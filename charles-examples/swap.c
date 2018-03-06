#include <stdio.h>
#include <stdlib.h>


void swap_func(int* a, int* b) {
	// for example purposes, print out the value of each argument
	printf("a: %d, b: %d\n", *a, *b);

	// start by creating a temporary variable to hold the value of b
	int tmp = *b;
	// then set the value of b equal to the value of a
	*b = *a;
	// then set the value of a to the value of tmp. We can't set it equal to the 
	// value of b since that has now been overidden
	*a = tmp;

	// print out the swapped values
	printf("a: %d, b: %d\n", *a, *b);
}

int main() {
	// Given two variables (integers in this case), declare and swap them
	int a = 1;
	int b = 2;

	// call the swap_func function that is defined above
	// remember to pass in the address (using '&' aka the 'address of' operator) since
	// 		swap_func takes in pointers. We know this because the * is used in the function
	// 		signature: void swap_func(int * a, int* b) 
	swap_func(&a, &b);
	return 0;
}
