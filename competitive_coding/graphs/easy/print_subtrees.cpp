#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 10
vector<int> adj[V];
vector<bool> visited(V, false);
vector<int> start (V, -1);
vector <int> endPosition (V, -1);
vector<int> dfs_order;


//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
}

//O(V+E)
void dfsUtil (int src, int &b) {

	visited[src] = true;
	b++;
	start [src] = b;
	dfs_order.push_back (src);


	for (int i = 0 ; i < adj[src].size () ; i++) {
		if (!visited[adj[src][i]]) {
			dfsUtil (adj[src][i], b);
		}
	}

	endPosition[src] = b;
}

void printSubtree () {
	for (int i = 0 ; i < V ; i++) {
		if (start[i] != endPosition[i]) {
			cout << "subtree of the node " << i << " : ";

			for (int j = start[i]+1 ; j <= endPosition[i] ; j++) {
				cout << dfs_order[j-1] << " ";
			}
			cout << endl;
		}
	}
}

void dfs () {

	int count = 0;
	
	dfsUtil (0, count);

	printSubtree ();
}

int main () {

	addEdge (0,1);
	addEdge (0,3);
	addEdge (0,2);
	addEdge (1,4);
	addEdge (1,5);
	addEdge (4,7);
	addEdge (4,8);
	addEdge (2,6);
	addEdge (6,9);

	dfs ();

	return 0;
}