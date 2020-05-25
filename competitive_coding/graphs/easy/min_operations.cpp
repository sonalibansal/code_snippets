// https://www.geeksforgeeks.org/minimum-number-operation-required-convert-number-x-y/
#include <iostream>
#include <set>
#include <queue>

using namespace std;

// O(V+E)
int minOperations (int x, int y) {

	queue<pair<int, int> > q;

	set<int> visited;

	pair<int, int> top;

	q.push (make_pair (x, 0));

	while (!q.empty ()) {

		top = q.front ();

		q.pop ();

		if (top.first == y) {
			return top.second;
		}

		visited.insert (top.first);

		if (visited.find (top.first * 2) == visited.end ()) {
			q.push (make_pair (top.first * 2, top.second +1));
		}

		if ((visited.find (top.first - 1) == visited.end ()) && top.first >= 1) {
			q.push (make_pair (top.first - 1, top.second +1));
		}

	}
}



int main () {
	int x = 4, y = 7;

	cout << "Min number of operations = " << minOperations (x, y) << endl;
}

