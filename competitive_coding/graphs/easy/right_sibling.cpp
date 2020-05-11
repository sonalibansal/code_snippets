#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 7
vector<int> adj[V];


//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
}

// O(V+E) 
void rightSibling (int src) {

	vector<bool> visited(V+1, false);

	int top;
	queue<int> q;
	visited [src] = true;
	q.push (src);
	q.push (-1);

	while (!q.empty ()) {
		top = q.front ();
		q.pop ();

		if (top == -1) {
			if (!q.empty ()) {
				q.push (-1);
			}
		} else {
			cout << top << " - " << q.front () << endl;
			for (int i = 0 ; i < adj[top].size () ; i++) {
				if (!visited[adj[top][i]]) {
					visited[adj[top][i]] = true;
					q.push (adj[top][i]);
				 }
			 }
		}	
	}

}

int main () {

	addEdge (1,2);
	addEdge (1,3);
	addEdge (2,4);
	addEdge (2,5);
	addEdge (3,6);
	addEdge (3,7);

	rightSibling (1);

	return 0;
}