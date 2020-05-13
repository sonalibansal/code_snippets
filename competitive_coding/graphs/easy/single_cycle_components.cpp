//https://www.geeksforgeeks.org/number-of-simple-cyclic-components-in-an-undirected-graph/
#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
using namespace std;

#define V 15
vector<int> adj[V];
vector<int> component;

// O(1)
void addEdge (int u , int v) {
	adj[u].push_back (v);
	adj[v].push_back (u);
}


// O(V+E)
void DFSUtil (int key, vector<bool> &visited) {
 
	visited[key] = true;
	component.push_back (key);
	for (int i = 0 ; i < adj[key].size (); i++) {
		if (!visited[adj[key][i]]) {
			DFSUtil (adj[key][i], visited);
		}
	}	
}

// O(1)
int indegree (int u ) {
	return adj[u].size ();
}

// O(V+E)
void countSingleCyclicComponents () {

	vector<bool> visited(V+1, false);
	int count = 0, flag = 0;
	for (int i = 1 ; i <= V ; i++) {
		if (!visited[i]) {
			component.clear ();
			DFSUtil (i, visited);
			flag = 1;
			for (int j  = 0 ; j < component.size() ; j++) {
				if (indegree(component[j]) == 2) {
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				count ++;
			}
		}

	}

	cout << "number of single cyclic components = " << count << endl;

}

int main () {

	addEdge (1,5);
	addEdge (1,10);
	addEdge (5,10);

	addEdge (2,12);
	addEdge (2,15);
	addEdge (2,9);
	addEdge (12,15);
	addEdge (9,15);

	addEdge (13,8);

	addEdge (6,11);
	addEdge (6,14);
	addEdge (11,7);
	addEdge (7,3);
	addEdge (3,14);

	countSingleCyclicComponents ();

}