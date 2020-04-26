#include <iostream>
#include <queue>
using namespace std;

int main() {

	priority_queue <int> q;
	q.push (2);
	q.push (8);
	q.push (3);
	q.push (7);
	q.push (-1);

	while (!q.empty ()) {
		cout << q.top () << " ";
		q.pop ();
	}
}

