//https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1
#include <iostream>
using namespace std;
class Node {
	public : 
	int data;
	Node *left , *right;
};

Node* newNode(int data) {
	Node *temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

//O(N) where N is the number of nodes in the tree
int getMinDepth(Node *root) {
	if(root == NULL) {
		return 0;
	} else {
		int lheight = getMinDepth(root -> left);
		int rheight = getMinDepth(root -> right);
		if(lheight >= rheight && lheight > 1) {
			return rheight + 1;
		}
		return lheight + 1;
	}
}


int main() {
	
	Node *root = NULL;
	root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	root -> right -> left -> left = newNode(8);
	cout << getMinDepth(root);
	
	return 0;
}