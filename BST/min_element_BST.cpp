//https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
#include <iostream>
using namespace std;

class Node {
	public :
	int data;
	Node *left, *right ;
};

Node* newNode(int data) {
	Node* temp = new Node();
	temp -> data = data;
	temp ->left = NULL;
	temp -> right = NULL;
	return temp;
};

int minElement(Node *root) {
	if (root == NULL) {
		return -1;
	}
	//cout << root -> data << endl;
	if(root -> left == NULL) {
		return root -> data;
	}
	return minElement(root -> left);
}

int main() {
	Node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> right -> left = newNode(4);
	root -> right -> right = newNode(6);
	root -> right ->left -> right = newNode(5);
	root -> right ->left -> right -> left = newNode(7);
	
	cout << minElement(root) << endl;
	
	Node *root1 = newNode(5);
	root1 -> left = newNode(4);
	root1 -> right = newNode(6);
	root1 -> left -> left = newNode(3);
	root1 -> right -> right = newNode(7);
	root1 -> left -> left -> left = newNode(1);
	
	cout << minElement(root1) << endl;
	
	Node *root2 = newNode(9);
	root2 ->right = newNode(10);
	root2 -> right ->right = newNode(11);
	cout << minElement(root2) << endl;
	return 0;
}