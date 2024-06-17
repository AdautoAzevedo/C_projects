#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
	int key;
	int value;
	struct Node* next;
} Node;

typedef struct {
	Node* table[TABLE_SIZE];
} HashTable;

int hashFunction(int key) {
	return key % TABLE_SIZE;
}

HashTable* createTable() {
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	int i;
	for(i = 0; i< TABLE_SIZE; i++) {
		newTable->table[i] = NULL;
	}
	return newTable;
}

void insert(HashTable* hashTable, int key, int value) {
	int index = hashFunction(key);
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = hashTable->table[index]; //NULL
	hashTable->table[index] = newNode;
}

int search(HashTable* hashTable, int key) {
	int index = hashFunction(key);
	Node* current = hashTable->table[index];
	while (current != NULL) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
	}
	return -1;
}

void printTable(HashTable* hashTable){
	int i;
	for (i = 0; i< TABLE_SIZE; i++) {
		printf("Index %d: ", i);
		Node* current = hashTable->table[i];
		while (current != NULL) {
			printf("-> (Key: %d, Value: %d)", current->key, current->value);
			current = current->next;
		}
	printf("\n");
	}
}

int main() {
	HashTable* hashTable = createTable();
	insert(hashTable, 1, 10);
	insert(hashTable, 2, 20);
	insert(hashTable, 12, 30);
	insert(hashTable, 22, 40);
	
	
	printTable(hashTable);
	
	printf("Value for key 2: %d\n", search(hashTable, 2));
	printf("Value for key 12: %d\n", search(hashTable, 12));
	
	return 0;
}
