//https://practice.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
	public:
	int data;
	Node *next;
};

Node* push(Node* head,int data) {
	Node *temp = new Node();
	temp -> data = data;
	temp -> next = head;
	return temp;
}

//O(N + M) where N is the size of first linked list and
// M is the size of second linked list
void printCount(Node *head1, Node *head2, int X) {
	
	Node *curr1 = head1, *curr2= head2;
	unordered_map<int, int> map;
	int count = 0;
	while(curr1) {
		map[curr1 -> data] ++;
		curr1 = curr1 -> next;
	}
	
	while(curr2) {
		if(map.find(X- curr2->data) != map.end()) {
			count = count + map[X-curr2->data];
		}
		curr2 = curr2 -> next;
	}
	cout << count << endl;
	
}

int main() {
	
	Node *head1 = NULL;
	head1 = push(head1, 1);
	head1 = push(head1, 2);
	head1 = push(head1, 3);
	head1 = push(head1, 4);
	head1 = push(head1, 5);
	head1 = push(head1, 6);
	
	Node *head2 = NULL;
	head2 = push(head2, 11);
	head2 = push(head2, 12);
	head2 = push(head2, 13);
	
	int X = 15;
	
	printCount(head1, head2, X);
	
	Node *head3 = NULL;
	head3 = push(head3, 7);
	head3 = push(head3, 5);
	head3 = push(head3, 1);
	head3 = push(head3, 3);
	
	Node *head4 = NULL;
	head4 = push(head4, 3);
	head4 = push(head4, 5);
	head4 = push(head4, 2);
	head4 = push(head4, 8);
	
	X = 10;
	printCount(head3, head4, X);
	return 0;
}