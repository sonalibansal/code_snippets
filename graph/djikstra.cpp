#include <iostream>
#include <vector>
#include <utility> 
#include <climits>
using namespace std;
 
#define V 9
vector< pair <int, int> > adj[V];

 // O (1)
void addEdge (int v, int w, int cost) {
	adj[v].push_back (make_pair (w, cost));
	adj[w].push_back (make_pair (v, cost));
}

//O (V) where V is the total number of vertices
int minDistance (vector<int> dist, vector<bool> sptSet) {
	int min = INT_MAX, min_index = -1;

	for (int i = 0 ;i < V ;i++) {
		if(!sptSet[i] && dist[i] < min) {
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

//O (E) where E is the number of edges from node u. 
// In worst case it is O(V-1) where V is the total number of vertices
pair<int, int> findElement (int u, int key) {
    vector<pair <int, int> > ::iterator it;
    pair<int, int> item;
	for (it = adj[u].begin() ;it != adj[u].end(); it++) {
		item = *it;
		if (item.first == key) {
			return item;
		}
	}
	return item;
}

// O(V) where V is the total number of vertices
void printList (vector<int> dist) {
	for (int i = 0; i < V; i++) {
		cout << dist[i] << " ";
	}
}

// O(V^2) where V is the total number of vertices
void djikstra (int src) {
	vector<int> dist;

	vector<bool> sptSet;
	for (int i = 0; i < V; i++) {

		dist.push_back (INT_MAX);
		sptSet.push_back (false);
	}

	dist[src] = 0;

	for (int count = 0; count < V-1; count++) {
		int u = minDistance (dist, sptSet);
		sptSet[u] = true;

		for(int i = 0; i< V; i++) {	
			pair<int, int> element = findElement(u,i);
			if (element.first != 0 && element.second != 0) {
				int key = element.first;
				if (!sptSet[key] && ((dist[u] + element.second) < dist[key])) {
					dist[key] = dist[u] + element.second;
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
   
	djikstra(0);

	return 0;
}
