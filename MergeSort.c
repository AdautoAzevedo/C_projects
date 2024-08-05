#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	
	//Find sizes of the two subarrays to be merged
	int n1 = mid - left +1;
	int n2 = right - mid;
	
	//Create temp arrays
	int L[n1], R[n2];
	
	//Copy data to temporary arrays
	for (i= 0; i< n1; i++) {
		L[i] = arr[left + i];
	}
	
	for (j = 0; j< n2; j++) {
		R[j] = arr[mid + 1 + j];
	}
	
	//Merge the temp arrays back into arr[]
	i = 0;
	j = 0;
	k = left;
	
	while (i < n1 && j < n2){
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	//Copy the remainig elements of L[] and R[]
	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
	int arr[] = {12, 11, 13, 50, 35, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("\nUnsorted Array: ");
	printArray(arr, size);
	
	mergeSort(arr, 0, size -1);
	
	printf("\nSorted Array: ");
	printArray(arr, size);
	return 0;
}
