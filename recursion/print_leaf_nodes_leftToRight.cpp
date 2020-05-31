//https://www.geeksforgeeks.org/print-leaf-nodes-left-right-binary-tree/
#include <iostream>
using namespace std;


class Node
{
public:
	int data;
	Node *left, *right;
	
};


Node* newNode (int data) {
	Node *newNode = new Node ();
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

// O(N) where N is the number of nodes in the binary tree
void DFS (Node *curr) {

	if (curr == NULL) {
		return;
	}
	if (curr -> left == NULL && curr -> right == NULL) {
		cout << curr -> data << " ";
	}

	if (curr -> left) {
		DFS (curr -> left);
	}

	if (curr -> right) {
		DFS (curr -> right);
	}
}

int main () {

	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(8); 
    root->right->left->left = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->left = newNode(9); 
    root->right->right->right = newNode(10); 

    Node *curr = root;

    DFS (curr);

    return 0;
}