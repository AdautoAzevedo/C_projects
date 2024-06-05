#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int data [MAX];
	int front;
	int rear;
} Queue;

Queue queue;
int isEmpty() {
	return queue.front == -1 || queue.front > queue.rear;
}

void enqueue(int value) {
	if (queue.rear == MAX -1) {
		printf("Queue overflow\n");
		return;
	}
	
	if (isEmpty()) {
		queue.front = 0;
	}
	
	queue.data[queue.rear] = value;
	queue.rear++;
	printf("\nResult of operation: \nData Rear value: %d \nRear value: %d ", queue.data[queue.rear-1], queue.rear);
	
}

void dequeue() {
	if (isEmpty()) {
		printf("\nQueue underflow");
		return -1;
	}
	printf("\nValue to be removed: %d", queue.data[queue.front]);
	return queue.data[(queue.front)++];
}

int main() {
	queue.front = -1;
	queue.rear = -1;
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	
	dequeue();
	printf("\nValue of queue.front after removal: %d", queue.front);
	printf("\nValue of first item in array: %d", queue.data[(queue.front)]);
	dequeue();
	printf("\nValue of queue.front after removal: %d", queue.front++);
	printf("\nValue of first item in array: %d", queue.data[(queue.front)]);
	dequeue();
	printf("\nValue of queue.front after removal: %d", queue.front++);
	printf("\nValue of first item in array: %d", queue.data[(queue.front)]);
}
