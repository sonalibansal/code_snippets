//https://www.geeksforgeeks.org/level-node-tree-source-node-using-bfs/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 8
vector<int> adj[V];

// O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


void printLevelOfEachNode (int src) {

	queue<pair<int, int> > q;
	vector<bool> visited (V, false);
	vector<int> result(V, -1);
	pair<int, int> top;
	q.push (make_pair (src, 0));

	while (!q.empty()) {
		top = q.front ();
		q.pop ();
		visited[top.first] = true;
		result[top.first] = top.second;

		for (int i = 0 ; i < adj[top.first].size () ; i++) {
			if (!visited[adj[top.first][i]]) {
				q.push (make_pair (adj[top.first][i], top.second+1));
			}

		}

	}

	for (int i = 0 ; i < result.size () ; i++) {
		cout << i << " " << result[i] << endl;
	}

}

int main () {

	addEdge (0,1);
	addEdge (0,2);
	addEdge (2,6);
	addEdge (6,7);
	addEdge (1,3);
	addEdge (1,4);
	addEdge (1,5);

	printLevelOfEachNode (0);

	return 0;


}