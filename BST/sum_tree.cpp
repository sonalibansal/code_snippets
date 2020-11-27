//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
#include <iostream>
using namespace std;

class Node {
	public :
	int data;
	Node *left, *right;
};

//O(1)
Node* newNode(int data) {
	Node *temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

int sumTree(Node *root) {
	if(root ->left == NULL && root ->right == NULL) {
		root ->data =  0;
		return root -> data;
	}
	root -> data = 0;
	if(root -> left != NULL) {
		root -> data = root -> data + root ->left ->data + sumTree(root ->left);
	}
	if(root -> right != NULL) {
		root -> data = root -> data + root -> right ->data + sumTree(root -> right);
	}
	return root -> data;
}

void printInOrder(Node *root) {
	if(root != NULL) {
		cout << root -> data << " ";
		printInOrder(root->left);
		printInOrder(root->right);
	}
}

int main() {
	Node *root = newNode(10);
	root -> left = newNode(-2);
	root -> right = newNode(6);
	root -> left -> left = newNode(8);
	root -> left -> right = newNode(-4);
	root -> right ->left = newNode(7);
	root -> right -> right = newNode(5);

	printInOrder(root);
	cout << endl;
	sumTree(root);
	
	printInOrder(root);

	return 0;
}