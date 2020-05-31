//https://www.geeksforgeeks.org/recursive-approach-alternating-split-linked-list/

#include <iostream>
#include <vector>
using namespace std;

class Node {
	public :

	int data;
	Node *next;
};

Node * push (Node *head, int data) {
	Node *newNode = new Node();
	newNode -> data = data;
	newNode -> next = head;

	return newNode;
}

// O(N) where N is the number of nodes
void printList (Node *curr, vector<int> &odd, vector<int> &even, int flag) {

	if (curr == NULL) {
		return;
	}

	if (flag) {
		odd.push_back (curr -> data);
	} else {
		even.push_back (curr -> data);
	}

	printList (curr -> next, odd, even, 1-flag);
}


int main() {
	Node *head = NULL;
	// Input : 10 -> 9->8->3->5->2->1 , k = 4
	// Output : 9-> 3 -> 2
	head = push (head, 1);
	head = push (head, 2);
	head = push (head, 5);
	head = push (head, 3);
	head = push (head, 8);
	head = push (head, 9);
	head = push (head, 10);
	
	vector<int> odd, even;

	printList (head, odd, even, 1);

	for (int i = 0; i < odd.size () ; i++) {
		cout << odd[i] << " ";
	}

	cout << endl;
	for (int i = 0 ; i < even.size () ; i++) {
		cout << even[i] << " ";
	}

	// 10 8 5 1 
	// 9 3 2

	return 0;
}