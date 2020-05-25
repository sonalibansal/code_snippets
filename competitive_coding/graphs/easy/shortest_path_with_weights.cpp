//https://www.geeksforgeeks.org/shortest-path-weighted-graph-weight-edge-1-2/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V = 4;

vector<int> adj[8];
vector<int> pred(V , -1);
vector<int> dist(V, INT_MAX);

// O (1)
void addEdge (int u, int v, int cost) {

	if (cost == 2) {
		adj[u].push_back (u+V);
		adj[u+V].push_back (v);
	} else {
		adj[u].push_back (v);
	}
	
}


// O(V+E)
bool shortestPathExists (int src, int dest) {

	queue<int> q;
	vector<bool> visited (2*V, false);
	int top, key;
	dist[src] = 0;
	visited[src] = true;


	q.push (src);

	while (! q.empty ()) {
		top = q.front ();
		q.pop ();
		for (int i = 0 ; i < adj[top].size () ; i++) {
			key = adj[top][i];
			if (!visited[key]) {
				pred[key] = top;
				dist[key] = dist[top] + 1;
				q.push (key);

				if (key == dest) {
					return true;
				}
			}
		}
	}

	return false;
}


// O(V)
void printCompletePath (vector<int> &parent, int src) {
	if (parent[src] == -1) {
		return;
	}

	printCompletePath (parent, parent[src]);

	if (src < V) {
		cout << src << " ";
	}
}

// O(V+Es)
void printPath (int src, int dest) {
	if (!shortestPathExists (src, dest)) {
		cout << "shortest path does not exists between " << src << "and " << dest << endl;

	} else {
		cout << "shortest distance between " << src << " and " << dest << " :" << dist[dest] << endl;
		cout << "Shortet path : " << src  << " ";
		printCompletePath (pred, dest);
		cout << endl;
	}
}

int main () {

	addEdge (0,1,2);
	addEdge (0,2,2);
	addEdge (2,0,1);
	addEdge (2,3,2);
	addEdge (1,2,1);
	addEdge (1,3,1);
	addEdge (3,3,2);

	printPath (0,3);
	return 0;




}