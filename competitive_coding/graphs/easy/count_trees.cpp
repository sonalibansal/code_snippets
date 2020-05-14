//https://www.geeksforgeeks.org/count-number-trees-forest/
#include <iostream>
#include <vector>
using namespace std;

#define V 5

vector<int> adj[V];

//O(1)
void addEdge (int v, int w) {
	adj[v].push_back (w);
	adj[w].push_back (v);
}


//O(V+E)
void DFSUtil (int key , vector<bool> &visited) {

	visited[key] = true;

	for (int i = 0 ; i < adj[key].size () ; i++) {
		if (!visited[adj[key][i]]) {
			DFSUtil (adj[key][i], visited);
		}
	}

}

//O(V+E)
void countTrees () {
	vector<bool> visited (V, false);
	int c = 0;
	for (int i = 0 ; i < V ; i++) {
		if (!visited[i]) {
			c++;
			DFSUtil (i, visited);
		}
	}

	cout << "Number of trees in forest = " << c << endl;
}

int main () {

	addEdge (0,1);
	addEdge (0,2);
	addEdge (3,4);

	countTrees ();

	return 0;
}