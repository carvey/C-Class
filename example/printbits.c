#include <stdio.h>

void printbits(void* base, size_t size) {
	int num = *(unsigned *)base;
	for (unsigned i = 1 << 7; i > 0; i = i / 2) {
		(num & i) ? printf("1") : printf("0");	
	}
	printf("\n");
}


int main() {
	for (unsigned char i = 0; i < 10; i++) {
		printbits(&i, sizeof i);
	}
	return 0;
}
