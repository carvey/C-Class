#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	size_t size;
	int count;

	fp = fopen("/usr/share/dict/words", "r");
	size = 102305;

//	printf("%d\n", size);

	char *words[size];

	count = 0;	
	while((nread = getline(&line, &len, fp)) != -1) {
		//printf("%s\n", line);
		words[count] = (char *)calloc(35, sizeof(char));
		char *p = strchr(line, '\n');
		if (p != NULL) *p = '\0';
		strncpy(words[count], line, 33);
		count += 1;
	}


	for (int i = 0; i < size; i ++) {
		for (int k = 0; k < size; k++) {
			printf("Bob\n");
			printf("%s%s\n", words[i], words[k]);
		}
	}



	return 0;
}
