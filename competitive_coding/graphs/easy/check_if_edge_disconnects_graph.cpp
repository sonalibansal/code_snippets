// https://www.geeksforgeeks.org/check-removing-given-edge-disconnects-given-graph/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define V 4

vector<int> adj[V];

// O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


// O (V+E)
bool ifConnected (int src) {

	queue<int> q;

	vector<bool> visited (V, false);

	q.push (src);
	int top;

	while (! q.empty ()) {
		top = q.front ();
		q.pop ();

		visited[top] = true;

		for (int i = 0; i < adj[top].size () ; i++) {
			if (!visited[adj[top][i]]) {
				q.push (adj[top][i]);
			}
		}
	}

	for (int i = 0 ; i < V ; i ++) {
		if (!visited[i]) {
			return false;
		}
	}

	return true;
}


// O (V + E)
bool isBridge (int x, int y) {

	adj[x].erase(std::remove(adj[x].begin(), adj[x].end(), y), adj[x].end());
	adj[y].erase(std::remove(adj[y].begin(), adj[y].end(), x), adj[y].end());

	return !ifConnected (0);

}

int main () {

	addEdge (0,1);
	addEdge (1,2);
	addEdge (2,3);

	if (isBridge(1, 2) ) {
		cout << " YES " << endl;
	} else {
		cout << " NO " << endl;
	}

	return 0;
}