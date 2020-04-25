#include <iostream>
#include <climits>
using namespace std;

class  Node {
	public :
	 int data;
	 Node *left, *right , *parent;

};

Node* newNode (int data, Node *parent) {
	Node *newNode = new Node();
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL; 
	newNode -> parent = parent;
	return newNode;
 }

 void swap ( int * x, int *y) {
 	int temp = *x ;
 	*x = *y ;
 	*y = temp;
 }

void minHeapifyUp (Node *temp, int data) {

	while (temp -> parent != NULL && temp -> parent -> data > data) {
 		swap(&temp -> data, &temp -> parent -> data);
 		temp = temp -> parent;
 	 }
 	 return ;
}

 Node* insert (Node* root, int key) {

 	if (root == NULL) {
 		root = newNode (key, NULL);
 		return root;
 	 }

 	if (root -> left == NULL) {
 		root -> left = newNode(key, root);
 		minHeapifyUp (root -> left, key);
 		return root;
 	}

 	if (root -> right == NULL) {
 		root -> right = newNode(key, root);
 		minHeapifyUp (root -> right, key);
 		return root;
 	}

 	insert (root -> left, key);
 	insert (root -> right, key);
 	return root;
 }

 void minHeapifyDown (Node* curr) {
 	Node *leftChild = curr -> left;
 	Node *rightChild = curr -> right;
 	Node *smallest = curr;

 	if (leftChild -> data < curr -> data) {
 		smallest = leftChild;
 	 }
 	if (rightChild -> data < curr -> data) {
 		smallest = rightChild;
 	 }

 	if (smallest != curr) {
 		swap (curr , smallest);
 		minHeapifyDown (smallest);
 	}
 }

 void deleteKey (Node* root) {
 	cout << "Top most element is :" << root -> data;
 	root -> data = INT_MAX;
 	minHeapifyDown (root);	
 }

 int getMinElement (Node* root) {

 	if (root == NULL) {
 		cout << "No elements in heap " ;
 		return INT_MAX;
 	 }
 	
 	return root -> data;
 }


 int main()
 {
 	Node *root = NULL; 
 	root = insert(root, 3);
 	cout << "Min element is" << getMinElement(root) << "\n";

 	root = insert(root, 2);
 	cout << "Min element is" << getMinElement(root) << "\n";

 	cout << "Root data" << root -> data;
 	deleteKey(root);

 	root = insert(root, 15);
 	root = insert(root, 5);
 	root = insert(root, 4);
 	root = insert(root, 45);
 	root = insert(root, 1);


 	//printLevelOrder (root);

 	cout << "Min element is" << getMinElement(root) << "\n";

 	cout << "Min element is" << getMinElement(root) << "\n";
 	return 0;
 }

