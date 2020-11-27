//https://practice.geeksforgeeks.org/problems/k-distance-from-root/1
#include <iostream>
using namespace std;

class Node {
	public :
	int data;
	Node *left, *right;
};

//O(1)
Node* newNode(int data) {
	Node *temp = new Node();
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

//O(N) in case of skewed tree 
int getHeight(Node *root) {
	if(root == NULL) {
		return 0;
	} else {
		int lheight = getHeight(root -> left);
		int rheight = getHeight(root -> right);
		if(lheight >= rheight) {
			return lheight + 1;
		}
		return rheight + 1;
	}
}

//O(log N) average case and in worst case O(N)
void prinGivenLevel(Node *root, int level) {
	if(root == NULL) {
		return;
	}
	if(level == 0) {
		cout << root -> data << " ";
	} else if(level >= 1) {
		prinGivenLevel(root -> left, level-1);
		prinGivenLevel(root -> right, level-1);
	}
}


int main() {
	Node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> right ->left = newNode(5);
	root -> right -> right = newNode(6);
	root -> left -> left ->right = newNode(8);
	
	int treeHeight = getHeight(root);
	int k = 2;
	if(k > treeHeight) {
		cout << "k value more than tree height" << endl;
	} else {
		prinGivenLevel(root, k);
	}
	
	return 0;
}