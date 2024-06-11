#include <stdio.h>
#include <stdlib.h>

//Dynamic memory allocation allows programs to request memory during runtime.

int main() {
	int *arr;
	int *arrCalloc;
	int n, i;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	//Dynamically allocate memory using malloc
	//Allocates a specified number of bytes and returns a pointer to the first byte of the allocated space
	arr = (int*)malloc(n * sizeof(int));
	
	//Check if the memory allocation was sucessfull
	if (arr == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	for (i = 0; i< n; i++) {
		arr[i] = i+1;
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	
	//Calloc alllocates memory for an array of elements and initializes all bytes to zero
	arrCalloc = (int*)calloc(n, sizeof(int));
	
	if (arrCalloc == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		printf("%d ", arrCalloc[i]); //Will print 0.
	}
	printf("\n");
	
	//Reallocate memory
	//Changes the size of the previously allocated memory block. 
	n = 10;
	arr = (int*)realloc(arr, n * sizeof(int));
	
	if (arr == NULL) {
		printf("Memory reallocation failed!\n");
		return 1;
	}
	
	for (i = 5; i < n;i++) { 
        arr[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
	
	//Deallocate the memory
	free(arr);
	free(arrCalloc);
}
