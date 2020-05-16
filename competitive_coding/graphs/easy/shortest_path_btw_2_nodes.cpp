//https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
#include <iostream>
#include <vector>
#include <utility> 
#include <climits>
#include <queue>
using namespace std;
 
#define V 8
vector<int> adj[V];
vector<int> pred(V , -1);
vector<int> dist(V, INT_MAX);

 // O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}


// O(V+E)
bool shortestPathExists (int src, int dest) {
	vector<bool> visited (V, false);
	queue<int> q;

	dist[src] = 0;
	visited[src] = true;

	int key, top;

	q.push (src);

	while (! q.empty ()) {
		top = q.front ();
		q.pop ();

		for (int i = 0 ; i < adj[top].size () ; i++) {
				key = adj[top][i];
				if (!visited[key]) {
					pred[key] = top;
					dist[key] = dist[top] +1;
					q.push (key);
					if (key == dest) {
						return true;
					}
				} 
			}

	}

	return false;
}

// O(V+E)
void printShortestPath (int src, int dest) {

	if (!shortestPathExists (src, dest)) {
		cout << "source and dest are not connected" << endl;
		return;
	}
	vector<int> path;
	int pos = dest;
	path.push_back (dest);

	// O(V)
	while (pred[pos] != -1) {
		path.push_back (pred[pos]);
		pos = pred[pos];
	}

	cout << "Shortest path length is " << dist[dest] << endl;
	cout << "Path is :" << endl;

	// O(V)
	for (int i = path.size()-1 ; i >= 0 ; i--) {
		cout << path[i] << " ";
	}
}

int main()  {

	addEdge (1,0);
	addEdge (1,2);
	addEdge (0,3);
	addEdge (3,7);
	addEdge (3,4);
	addEdge (7,6);
	addEdge (6,5);
	addEdge (5,4);
	addEdge (4,6);

	printShortestPath(0, 7);  

	// Output :
	// Shortest path length is 2
	// Path is :
	// 0 3 7

	return 0;
}
