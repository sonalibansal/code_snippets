#include <iostream>
using namespace std;

class Node {
	public:
	 int data;
	 Node *next;
 };

//Adding the node at the starting 
Node* push (Node* head, int data) {

	Node* newNode = new Node();
	newNode -> data = data;
	newNode -> next = head;
	return newNode;
 }

void insertAfter (Node* prevNode, int data){
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

Node* insertAtKthPostion(Node* head,int data, int position){

	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL && position==0){
		head = newNode;
		return head;
	}
	else if (head == NULL && position!=0){
		return head;
	}
	else if(head!= NULL && position==0){
		newNode->next = head;
		head = newNode;
		return head;
	}
	Node* temp = head;
	int count = 0;
	while(temp->next!=NULL && count<position-1){
		temp = temp->next;
		count++;
	}

	newNode->next = temp->next;
	temp->next = newNode;
	return head;

}

void printList(Node* head){
	while(head!= NULL){
		cout<<head->data<<"->";
		head = head->next;
	}	
}

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

int main(){

	Node* head= NULL;
	head = push(head,1);

	insertAtTheEnd(&head,8);

	insertAfter(head->next,9);

	head = push(head,2);

	insertAtTheEnd(&head,10);

	printList(head); //2->1->8->9->10

	head = insertAtKthPostion(head,5,2);
	printList(head);

	deleteNode(head,8);
	printList(head);

	deleteNodeAtGivenPositon(head,1);
	printList(head);
	return 0;	
}
