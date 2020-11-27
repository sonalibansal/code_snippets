//https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1
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
int X = 7,count = 0;

//O(N) where N is the number of nodes in the tree
int countSubTrees(Node *root) {
	int sum = 0;
	if(root == NULL) {
		return 0;
	} else {
		sum = root -> data;
		if(root -> left != NULL) {
			sum = sum + countSubTrees(root -> left);
		}
		if(root -> right != NULL) {
			sum = sum + countSubTrees(root -> right);
		}
	}
	if(sum == X) {
		count ++;
	}
	return sum;
}

int main() {
	Node *root = newNode(5);
	root -> left = newNode(-10);
	root -> right = newNode(3);
	root -> left -> left = newNode(9);
	root -> left -> right = newNode(8);
	root -> right ->left = newNode(-4);
	root -> right -> right = newNode(7);

	countSubTrees(root);
	cout << count << endl;
	
	count = 0, X = 5;
	Node *root1 = newNode(1);
	root1 -> left = newNode(2);
	root1 -> right = newNode(3);
	
	countSubTrees(root1);
	cout << count << endl;
	return 0;
}