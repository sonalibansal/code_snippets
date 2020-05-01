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
void printList (vector<int> parent, vector<int> dist) {
	for (int i = 0; i < V; i++) {
		if (parent[i] != -1) {
			cout << parent[i] << "-" << i << " " << dist[i] << "\n";	
		}
	}
}

// O(V log V) where V is the total number of vertices and E is the number of edges. 
void prims (int src) {

	priority_queue<pair<int,int> > pq;
	vector<int> dist(V, INT_MAX);
	vector<bool> sptSet(V, false);
	vector<int> parent(V, 0);

	dist[src] = 0;
	sptSet[src] = true;
	parent[src] = -1;
	pq.push (make_pair (0, src));
	vector<pair <int, int> > ::iterator it;
	pair<int, int> element;


	while (!pq.empty()) {
		pair<int, int> top = pq.top ();
		int u = top.second;
		pq.pop ();
		if (-dist[u] == top.first) {
			sptSet[u] = true;


			for (it = adj[u].begin(); it != adj[u].end() ;it++) {
				element = *it;
				int key = element.first;
				int cost = element.second;

				if (!sptSet[key] && cost < dist[key]) {
					dist[key] = cost;
					parent[key] = u;
					pq.push (make_pair (-dist[key], key));
				}

			}
		}
		
	}

	cout << "Min spanning tree from the source \n";
	printList (parent,dist);
	
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
   
	prims(0);

	return 0;
}