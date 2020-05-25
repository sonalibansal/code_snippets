//https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/
#include <iostream>
#include <vector>
using namespace std;

#define V 4
vector<int> adj[V];

int tc[V][V];

void addEdge (int u , int v) {
	adj[u].push_back (v);
}


void DFSUtil (int src, int dest) {

	tc[src][dest] = 1;

	for (int i = 0 ; i < adj[dest].size () ; i++) {
		if (!tc[src][adj[dest][i]]) {
			DFSUtil (src, adj[dest][i]);
		}
	}
}

void transitive () {

	for (int i = 0 ; i < V ; i++) {
		for (int j = 0 ; j < V ; j++) {
			tc[i][j] = 0;
		}
	}

	for (int i = 0 ; i < V ; i++) {
		DFSUtil (i, i);
	}

	for (int i = 0 ; i < V ; i++) {
		for (int j = 0 ; j < V ; j++) {
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}

}

int main () {

	addEdge (0,1);
	addEdge (1,2);
	addEdge (2,3);
	addEdge (0,2);
	addEdge (2,0);

	transitive ();
	return 0;
}