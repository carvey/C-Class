#include<stdio.h>
#include "program.h"

int main(void)
{
  int n[100];
  init_array(&n[0]);

  int sum2 = 0;
  for (int i = 0; i < 100; i++)
  {
  	  //printf("%d\n", *(n+i));
  	  sum2 += *(n+i);
  }

  int* end = (&n[0]+100);
  int* current = &n[0];
  int sum = 0;


  for(;current != end; current++)
  {
  	  sum += *current;
  	  //current += 1;
  }

  printf("%d\n",sum);
  return 0;
}
