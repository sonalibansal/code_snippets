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

// O(V^2) where V is the total number of vertices
void djikstra (int src) {

	priority_queue<pair<int,int> > pq;
	vector<int> dist(V,INT_MAX);

	pq.push(make_pair (-2, src));
	pq.push(make_pair (-1, src));

	dist[src] = 0;
	vector<pair <int, int> > ::iterator it;
	pair<int, int> element;

	while (!pq.empty()) {
		int u = pq.top ().second;
		pq.pop ();


		for (it = adj[u].begin(); it != adj[u].end() ;it++) {
			element = *it;
			int key = element.first;
			int cost = element.second;

			if (dist[u] + cost < dist[key]) {
				dist[key] = dist[u] + cost;
				cout << "key" << key << "dist[key]" << dist[key];
				//pq.push (make_pair (key, dist[key]));
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
   
	djikstra(0);

	return 0;
}
