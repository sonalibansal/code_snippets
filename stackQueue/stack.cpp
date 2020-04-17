#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Time complexity : O(n) where n is the number of elements in the stack 
void printStackElement (stack<int> s) {

	if (s.empty()) {
		return;
	 }
	 
	int top = s.top ();
	s.pop ();
	printStackElement (s);

	cout << top << " ";

	s.push (top);
}

//Time complexity : O(n) where n is the number of elements in the queue 
void printQueueElemt (queue<int> q) {

	if (q.empty ()) {
		return;
	 }

	int top = q.front ();
	q.pop ();

	cout << top << " ";

	printQueueElemt (q);
	q.push (top);
}

int main () {
	stack<int> sampleStack ;
	sampleStack.push (2); //O(1)
	sampleStack.push (3);
	sampleStack.push (8);
	sampleStack.push (9);	

	cout << "Stack size " << sampleStack.size() << "\n"; //O(n)

	printStackElement (sampleStack); //O(n)
	sampleStack.pop (); //O(1)

	cout << "New stack size " << sampleStack.size() << "\n";
	cout << "Stack top element " << sampleStack.top () << "\n"; //O(1)

	queue<int> queue;
	queue.push (2); //O(1)
	queue.push (3);
	queue.push (4);
	queue.push (5);
	printQueueElemt (queue);

	cout << "queue first element " << queue.front() << "\n" ; //O(1)
	cout << "queue last element " << queue.back() << "\n"; //O(1)
	cout << "queue size " << queue.size() << "\n"; //O(n)

	queue.pop ();

	cout << "new queue size " << queue.size() << "\n";
	cout << "updated queue first element " << queue.front() << "\n" ;
	cout << "updated queue last element " << queue.back() << "\n";

 }