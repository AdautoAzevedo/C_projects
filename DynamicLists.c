#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* createNode(int data) {
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Creates a node in memory 
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtEnd(struct Node** head, int data) {
	struct Node* newNode = createNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtTheBeginning(struct Node** head, int data) {
	struct Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void printList(struct Node* node) {
	while (node != NULL) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main() {
	struct Node* head = NULL;
	
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 20);
	insertAtEnd(&head, 300);
	
	printf("\nLinked List: ");
	printList(head);
	
	insertAtTheBeginning(&head, 100);
	insertAtTheBeginning(&head, 200);
	insertAtTheBeginning(&head, 0);
	
	printf("\nLinked List: ");
	printList(head);
	return 0;
}

