#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myFunc(const char *path, const int lineNumber, char *buffer) {

      FILE *stream;
      char *line = NULL;
      size_t len = 0;
      ssize_t nread;
      size_t line_count = 0;
      size_t numBytes = 0;

      stream = fopen(path, "r");
      if (stream == NULL) {
             perror("fopen");
             exit(EXIT_FAILURE);
      }

      while ((nread = getline(&line, &len, stream)) != -1) {
          // uncomment this next line to see what this while loop is doing
          //printf("Line #%d: %s", ++line_count, line);

          if (++line_count == 12) {
          	  memset(buffer, 0, 55);
          	  strncpy(buffer, line, nread);
          	  numBytes = nread;
          }
      }

	  // print out whats in buffer and the number of bytes that were put in
      printf("%s: %d\n", buffer, numBytes);

      free(line);

      fclose(stream);
	  return numBytes;
}

int
main(int argc, char *argv[])
{
	const char *path = "file_input.txt";
	char buf[55] = {};
	myFunc(path, 12, buf);
	exit(EXIT_SUCCESS);
}

