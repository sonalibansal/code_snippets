//https://practice.geeksforgeeks.org/problems/mirror-tree/1

#include <iostream>
using namespace std;

class Node {
	public : 
		int data;
		Node *left, *right;
};

Node* newNode(int data) {
	Node* temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void mirror(Node *root) {
	if(root-> left != NULL || root -> right != NULL) {
		Node * temp = root -> left;
		root -> left = root -> right;
		root -> right = temp;
		
		mirror(root -> left);
		mirror(root -> right);
	}
}

void printInOrder(Node *root) {
	if(root != NULL) {
		cout << root -> data << " ";
		printInOrder(root->left);
		printInOrder(root->right);
	}
}

int main() {
	Node * root = newNode(1);
	root -> left = newNode(3);
	root -> right = newNode(2);
	root -> right -> left = newNode(5);
	root -> right -> right = newNode(4);
	
	printInOrder(root);
	cout << endl;
	
	Node *mirrorRoot = root;
	mirror(mirrorRoot);
	printInOrder(mirrorRoot);
	cout << endl;
	
	return 0;
}}