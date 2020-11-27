//https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
#include <iostream>
using namespace std;

//int pre[] = {40,30,35,80,100};
int pre[] = {40, 30, 32, 35, 80, 90, 100, 120};
int n = 8;
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

Node* construct(int preIndex, int start, int end) {
	if(preIndex >= n || start > end) {
		return NULL;
	}
	Node *root = newNode(pre[preIndex]);
	preIndex ++;
	
	if(start == end) {
		return root;
	}
	int i;
	for(i = start ; i <= end ;i++) {
		if(pre[i] > root -> data) {
			break;
		}
	}
	root -> left = construct(preIndex, preIndex, i-1);
	root -> right = construct(i, i, end);
	return root;
}

void printPostOrder(Node *root) {
	if(root == NULL) {
		return;
	}
	printPostOrder(root -> left);
	printPostOrder(root -> right);
	cout << root -> data << " ";
}

//O(nlog(n))
void preOrderToPostOrder() {
	Node *root = construct(0, 0, n-1);
	printPostOrder(root);
}

int main() {
	preOrderToPostOrder();
	return 0;
}