#include <stdio.h>
#include <stdlib.h>

//Define the node structure
struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

//Function create a new node
struct TreeNode* newNode(int data) {
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); //create a new node in memory
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inorderTraversal(struct TreeNode* node) {
	if (node != NULL) {
		inorderTraversal(node->left);
		printf("%d ", node->data);
		inorderTraversal(node->right);
	}
}

int main() {
	struct TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	printf("Inorder traversal of the binary tree:\n");
	inorderTraversal(root);
	
	return 0;
}

