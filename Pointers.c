#include <stdio.h>
#include <stdlib.h>

int main() {
	int var = 100;
	int *pointer = &var;
	
	printf("Value of var: %d\n", var);
	printf("Value of memory address of var: %d\n", pointer);
	printf("Value of var by dereferencing: %d\n",*pointer);
	
	//Pointer arithmetic
	int arr[5] = {1,2,3,4,5};
	int *p = arr;
	int i;
	for(int i = 0; i < 5; i++) {
		printf("Element %d: %d\n", i, *p);
		p++;
	}
	
}

