//https://www.geeksforgeeks.org/find-the-minimum-cost-to-reach-a-destination-where-every-station-is-connected-in-one-direction/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define V 4

vector<pair <int, int > > adj[V];
vector<int> dist (V, INT_MAX);

// O(1)
void addEdge (int u, int v, int cost) {
	adj[u].push_back (make_pair(v, cost));
}

// O(ELogV)
void djikstra (int src, int dest) {
	priority_queue<pair<int,int> > q;
	pair<int, int> top, element;
	vector<bool> visited (V, false);
	int key, cost;

	q.push (make_pair (0, src));
	dist[src] = 0;
	

	while (! q.empty ()) {
		top = q.top ();
		int u = top.second;
		q.pop ();

		if (!visited[u]) {

			dist[u] = -top.first;
			visited[u] = true;
			for (int i = 0 ; i < adj[u].size () ; i++) {
				element = adj[u][i];
				key = element.first;
				cost = element.second;
				if (!visited[key]) {
					q.push (make_pair (-(dist[u]+ cost), key));
				}
			}

		}
	}

	cout << "The minimum cost is " << dist[dest] << endl;
}


int main () {

	addEdge (0,1,15);
	addEdge (0,2,80);
	addEdge (0,3,90);
	addEdge (1,2,40);
	addEdge (1,3,50);
	addEdge (2,3,70);

	djikstra (0,3);

	return 0;
}