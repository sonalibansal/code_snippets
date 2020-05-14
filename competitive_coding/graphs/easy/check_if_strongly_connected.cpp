//https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/
#include <iostream> 
#include <vector>

using namespace std;

#define V 5

vector<int> adj[V];
vector<int> trans[V];

// O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
}

// O(1)
void addTransEdge (int u , int v) {
	trans[u].push_back (v);
}

// O(V + E)
void transpose () {
	for (int i = 0 ; i < V ; i++) {
		for (int j = 0 ; j < adj[i].size (); j++) {
			addTransEdge (adj[i][j], i);
		}
	}
}

// O(V + E)
void DFSUtil (int key, vector<bool> &visited) {

	visited[key] = true;
	for (int i = 0 ; i < adj[key].size () ; i++) {
		if (!visited[adj[key][i]]) {
			DFSUtil (adj[key][i], visited);
		}
	}
}

// O(V + E)
void TransposeDFSUtil (int key, vector<bool> &visited) {

	visited[key] = true;
	for (int i = 0 ; i < trans[key].size () ; i++) {
		if (!visited[trans[key][i]]) {
			TransposeDFSUtil (trans[key][i], visited);
		}
	}
}

// O(V + E)
bool DFS (int src, bool transpose) {

	vector<bool> visited (V, false);

	if (! transpose) {
		DFSUtil (src, visited);
	} else {
		TransposeDFSUtil (src, visited);
	}
	
	for (int i = 0 ; i < V ; i++) {
		if (!visited[i]) {
			return false;
		}
	}

	return true;
}

// O(V + E)
bool kosaraju_algo (int src) {

	if (DFS (src, false)) {
		transpose ();

		if (DFS (src, true)) {
			return true;
		}
		 return false;

	 }

	 return false;
}


int main () {

	// addEdge (0,1);
	// addEdge (1,2);
	// addEdge (2,3);
	// addEdge (3,0);
	// addEdge (2,4);
	// addEdge (4,2);

	addEdge (0,1);
	addEdge (1,2);
	addEdge (2,3);
	addEdge (3,4);

	cout << "Strongly connected ";
	if (kosaraju_algo (0)) {
		cout << ": YES" << endl;
	} else {
		cout << ": NO " << endl;
	}

	return 0;
}