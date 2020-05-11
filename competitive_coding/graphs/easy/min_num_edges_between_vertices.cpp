#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

#define V 7
vector<int> adj[V];

// O(1)
void addEdge(int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


// O(V+E)
int minEdges (int src, int dest) {

	vector<bool> visited (V, false);
	vector<int> dis (V, 0);
	queue<int> q;
	q.push (src);
	visited[src] = true;
	int top, element;

	while (!q.empty ()) {
		top = q.front ();

		q.pop ();

		for (int i = 0 ; i < adj[top].size() ; i++) {
			element = adj[top][i];
			if (!visited[element]) {
				visited[element] = true;
				q.push(element);
				dis[element] = dis[top] + 1;

				if (element == dest) {
					return dis[dest];
				}
			}
		}

	}

	return dis[dest];
}

int main () {

	// addEdge (0,1);
	// addEdge (0,4);
	// addEdge (1,2);
	// addEdge (2,4);
	// addEdge (4,3);
	// addEdge (3,2);

	addEdge (0,1);
	addEdge (0,4);
	addEdge (0,2);
	addEdge (1,2);
	addEdge (2,5);
	addEdge (4,3);
	addEdge (4,5);
	addEdge (4,6);

	cout << minEdges(1, 5) << " " << endl;
	return 0 ;
}
