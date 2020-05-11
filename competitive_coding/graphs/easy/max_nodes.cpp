//https://www.geeksforgeeks.org/maximum-number-of-nodes-which-can-be-reached-from-each-node-in-a-graph/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define V 7

vector<int> adj[V];
unordered_map<int, int> map;

void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}

// O(V+E) where V is the number of vertices and E is the number of Edges
void maxNodesUtil (int key, int c,  vector<bool> &visited) {
	visited[key] = true;
	map[c]++;
	for (int i = 0; i < adj[key].size() ; i++) {
		if(!visited[adj[key][i]]) {
			maxNodesUtil (adj[key][i], c , visited);
		}
	}
}

void maxNodes () {

	vector<bool> visited(V, false);
	int c = 1;

	// O(V+E)
	for (int i = 0 ; i < V ; i++) {
		if (!visited[i]) {
			maxNodesUtil (i, c, visited);
			c++;
		}
		
	}

	// O(V+E)
	int i, j;
	for (i = 1; i <= map.size() ; i++) {
		for (j = 0 ; j < map[i] ; j++) {
			cout << map[i] << " ";
		}	
	}
}

int main () {

	addEdge (0,1);
	addEdge (1,2);
	addEdge (2,3);
	addEdge (4,5);
	addEdge (5,6);
	addEdge (6,4);

	maxNodes ();

	return 0;
}

