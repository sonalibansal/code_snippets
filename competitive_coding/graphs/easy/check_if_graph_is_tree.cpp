//https://www.geeksforgeeks.org/check-given-graph-tree/
#include <iostream>
#include <vector>
using namespace std;

#define V 5
vector<int> adj[V];

void addEdge (int u ,int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


// O(V+E)
bool isCyclicUtil (int key, int parent, vector<bool> &visited) {

	visited[key] = true;

	for (int i = 0 ; i < adj[key].size () ; i++) {
		if (!visited[adj[key][i]]) {
			if (isCyclicUtil (adj[key][i], key, visited)) {
				return true;
			}
		} else if (adj[key][i] != parent) {
			return true;
		}
	}
	return false;
}


// O(V+E)
bool check_if_tree (int src) {

	vector<bool> visited(V, false);

	if (isCyclicUtil (src, -1, visited)) {
		return false;
	}

	for (int i = 0 ; i < V; i++) {
		if (!visited[i]) {
			return false;
		}
	}

	return true;
}

int main () {

	addEdge (0,1);
	addEdge (0,2);
	addEdge (0,3);
	addEdge (3,4);
	addEdge (1,2);

	if (check_if_tree (0)) {

		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	// NO 


}