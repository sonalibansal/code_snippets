//https://www.geeksforgeeks.org/count-number-nodes-given-level-using-bfs/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define V 7
vector<int> adj[V];

void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


int BFS (int src, int l) {

	queue<int> q;
	int top;
	unordered_map <int, int > map;
	vector<int> level (V, -1);
	vector<bool> visited (V, false);
	level[src] = 0;
	q.push (src);

	while (!q.empty ()) {
		top = q.front ();
		visited[top] = true;
		q.pop ();

		for (int i = 0 ; i < adj[top].size () ; i++) {
			if (!visited[adj[top][i]]) {
				level[adj[top][i]] = level[top] +1;
				q.push (adj[top][i]);
			}
		}
	}

	int count = 0; 
	for (int i = 0 ; i < V ; i++) {
		if (level[i] == l) {
			count ++;
		}
	}

	return count;
}

int main () {

	addEdge (0,1);
	addEdge (0,2);
	addEdge (1,3);
	addEdge (1,4);
	addEdge (1,5);
	addEdge (2,6);

	int l = 2;

	cout << "number of nodes at level = " << l << " is " << BFS (0, l) << endl;
}

