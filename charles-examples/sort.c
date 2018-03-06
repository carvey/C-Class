#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int int_a = * ( (int*) a );
	int int_b = * ( (int*) b );

	if ( int_a == int_b ) return 0;
	else if ( int_a < int_b ) return -1; // Change the < sign to a > sign to reverse the sorting
	else return 1;
}

int main(void) {
	// this is the array that will be sorted
	// Remember it is size 10, so you can only access elements[0] through elements[9]
	int elements[10] = { 3, 6, 1, 9, 8, 2, 0, 5, 7, 4 };

	// Parameters:
	// 1) First param is the array to be sorted
	// 2) Next is the number of elements to sort
	// 3) Third is the size of each element that you are sorting
	// 4) Fourth is the comaparison function used to sort the elements of the array
	qsort(elements, 10, sizeof(int), compare);

	// Print out each sorted element
	for (int i = 0; i < 10; i++) {
		printf("%d\n", elements[i]);
	}
}
