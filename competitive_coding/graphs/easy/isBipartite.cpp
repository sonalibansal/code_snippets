#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 6
vector<int> adj[V];


//O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
}

// O(V+E) 
bool isBipartiteUtil (int src, vector<int> &color) {

	
	int top, element;
	queue<int> q;
	color[src] = 0;
	q.push (src);

	while (!q.empty ()) {
		top = q.front ();
		q.pop ();

		if (find (adj[top].begin(), adj[top].end(), top) != adj[top].end()) {
			return false;
		}

		for (int i = 0 ; i < adj[top].size () ; i++) {
			element = adj[top][i];
			if (color[element] == -1) {
				color[element] = 1 - color[top];
				q.push (element);

			}else if (color[element] == color[top]){
				return false;
			 }
		}
	}

	return true;

}

bool isBipartite (int src) {
	vector<int> color (V+1, -1);

	for (int i = 1 ; i <= V ; i++) {
		if (color[i] == -1) {
			if (!isBipartiteUtil (i, color)) {
				return false;
			}
		}
	}
	return true;
}

int main () {

	addEdge (1,2);
	addEdge (2,3);
	addEdge (3,4);
	addEdge (4,5);
	addEdge (5,6);
	addEdge (6,1);

	cout << isBipartite (1) << endl;

	return 0;
}