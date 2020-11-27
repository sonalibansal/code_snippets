#include <iostream>
#include <queue>
using namespace std;
class Node {
	public:
	int data;
	Node *left, *right;
};

Node* newNode(int data) {
	Node *temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void print(Node* root) {
	if(root == NULL) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0 ; i < size ; i++) {
			Node* top = q.front();
			q.pop();
			if(i == 0 || i == size-1) {
				cout << top -> data << " ";
			}
			if(top -> left != NULL) {
				q.push(top -> left);
			}
			if(top -> right != NULL) {
				q.push(top -> right);
			}
		}
	}
}
int main() {
	Node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	//root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	//root -> right -> right = newNode(5);
	
	print(root);
	return 0;
}