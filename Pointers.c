#include <stdio.h>
#include <stdlib.h>

int main() {
	int var = 100;
	int *pointer = &var;
	
	printf("Value of var: %d\n", var);
	printf("Value of memory address of var: %d\n", pointer);
	printf("Value of var by dereferencing: %d\n",*pointer);
}

