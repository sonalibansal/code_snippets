#include <iostream>
#include <vector>
#include <utility> 
#include <climits>
#include <queue>
using namespace std;
 
#define V 9
vector< pair <int, int> > adj[V];

pair<int,int> p;

 // O (1)
void addEdge (int v, int w, int cost) {
	adj[v].push_back (make_pair (w, cost));
	adj[w].push_back (make_pair (v, cost));
}

// O(V) where V is the total number of vertices
void printList (vector<int> dist) {
	for (int i = 0; i < V; i++) {
		cout << dist[i] << " ";
	}
}

// O(E log V) where V is the total number of vertices and E is the number of edges. 
// In worst case, value of E = V^2
void djikstra (int src) {

	priority_queue<pair<int,int> > pq;
	vector<int> dist(V,INT_MAX);
	vector<bool> visited(V, false);

	dist[src] = 0;
	pq.push (make_pair (0, src));

	int i ;
	vector<pair <int, int> > ::iterator it;
	pair<int, int> element;

	while (!pq.empty()) {
		pair<int, int> top = pq.top ();
		int u = top.second;
		pq.pop ();

		if (!visited[u]) {
			visited[u] = true;
			dist[u] = - top.first;
			for (i = 0 ; i < adj[u].size () ;i++ ) {
				element = adj[u][i];
				int key = element.first;
				int cost = element.second;

				if (!visited[key]) {
					pq.push (make_pair (-(dist[u] + cost), key));
				}

			}
		}
		
	}

	cout << "Min distance of all nodes from the source \n";
	printList (dist);
	
}

int main()  {

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
   
	djikstra(0);  // Output : 0 4 12 19 21 11 9 8 14

	return 0;
}
