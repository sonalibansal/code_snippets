//https://www.geeksforgeeks.org/maximum-edges-can-added-dag-remains-dag/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 6

vector<int> adj[V];

void addEdge (int u , int v) {
	adj[u].push_back (v);
}


// O(V+E)
vector<int> topoSort () {

	queue<int> q;
	vector<int> result;
	vector<int> indegree (V,0);

	int i, j, top;

	for (i = 0 ; i < V ; i++) {
		for (j = 0 ; j < adj[i].size () ; j++) {
			indegree[adj[i][j]] ++;
		}
	}

	for (i = 0 ; i < V ; i++) {
		if (indegree[i] == 0) {
			q.push (i);
		}
	}

	while (!q.empty ()) {

		top = q.front ();
		q.pop ();
		result.push_back (top);

		for (i = 0 ; i < adj[top].size(); i++) {
			indegree[adj[top][i]]--;

			if (indegree[adj[top][i]] == 0) {
				q.push (adj[top][i]);
			}
		}

	}

	if (result.size () != V) {
		cout << "topo sort of the graph is not possible" << result.size () << endl;
	}

	return result;
}

// O (V+E)
void maxEdges () {

	vector<int> topo = topoSort();
	vector<bool> visited (V, false);
	int t, i;

	// O (V+E)
	for (i = 0 ; i < topo.size () ; i++) {

		t = topo[i];

		for (int j = 0 ; j < adj[t].size () ; j++) {
			visited[adj[t][j]] = true;
		}

		for (int j = i+1 ; j < topo.size () ; j++) {
			if (!visited[topo[j]]) {
				cout << t << "-" << topo[j] << endl;
			}
		}

		for (int j = 0 ; j < V ; j++) {
			visited[j] = false;
		}
	}

}

int main () {

	addEdge (5,2);
	addEdge (5,0);
	addEdge (4,0);
	addEdge (4,1);
	addEdge (2,3);
	addEdge (3,1);

	maxEdges ();

	return 0;
}