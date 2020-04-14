// #include<bits/stdc++.h> 
#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
};


//Adding the node at the starting 
void push(Node** head,int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
	return;
}

void insertAfter(Node* prevNode, int data){
	if(prevNode == NULL){
	cout<<"Previous node reference cannot be NULL";
	return;
	}
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	return;
}

void insertAtTheEnd(Node** head,int data){

	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL){
		*head = newNode;
		return;
	}
	Node* last = *head;
	while(last->next!=NULL){
		last = last->next;
	}

	last->next = newNode;
	return;

}

void printList(Node* head){
	while(head!= NULL){
		cout<<head->data<<"->";
		head = head->next;
	}	
}

int main(){

	Node* head= NULL;
	push(&head,1);

	insertAtTheEnd(&head,8);

	insertAfter(head->next,9);

	push(&head,2);

	insertAtTheEnd(&head,10);

	printList(head); //2->1->8->9->10


	return 0;	
}


// 2->1->9->7->8->10