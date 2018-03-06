#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <argp.h>

int main (int argc, char **argv)
{
  char *fvalue = NULL;
  char *nvalue = NULL;
  char *lvalue = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "f:n:l:")) != -1)
    switch (c)
      {
            case 'f':
              fvalue = optarg;
              break;
            case 'n':
              nvalue = optarg;
              break;
            case 'l':
              lvalue = optarg;
              break;
            case '?':
              if (optopt == 'c')
                fprintf (stderr, "Option -%c requires an argument.\n", optopt);
              else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
              else
                fprintf (stderr, "Unknown option character `\\x%x'.\n",
                		                                      optopt);
              return 1;
            default:
              abort ();
            }

  //printf ("fvalue = %d, nvalue = %d, lvalue = %s\n", fvalue, nvalue, lvalue);

  if (fvalue)
  	  printf("%s\n", fvalue);

  if (nvalue)
  	  printf("%s\n", nvalue);

  if (lvalue)
  	  printf("%s\n", lvalue);

  for (index = optind; index < argc; index++)
    printf ("%s\n", argv[index]);
  return 0;
}
