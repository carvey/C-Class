#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(const void* a, const void* b);

int main(void)
{
  int array[1024] = { 0 };

  /* Fill array with random numbers */
  srand((unsigned)time(NULL));

  int index;
  for(index = 0; index < 1024; index++)
    array[index] = rand() % 100;
  /* ------------------------------- */\

  qsort(array, 1024, sizeof(int), compare);
  for (int i = 0; i < 1024; i++) {
  	  printf("%d\n", array[i]);
  }
  return 0;
}

int compare(const void* a, const void* b)
{
	int int_a = * ( (int*) a );
	int int_b = * ( (int*) b );

	if ( int_a == int_b ) return 0;
	else if ( int_a > int_b ) return -1;
	else return 1;
}
