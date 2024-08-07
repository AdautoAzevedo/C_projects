#include <stdio.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	printf("\n Pivot: %d", arr[pivot]);
	int i = (low -1); // index of smaller element
	int j;
	for (j = low; j <= high -1; j++) {
		printf("\narr[j] dentro do for: %d\n", arr[j]);
		if (arr[j] <= pivot) {
			i++;
			printf("\narr[i] dentro do if: %d\n", arr[i]);
			printf("\narr[j] dentro do if: %d\n", arr[j]);
			swap(&arr[i], &arr[j]);
		}
	}
	printf("\narr[i+1]: %d\n", arr[i+1]);
	printf("\narr[j]: %d\n", arr[j]);
	swap(&arr[i+1], &arr[j]);
	return (i+1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
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
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array: \n");
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
	
}
