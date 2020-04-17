#include <iostream>
#include <climits>
using namespace std;

class  Node {
	public :
	 int data;
	 Node *left, *right;

};

Node* newNode (int data) {
	Node *newNode = new Node();
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL; 
	return newNode;
 }

void minHeapifyUp (Node *temp, int data) {

	while (temp != root && arr[parent(position)] > data) {
 		swap(& arr[parent(position)], & arr[position]);
 		position = parent(position);
 	 }
}

 void insert (Node* root, int key) {

 	if (root == NULL) {
 		root = newNode (key);
 	 }

 	if (root -> left == NULL) {
 		root ->left = newNode(key);
 		return minHeapifyUp (root, key);
 	}

 	if (root -> right == NULL) {
 		root -> right = newNode(key);
 		return minHeapifyUp (root, key);
 	}

 	insert (root -> left, key);
 	insert (root -> right, key);
 	return;
 }


 int getMinElement (Node *root) {

 	if (root == NULL) {
 		cout << "No elements in heap " ;
 		return INT_MAX;
 	 }
 	
 	return root -> data;
 }

 void swap ( Node *x, Node *y) {
 	int temp = x -> data;
 	x -> data = y -> data;
 	y -> data = temp;
 }

 Node* searchElementInBT (Node *root, int data) {
 	if (root == NULL) {
 		cout << "Empty tree" << "\n";
 		return NULL;
 	}

 	if (root != NULL && root ->data == data) {
 		return root;
 	}

 	if (root ->left != NULL) {
 		return searchElementInBT (root -> left, data);
 	 }
 	
 	if (root ->right != NULL) {
 		return searchElementInBT (root -> right, data);
 	}
 }

 void minHeapifyDown (Node *curr) {
 	Node *leftChild = curr -> left;
 	Node *rightChild = curr -> right;
 	Node *smallest = curr;

 	if (leftChild -> next != NULL && leftChild -> data < curr -> data) {
 		smallest = leftChild;
 	 }
 	if (rightChild -> next != NULL && rightChild -> data < curr -> data) {
 		smallest = rightChild;
 	 }

 	if (smallest != curr) {
 		swap (curr , smallest);
 		minHeapifyDown (smallest);
 	}
 }

 int main()
 {
 	Node *root = NULL; 
 	heap.insert(3);
 	heap.insert(2);
 	heap.deleteKey(1);
 	heap.insert(15);
 	heap.insert(5);
 	heap.insert(4);
 	heap.insert(45);

 	cout << "Minimum element extracted" << heap.extractAndRemoveMinElement() << "\n";
 	cout << "Min element is" << heap.getMinElement() << "\n";

 	heap.updateKeyValue(2,1);

 	cout << "Min element is" << heap.getMinElement() << "\n";
 	return 0;
 }

