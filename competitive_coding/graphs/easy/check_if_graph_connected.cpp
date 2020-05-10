// https://www.geeksforgeeks.org/check-if-a-directed-graph-is-connected-or-not/
#include <iostream>
#include <vector>

using namespace std;

#define V 4
vector<int> adj[V];


// O (1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
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

int isGraphConnectedOptimised () {
	vector <bool> visited(V, false);

	DFSUtil (0, visited);
	for (int i = 0 ; i < V ;i++) {
		if(!visited[i]) {
			return 0;
		}	
	}

	return 1;
}

int main () {

	addEdge (0,1);
	addEdge (1,2);
	//addEdge (2,3);
	addEdge (0,2);

	if (isGraphConnectedOptimised()) {
		cout << "Graph is connected" << endl;
	}else {
		cout << "Graph is not connected " << endl;
	}
}