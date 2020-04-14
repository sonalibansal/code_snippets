#include <iostream>

using namespace std;

class Node{	
public:
	int data;
	Node* next;
};

void deleteNode(Node* head,int data){
	Node* temp = head, *prev;
	if(head!= NULL && head->data == data){
		head = head->next;
		return;
	}

	while(temp!= NULL && temp->data!= data){
		prev = temp;
		temp = temp->next;
	}

	if(temp ==NULL){
		return;
	}
	prev->next = temp->next;
}

void deleteNodeAtGivenPositon(Node* head, int position){
	if(head == NULL)
		return;

	Node *temp = head, *prev;
	if(position ==0){
		head = head->next;
		free(temp);
		return;
	}

	int count = 0;
	while(temp!= NULL && count!=position){
		prev = temp;
		temp  = temp->next;
		count++;
	}

	if(temp==NULL){
		cout<<"positon is greater than the length of the linked list";
		return;
	}

	prev-> next = temp->next;
	free(temp);
	return;
}

//Adding the node at the starting 
Node* push(Node* head, int data){

	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	return newNode;
}

void printList(Node* head){
	while(head!= NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	return;	
}

int main(){

	Node* head= NULL;
	head = push(head, 1);
	head = push(head,2);
	head = push(head,3);
	head = push(head,4);

	//cout<<"Printing list before deletion";
	printList(head);

	deleteNode(head, 3);
	printList(head);

	deleteNodeAtGivenPositon(head,1);

	printList(head);

	return 0;
}