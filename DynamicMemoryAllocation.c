#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr;
	int n, i;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	//Dynamically allocate memory using malloc
	//Aloocates a specified number of bytes and returns a pointer to the first byte of the allocated space
	arr = (int*)malloc(n * sizeof(int));
	
	if (arr == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}
}
