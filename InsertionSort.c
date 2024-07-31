#include <stdio.h>

void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i-1;
		printf("\ni: %d",i);
		printf("\nj: %d",j);
		while (j>=0 & arr[j] > key) {
			printf("\narr[j]: %d e key: %d", arr[j], key);
			arr[j+1] = arr[j];
			j = j-1;
		}
		printf("\n");
		printArray(arr, n);
		printf("\nvalores de arr[j+1]: %d e key: %d", arr[j+1], key);
		arr[j+1] = key;
		printf("\n");
		printArray(arr, n);
		
	}
}

void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {12, 11, 13, 5, 6};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted array: \n");
	printArray(arr, size);
	insertionSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);
	return 0;
}
