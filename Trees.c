#include <stdio.h>
#include <stdlib.h>

//Define the node structure
typedef struct {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

//Function create a new node
TreeNode* newNode(int data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); //create a new node in memory
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void preorderTraversal(TreeNode* node) {
	if (node == NULL) return;
	printf("%d ", node->data); //Visit the root
	preorderTraversal(node->left); //Traverse the left subtree
	preorderTraversal(node->right); //Traverse the right subtree
}

void inorderTraversal(TreeNode* node) {
	if (node != NULL) {
		inorderTraversal(node->left); // Traverse the left subtree
		printf("%d ", node->data); //Visit the root
		inorderTraversal(node->right); // Traverse the right subtree
	}
}

void postorderTraversal(TreeNode* node) {
	if (node == NULL) return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	printf("%d ", node->data);
}

int main() {
	TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	printf("preorder traversal of the binary tree:\n");
	preorderTraversal(root);
	
	printf("Inorder traversal of the binary tree:\n");
	inorderTraversal(root);
	
	printf("Postorder traversal of the binary tree:\n");
	postorderTraversal(root);
	
	return 0;
}

