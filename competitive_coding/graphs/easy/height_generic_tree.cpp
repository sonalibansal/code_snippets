//https://www.geeksforgeeks.org/height-generic-tree-parent-array/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define V 8
vector<int> adj[V];

//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}

//O(V)
int buildTree (vector<int> &parent) {

	int rootIndex = -1;

	for (int i = 0 ; i < parent.size () ; i++) {
		if (parent[i] == -1) {
			rootIndex = i;
		} else {
			addEdge (i, parent[i]);
		}
	}
	return rootIndex;
}

//O(V+E)
int height (int rootIndex) {

	vector<int> visited(V ,false);
	queue<pair<int, int >> q;
	pair<int, int> top;
	q.push (rootIndex, 0);
	int height = 0;

	while (!q.empty ()) {
		top = q.top ();
		visited[top.first] = true;

		height = max (height, top.second);
		q.pop ();

		for (int i = 0 ; i < adj[top.first].size () ;i++) {
			if (!visited[adj[top.first][i]]) {
				q.push (adj[top.first][i], top.second+1);
			}
		}

	}

	return height;
}

int main () {

	vector<int> parent {-1,0,0,0,3,1,1,2};

	int rootIndex = buildTree (parent);

	cout << "Height of the generic tree " << height (rootIndex);

	return 0;

}