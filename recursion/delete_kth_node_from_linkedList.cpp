//https://www.geeksforgeeks.org/recursive-function-delete-k-th-node-linked-list/
#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

//Adding the node at the starting 
Node* push(Node* head, int data){

	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	return newNode;
}


void printList (Node *head) {
	Node *curr = head;
	while (curr) {
		cout << curr -> data << " ";
		curr = curr -> next;
	}
}

void deleteNode (Node *curr, Node *prev, int k) {
	if (k == 1) {
		if (curr -> next) {
			prev -> next = curr ->next;
			return ;
		} else {
			cout << "Position for deletion does not exist";
			return;
		}	
	}

	prev = curr;
	curr = curr -> next;
	deleteNode (curr, prev, k-1);
}

int main () {
	Node *head = NULL;


	// Input : 9->8->3->5->2->1 , k = 4
	// Output : 9->8->3->2->1 
	head = push (head, 1);
	head = push (head, 2);
	head = push (head, 5);
	head = push (head, 3);
	head = push (head, 8);
	head = push (head, 9);

	int k = 4;
	Node *curr = head, *prev = NULL;
	deleteNode (curr, prev, k);
	printList (head);

}