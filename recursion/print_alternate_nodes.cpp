//https://www.geeksforgeeks.org/print-alternate-nodes-linked-list-using-recursion/
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


// O(N) where N is the number of nodes
void printList (Node *curr, int flag) {
	if (curr == NULL) {
		return;
	}
	if (flag) {
		cout << curr -> data << " ";
	}
	printList (curr -> next, 1- flag);	
}

int main () {
	Node *head = NULL;


	// Input : 9->8->3->5->2->1 , k = 4
	// Output : 9-> 3 -> 2
	head = push (head, 1);
	head = push (head, 2);
	head = push (head, 5);
	head = push (head, 3);
	head = push (head, 8);
	head = push (head, 9);
	int flag = 1;
	Node * curr = head;
	printList (head, flag);

}