//https://www.geeksforgeeks.org/program-to-count-number-of-connected-components-in-an-undirected-graph/

#include <iostream>
#include <vector>

using namespace std;

#define V 4
vector<int> adj[V];


// O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}

// O(V) 
void DFSUtil (int src, vector<bool> &visited) {

	visited[src] = true;
	for (int i = 0; i < adj[src].size() ; i++) {
		if(!visited[adj[src][i]]) {
			DFSUtil (adj[src][i], visited);
		}
	}
}

int numbOfConnectedComponents () {
	vector <bool> visited(V, false);
	int ans = 0 ;

	for (int i = 0 ; i < V ; i++) {
		ans ++;
		DFSUtil (i, visited);
	}

	return ans - 1;
}

int main () {

	addEdge (1,5);
	addEdge (0,2);
	addEdge (2,4);

	cout << "Number of connected components " << numbOfConnectedComponents () << endl;
}