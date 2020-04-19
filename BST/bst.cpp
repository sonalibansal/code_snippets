#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *left, *right;
};

// Time complexity: O(1)
Node* newNode (int data) {

	Node *temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
 }

// Time complexity: O(n) in worst case(skewed BST) and O(h) in avg case.
Node* insert (Node *root, int data) {

	if (root == NULL) {
		return newNode(data);
	 }
	if(data < root->data) {
		root -> left = insert(root -> left, data);
		return root;
	}
	else (data > root -> data) {
		root -> right = insert(root -> right, data);
		return root;
	 }
}

// Time complexity: O(n) where n is the number of nodes
void printPreOrder (Node *root) {
	if (root != NULL) {
		cout << root -> data << "->";
		printPreOrder(root -> left);
		printPreOrder(root -> right);
	 }
}

// Time complexity: O(n) where n is the number of nodes
void printInOrder (Node *root) {
	if (root != NULL) {
		printInOrder( root -> left);
		cout << root -> data << "->";
		printInOrder (root -> right);
	 }
 }

// Time complexity: O(n) where n is the number of nodes
void printPostOrder (Node *root) {

	if(root != NULL) {
		printPostOrder (root -> left);
		cout << root -> data << "->";
		printPostOrder (root -> right);
	 }
 }

//Time complexity : O(n) 
int getBSTHeight (Node *root) {
	if (root == NULL) {
		return 0;
	 } else {
		int lheight = getBSTHeight (root -> left);
		int rheight = getBSTHeight (root -> right);
		if (lheight > rheight) {
			return lheight + 1;
		}
		return rheight + 1;
	}
 }

//Time complexity : O(n) in worst case(skewed tree)
void printGivenLevel (Node *root, int level) {
	if (root == NULL) {
		return;
	 }

	if (level == 1) {
		cout << root -> data << "->";
	} else if (level >1) {
		printGivenLevel (root -> left, level-1);
		printGivenLevel (root -> right, level-1);
	}
	cout << root -> left -> data << "->";
	cout << root -> right -> data << "->";
 }

//Time complexity : O(n^2) in case of skewed tree
void printLevelOrderTraversal (Node *root) {
	int height = getBSTHeight (root);

	for (int i=1 ; i <= height ; i++) {
		printGivenLevel(root,i);
	 }
 }

//Time complexity : O(n)
Node* minValueNode (Node *root) {
	Node *curr = root;
	while (curr && curr -> left != NULL)
		curr = curr->left;
	return curr;
 }

//Time complexity : O(n)
Node* deleteNode (Node* root, int data) {
	if (root == NULL) {
		return root;
	 }
	if(data < root -> data) {
		root -> left= deleteNode (root -> left, data);
		return root;
	 }
		
	if(data > root -> data) {
		root->right = deleteNode(root->right,data);
		return root;
	} else {
		if (root -> left == NULL) {
			Node *temp = root -> right;
			free (root);
			return temp;
		 }
		else if(root -> right == NULL) {
			Node *temp = root -> left;
			free(root);
			return temp;
		}
		Node *temp = minValueNode (root -> right);
		root -> data = temp -> data;
		root -> right = deleteNode (root -> right, temp -> data); 
	}
}

int main() {

	Node *root = NULL;
	root = insert (root, 4);
	root = insert (root, 5);
	root = insert (root, 12);
	root = insert (root, 10);
	root = insert (root, -1);
	root = insert (root, 20);
	root = insert (root, 50);

	cout << "PreOrder traversal \n";
	printPreOrder (root); //4->-1->5->12->10->20->50->

	cout << "Inorder traversal \n";
	printInOrder (root); //-1->4->5->12->10->20->50->

	cout << "PostOrder traversal \n";
	printPostOrder (root); //-1->4->5->12->10->20->50

	root = deleteNode (root, 50);
	root = deleteNode (root, 4);
	root = deleteNode (root, 12);

	cout << "Inorder traversal after deletion \n";
	printInOrder (root);  //-1->5->20->10->
	return 0;
 }