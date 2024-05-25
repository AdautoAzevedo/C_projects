#include <stdio.h>
#include <stdlib.h>

int main() {
	int var = 100;
	int *pointer = &var;
	
	printf("Value of var: %d\n", var);
	printf("Value of memory address of var: %d\n", pointer);
	printf("Value of var by dereferencing: %d\n",*pointer);
	
	//Pointer arithmetic
	int arr[5] = {10,20,30,40,50};
	int *p = arr;
	printf("%d\n", p);
	printf("%d\n", *p);
	int i;
	for(i = 0; i < 5; i++) {
		printf("Element %d: %d\n", i, *p);
		p++;
	}
	
	//Pointer to pointer
	int **pp = &pointer;
	printf("Value of var using a pointer to pointer: %d\n", **pp);
	
}

