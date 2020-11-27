//https://practice.geeksforgeeks.org/problems/vertical-sum/1
#include <iostream>
#include <map>
using namespace std;
#define V 4
map<int, int> m;
class Node {
	public : 
	int data;
	Node *left, *right;
};

Node *newNode(int data) {
	Node *temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void verticalSum(Node* root, int level) {
	if(root == NULL) {
		return;
	}
	verticalSum(root ->left, level - 1);
	m[level] = m[level] + root ->data;
	verticalSum(root ->right, level + 1);
}

void calculateSum(Node *root) {
	verticalSum(root, 0);
	map<int, int> ::iterator it;
	for(it = m.begin(); it != m.end() ;it++) {
		cout << it->second << " ";
	}
}
int main() {
	Node *root = NULL;
	root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left= newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	calculateSum(root);
	return 0;
}