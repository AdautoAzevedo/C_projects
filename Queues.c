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
	return queue.front == -1;
}

int isFull() {
	return queue.rear == MAX-1;
}

void enqueue(int value) {
	if (isFull()) {
		printf("Queue overflow\n");
		return;
	}
	
	if (isEmpty()) {
		queue.front = 0;
	}
	
	queue.rear++;
	queue.data[queue.rear] = value;
	printf("Enqueued: %d\n", queue.data[queue.rear]);
	
}

void dequeue() {
	if (isEmpty()) {
		printf("\nQueue underflow");
		system("pause");
	} 
	
	printf("\nDequeued: %d\n", queue.data[queue.front]);
	queue.front++;
	
}

int main() {
	queue.front = -1;
	queue.rear = -1;
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	
	dequeue();
	dequeue();
	dequeue();
	
}
