#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
	int data[TAM];
	int top;
} Stack;

Stack stack;

void push(int number) {
	if (stack.top == TAM) {
		printf("\n Stack overflow\n");
		system("pause");
	} else {
		printf("Number added: %d\n", number);
		stack.data[stack.top] = number;
		stack.top++;
	}
}

void pop() {
	if (stack.top == -1) {
		printf("\n Stack underflow\n");
		system("pause");
	} else {
		printf("\nValue of stack[%d] before removal: %d\n", stack.top-1, stack.data[stack.top-1]);
		stack.data[stack.top-1] = 0;
		printf("Value of stack[%d] after removal: %d\n", stack.top-1, stack.data[stack.top-1]);
		stack.top--;
	}
}

int main() {
	stack.top = 0;
	
	push(10);
	push(20);
	push(30);
	
	pop();
	pop();
	pop();
}

