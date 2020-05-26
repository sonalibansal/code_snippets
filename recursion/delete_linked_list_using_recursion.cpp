//https://www.geeksforgeeks.org/delete-linked-list-using-recursion/
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

void deleteLinkedList (Node * head) {
	if(head == NULL){
		return;
	}
	deleteLinkedList (head -> next);
	cout << "deleting " << head -> data << endl;
	free (head);
}

int main () {
	Node *head = NULL;
	// Input : 9->8->3->5->2->1 
	head = push (head, 1);
	head = push (head, 2);
	head = push (head, 5);
	head = push (head, 3);
	head = push (head, 8);
	head = push (head, 9);

	Node *curr = head;
	deleteLinkedList (head);

	cout << "Linked list deleted" << endl;
	

}