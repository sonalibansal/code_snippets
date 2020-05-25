//https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define V 9
vector<pair <int, int> > adj[V];

void addEdge (int v, int w, int cost) {
	adj[v].push_back (make_pair (w, cost));
	adj[w].push_back (make_pair (v, cost));
}


// O(V)
void printPath(vector<int> &parent, int j) {
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    cout << j << " ";
}

// O(V^2)
void printAllPaths (vector<int> &parent, int src, vector<int> &dist) {
	for (int i = 1 ; i < V ; i++) {
		cout << src << "-" << i << " " << dist[i] << "\t" << src << " ";
		printPath (parent, i) ;
		cout << endl;
	}
 }

void djikstra (int src) {
	priority_queue<pair<int,int> > q;
	pair<int, int> top, element;
	vector<bool> visited (V, false);
	vector<int> dist(V,INT_MAX);
	vector<int> pred (V , -1);

	dist[src] = 0;
	q.push (make_pair (0, src));

	while (! q.empty ()) {

		top = q.top ();
		int u = top.second;
		q.pop ();

		if (! visited[u]) {
			visited[u] = true;
			dist[u] = - top.first;

			for (int i = 0 ; i < adj[u].size () ; i++) {
				element = adj[u][i];
				int key = element.first;
				int cost = element.second;

				if (!visited[key]) {
					pred[key] = u;
					q.push (make_pair (-(dist[u] + cost), key));
				}
			}

		}

	}

	printAllPaths (pred, src, dist);

}

int main () {
	addEdge (0,1,4);
	addEdge (0,7,8);
	addEdge (1,2,8);
	addEdge (1,7,11);
	addEdge (7,8,7);
	addEdge (7,6,1);
	addEdge (2,8,2);
	addEdge (2,5,4);
	addEdge (2,3,7);
	addEdge (6,8,6);
	addEdge (6,5,2);
	addEdge (5,3,14);
	addEdge (5,4,10);
	addEdge (4,3,9);

	djikstra (0);

	/**
	0-1 4	0 1 
	0-2 12	0 1 7 6 5 2 
	0-3 19	0 1 7 6 5 2 3 
	0-4 21	0 1 7 6 5 2 3 4 
	0-5 11	0 1 7 6 5 
	0-6 9	0 1 7 6 
	0-7 8	0 1 7 
	0-8 14	0 1 7 6 5 2 8 
	**/

	return 0;
}