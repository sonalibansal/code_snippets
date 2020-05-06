#include <iostream>
#include <vector>

using namespace std;

#define V 7

vector<int> adj[V];
vector<int> ans(V, 0);

void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}

// O(V) where V is the number of vertices 
void maxNodesUtil (int src, int dest,  vector<bool> &visited) {
	visited[dest] = true;
	ans[src] ++;

	for (int i = 0; i < adj[dest].size() ; i++) {
		if(!visited[adj[dest][i]]) {
			maxNodesUtil (src, adj[dest][i],visited);
		}
	}
}

void maxNodes () {

	vector<bool> visited(V, false);

	for (int i = 0 ; i < V ; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vector<bool> visitedChild(V, false);
			maxNodesUtil (i, i, visitedChild);
		}
		
	}

	for (int i = 0; i < V ;i++) {
		cout << ans[i] << " ";
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

