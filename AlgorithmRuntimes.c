#include<stdio.h>
#include<stdlib.h>

int main(
	//Constant Time O(1)
	//Example: Accessing an element in a array by index
	int getElementAtIndex(int arr[], int index) {
		return arr[index];
	}
	
	//Logarithmic Time O(log n)
	//Example: Binary Search
	int binarySearch(int arr[], int size, int target) {
		int left = 0;
		int right = size - 1;
		while(left <= right) {
			int mid = left +(right-left) / 2;
			if (arr[mid] == target) return mid;
			if (arr[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}
	
	//Linearithmic Time O(n log n)
	//Example: Merge sort
	
	//Quadratic Time O(n^2)   tips: Usually have nested loops (n*n)
	//Example: Bubble Sort
	void bubbleSort(int arr[], int size) {
		
	}
	
	//Cubic Time O(n^3)   (n*n*n)
	//Example: Multiplying two matrices (naive approach) 
	
	//Exponential Time O(2^n)
	//Example Solving the towers of Hanoi problem
	
	//Factorial time O(n!)
	//Example: enerating all permutation of a set
)
