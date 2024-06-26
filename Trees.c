#include <stdio.h>
#include <stdlib.h>

//Define the node structure

typedef struct Node{
	int data;
	struct node* left;
	struct node* right;
} Node;

Node* createNode(int val) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insertNode(Node* root, int data) {
	if (root == NULL) {
		root = createNode(data);
		return root;
	}
	
	if (data < root->data) {
		root->left = insertNode(root->left, data);
	} else if (data > root->data) {
		root->right = insertNode(root->right, data);
	}
	
	return root;
}

//In-order Taversal: Left, Root, right
void inOrderTraversal(Node* root) {
	if (root != NULL) {
		inOrderTraversal(root->left);
		printf("%d ", root->data);
		inOrderTraversal(root->right);
	}
}

//Pre-order traversal: Root, Left, Right
void preOrderTraversal(Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void postOrderTraversal(Node* root) {
	if (root != NULL) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		printf("%d ", root->data);
	}
}

int main() {
	Node* root = NULL;
	root = insertNode(root, 50);
	insertNode(root, 30);
	insertNode(root, 70);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 60);
	insertNode(root, 80);
	
	printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");
	
	return 0;	
}


